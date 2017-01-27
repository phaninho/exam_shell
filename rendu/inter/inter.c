#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_str(char c, char *str)
{
	int		i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		check_double(char c, char *str, int len)
{
	int		i = 0;
	while (str && str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(char *str, char *str2)
{
	int	i = 0;

	while (str && str[i])
	{
		if (!check_double(str[i], str, i))
			if (check_str(str[i], str2))
				ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
