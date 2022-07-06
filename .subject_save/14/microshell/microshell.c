#include <stdio.h> //delete
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include <sys/types.h> //for linux
#include <sys/wait.h> //for linux

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5

typedef struct s_base
{
    char **argv;
    int size;
	int type;
	int fd[2];
	struct s_base *prev;
    struct s_base *next;
} t_base;

/*
**====================================
**============Part utils==============
**====================================
*/

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	char *new;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

/*
**====================================
**============Part error==============
**====================================
*/

void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}

/*
**====================================
**============Part parsing============
**====================================
*/

void ft_lstadd_back(t_base **ptr, t_base *new)
{
    t_base *temp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		temp = *ptr;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

int size_argv(char **argv)
{
    int i = 0;
    while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
        i++;
    return (i);
}

int check_end(char *av)
{
    if (!av)
        return (TYPE_END);
    if (strcmp(av, "|") == 0)
        return (TYPE_PIPE);
    if (strcmp(av, ";") == 0)
        return (TYPE_BREAK);
    return (0);
}

int parser_argv(t_base **ptr, char **av)
{
    int size = size_argv(av);
    t_base *new;

    if (!(new = (t_base *)malloc(sizeof(t_base))))
        exit_fatal();
    if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1))))
        exit_fatal();
    new->size = size;
	new->next = NULL;
	new->prev = NULL;
    new->argv[size] = NULL;
    while (--size >= 0)
        new->argv[size] = ft_strdup(av[size]);
    new->type = check_end(av[new->size]);
    ft_lstadd_back(ptr, new);
    return (new->size);
}

/*
**====================================
**============Part execve=============
**====================================
*/

void exec_cmd(t_base *temp, char **env)
{
	pid_t pid;
	int status;
	int pipe_open;

	pipe_open = 0;
	if (temp->type == TYPE_PIPE || (temp->prev && temp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(temp->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0) //child
	{
		if (temp->type == TYPE_PIPE && dup2(temp->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (temp->prev && temp->prev->type == TYPE_PIPE && dup2(temp->prev->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(temp->argv[0], temp->argv, env)) < 0)
			exit_execve(temp->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else //parent
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(temp->fd[STDOUT]);
			if (!temp->next || temp->type == TYPE_BREAK)
				close(temp->fd[STDIN]);
		}
		if (temp->prev && temp->prev->type == TYPE_PIPE)
			close(temp->prev->fd[STDIN]);
	}
}

void exec_cmds(t_base *ptr, char **env)
{
	t_base *temp;

	temp = ptr;
	while (temp)
	{
		if (strcmp("cd", temp->argv[0]) == 0)
		{
			if (temp->size < 2)
				exit_cd_1();
			else if (chdir(temp->argv[1]))
				exit_cd_2(temp->argv[1]);
		}
		else
			exec_cmd(temp, env);
		temp = temp->next;
	}
}

/*
**====================================
**============Part main===============
**====================================
*/

void free_all(t_base *ptr)
{
	t_base *temp;
	int i;

	while (ptr)
	{
		temp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->argv[i++]);
		free(ptr->argv);
		free(ptr);
		ptr = temp;
	}
	ptr = NULL;
}

int main(int ac, char **av, char **env)
{
	t_base *ptr = NULL;
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
    	{
            if (strcmp(av[i], ";") == 0)
            {
                i++;
                continue ;
            }
    	    i += parser_argv(&ptr, &av[i]);
    	    if (!av[i])
    	        break;
    	    else
    	        i++;
    	}
	/*while (ptr)
	{
		
		printf("=================\n");
		for (i = 0; i < ptr->size; i++)
			printf("%s\n", ptr->argv[i]);
		printf("TYPE: %d\n", ptr->type);
		printf("SIZE: %d\n", ptr->size);
		printf("=================\n");
		ptr = ptr->next;
	}
	(void)**env;
	printf("END\n");*/
		if (ptr)
			exec_cmds(ptr, env);
		free_all(ptr);
	}
	return (0);
}