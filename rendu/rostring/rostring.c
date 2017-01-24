#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_alpha(char c)
{
	if ((c != ' ' || c != '\t'))
		return (0);
	return (1);
}

char	*alloc_str(int len)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	str[len] = '\0';
	return (str);
}

void	rot_string(char *str)
{
	int		i = 0;
	int		len;
	char	*last;

	while (str && str[i])
	{
		if (!is_alpha(str[0]))
		{
			while (!is_alpha(str[i]))
				i++;
			str = alloc_str(i);
			len = i;
			i = 0;
			last[i++] = ' ';
			while (i < len)
				last[i] = str[i - 1];
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	rot_string(av[1]);
	return (0);
}
