#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define MIN(a, b)	((a < b) ? a : b)
#define ABS(x) 		((x < 0) ? -x : x)

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
	*ft_substr(char const *str, int start, int length)
{
	int		i;
	char	*cpy;
	int		str_length;

	str_length = ft_strlen(str);
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (str_length + 1))))
		return (NULL);
	i = 0;
	while (start + i < str_length && i < length)
	{
		cpy[i] = str[start + i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

static int
	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int
	ft_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

static t_str
	*str_add(t_str **str, char *content)
{
	t_str	*tmp;
	t_str	*new;

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
	str_write(t_str *str)
{
	int	total;
	int	length;

	total = 0;
	while (str)
	{
		length = ft_strlen(str->content);
		total += length;
		if (length > 0)
			write(1, str->content, length);
		str = str->next;
	}
	return (total);
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
	parse_flags(char const *flags, int *width, int *precision)
{
	int	i;
	int	state;
	int	tmp;
	
	*precision = -1;
	*width = -1;
	state = 0;
	i = 0;
	while (flags[i])
	{
		if (flags[i] == '.')
		{
			*precision = 0;
			state = 1;
			i++;
		}
		else if (ft_isdigit(flags[i]))
		{
			tmp = 0;
			while (ft_isdigit(flags[i]))
				tmp = (tmp * 10) + (flags[i++] - '0');
			if (state)
				*precision = tmp;
			else
				*width = tmp;
			state = 0;
		}
		else
			return (0);
	}
	return (1);
}

static char
	*malloc_decimal(int length, int precision)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		if (precision >= 0 && length - i <= precision)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	str[i] = 0;
	return (str);
}

static char
	*format_signed(int width, int precision, int val)
{
	char	*str;
	int		tmp;
	long	ltmp;
	int		i;
	int		length;
	int		nbr_length;

	ltmp = val;
	if (ltmp > 2147483647)
		val = (-2147483648 + (ltmp - 2147483647));
	else if (ltmp < -2147483648)
		val = (2147483647 - (-2147483648 - ltmp));
	nbr_length = 1;
	tmp = val;
	while (tmp > 9 || tmp < -9)
	{
		tmp /= 10;
		nbr_length++;
	}
	length = nbr_length + (val < 0);
	if (width > nbr_length)
		length = width;
	if (precision > length)
		length = precision;
	if (!(str = malloc_decimal(length, precision)))
		return (NULL);
	if (precision == 0 && val == 0)
		str[length - 1] = (width == length) ? ' ' : 0;
	else if (val == 0)
		str[length - 1] = '0';
	tmp = val;
	i = length - 1;
	while (tmp != 0)
	{
		ltmp = tmp;
		ltmp = ABS(ltmp);
		str[i--] = "0123456789"[ltmp % 10];
		tmp /= 10;
	}
	if (val < 0)
		str[i] = '-';
	return (str);
}

static char
	*format_hex(int width, int precision, unsigned int val)
{
	unsigned int	tmp;
	int				nbr_length;
	int				length;
	char			*str;
	int				i;

	nbr_length = 1;
	tmp = val;
	while (tmp > 15)
	{
		nbr_length++;
		tmp /= 16;
	}
	length = nbr_length;
	if (width > nbr_length)
		length = width;
	if (precision > length)
		length = precision;
	if (!(str = malloc_decimal(length, precision)))
		return (NULL);
	if (precision == 0 && val == 0)
		str[length - 1] = (width == length) ? ' ' : 0;
	else if (val == 0)
		str[length - 1] = '0';
	i = length - 1;
	tmp = val;
	while (tmp != 0)
	{
		str[i--] = "0123456789abcdef"[tmp % 16];
		tmp /= 16;
	}
	return (str);
}

static char
	*format_str(int width, int precision, char *str)
{
	char	*cpy;
	int		str_length;
	int		length;
	int		i;
	int		j;
	int		limit;

	if (!str)
		str = "(null)";
	str_length = ft_strlen(str);
	length = str_length;
	if (width > str_length || (precision >= 0 && width > precision))
		length = width;
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (length + 1))))
		return (NULL);
	i = 0;
	while (i < length)
		cpy[i++] = ' ';
	cpy[i] = 0;
	if (width > 0 && (precision == 0 || str_length == 0))
	{
		cpy[width] = 0;
		return (cpy);
	}
	else if (precision == 0)
	{
		cpy[0] = 0;
		return (cpy);
	}
	if (precision > 0)
		limit = MIN(str_length, precision);
	else
		limit = str_length;
	j = 0;
	if (width == length)
		i = length - limit;
	else
		i = 0;
	while (j < limit)
		cpy[i++] = str[j++];
	cpy[i] = 0;
	return (cpy);
}

static char
	*format_missing(char const *flags, char format)
{
	char	*str;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(flags) + 1 + 1;
	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	i = 0;
	str[i++] = '%';
	j = 0;
	while (flags[j])
		str[i++] = flags[j++];
	str[i++] = format;
	str[i] = 0;
	return (str);
}

static int
	do_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}

static int
	add_format(t_str **str, char *flags, char d, va_list *args)
{
	char	*mat;
	int		width;
	int		precision;
	int		fla;

	if (!flags)
		return (0);
	fla = parse_flags(flags, &width, &precision);
	if (!fla)
		return (do_free(flags));
	mat = NULL;
	if (d == 'd')
		mat = format_signed(width, precision, va_arg(*args, int));
	else if (d == 'x')
		mat = format_hex(width, precision, va_arg(*args, unsigned int));
	else if (d == 's')
		mat = format_str(width, precision, va_arg(*args, char*));
	else
		mat = format_missing(flags, d);
	free(flags);
	if (!mat)
		return (0);
	if (!str_add(str, mat))
		return (0);
	return (1);
}

static int
	clear_all(t_str **str, va_list *args)
{
	str_clear(str);
	va_end(*args);
	return (0);
}

int
	ft_printf(char const *format, ...)
{
	t_str	*str;
	int		i;
	int		start;
	int		length;
	va_list	args;


	str = NULL;
	if (!format)
		return (0);
	va_start(args, format);
	length = ft_strlen(format);
	i = 0;
	while (i < length)
	{
		start = i;
		while (i < length && format[i] != '%')
			i++;
		if (i - start > 0 && !str_add(&str, ft_substr(format, start, i - start)))
			return (clear_all(&str, &args));
		if (format[i] == '%' && (start = ++i) && i < length)
		{
			while (ft_in_set(format[i], ".0123456789"))
				i++;
			if (!add_format(&str, ft_substr(format, start, i - start), format[i], &args))
				return (clear_all(&str, &args));
			i++;
		}
	}
	i = str_write(str);
	clear_all(&str, &args);
	return (i);
}
