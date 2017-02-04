#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_double(char c, char * s2)
{
	int		i = 0;
	while (s2 && s2[i])
	{
		if (s2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_str(char *str, char c, int len)
{
	int	i = 0;

	while (i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *s1, char *s2)
{
	int		i = 0;

	while (s1 && s1[i])
	{
		if (!check_str(s1, s1[i], i))
			if (check_double(s1[i], s2))
				ft_putchar(s1[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		write (1, "\n", 1);
		return (1);
	}
	inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
