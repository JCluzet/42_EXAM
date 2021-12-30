# include <unistd.h>
# include <stdlib.h>

typedef struct	s_str
{
	char			*content;
	struct s_str	*next;
}				t_str;

static int
	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char
	*ft_strdup(char const *str)
{
	char	*cpy;
	int		i;

	if (!str)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

static int
	ft_strchr(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

static t_str
	*str_add(t_str **str, char *content)
{
	t_str	*new;
	t_str	*tmp;

	if (!content)
		return (NULL);
	if (!(new = (t_str*)malloc(sizeof(*new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!*str)
		*str = new;
	else
	{
		tmp = *str;
		while ((*str)->next)
			*str = (*str)->next;
		(*str)->next = new;
		*str = tmp;
	}
	return (new);
}

static int
	str_strchr(t_str *str, char c)
{
	while (str)
	{
		if (ft_strchr(str->content, c))
			return (1);
		str = str->next;
	}
	return (0);
}

static int
	str_length(t_str *str)
{
	int	total;
	int	i;

	total = 0;
	while (str)
	{
		i = 0;
		while (str->content[i] && str->content[i] != '\n')
			i++;
		total += i;
		if (str->content[i] == '\n')
			return (total);
		str = str->next;
	}
	return (total);
}

static int
	str_write(t_str **str, char **line)
{
	char	*ltmp;
	t_str	*tmp;
	int		length;
	int		i, j;

	length = str_length(*str);
	if (!(ltmp = (char*)malloc(sizeof(*str) * (length + 1))))
		return (0);
	ltmp[length] = 0;
	*line = ltmp;
	j = 0;
	while (*str)
	{
		i = 0;
		while ((*str)->content[i] && (*str)->content[i] != '\n')
			(*line)[j++] = (*str)->content[i++];
		(*line)[j] = 0;
		if ((*str)->content[i++] == '\n')
		{
			j = 0;
			while ((*str)->content[i])
				(*str)->content[j++] = (*str)->content[i++];
			(*str)->content[j] = 0;
			return (1);
		}
		else
		{
			tmp = (*str)->next;
			free((*str)->content);
			free(*str);
			*str = tmp;
		}
	}
	return (1);
}

static int
	str_clear(t_str **str)
{
	t_str	*next;

	while (*str)
	{
		next = (*str)->next;
		free((*str)->content);
		free(*str);
		*str = next;
	}
	return (0);
}

static int
	read_file(t_str **str)
{
	char	buffer[129];
	int		r;
	int		total;

	total = 0;
	while ((r = read(0, buffer, 128)) > 0)
	{
		buffer[r] = 0;
		if (!str_add(str, ft_strdup(buffer)))
			return (-1);
		if (ft_strchr(buffer, '\n'))
			return (1);
	}
	return (total > 0);
}

int
	get_next_line(char **line)
{
	static t_str	*buffer = NULL;
	int				read_ret;
	
	read_ret = 1;
	if (!buffer || !str_strchr(buffer, '\n'))
		read_ret = read_file(&buffer);
	if (read_ret < 0)
		return (str_clear(&buffer) | -1);
	if (!str_write(&buffer, line))
		return (str_clear(&buffer) | -1);
	read_ret = 1;
	if (!buffer || !str_strchr(buffer, '\n'))
		read_ret = read_file(&buffer);
	if (read_ret < 0)
		return (str_clear(&buffer) | -1);
	return (!!buffer);
}

