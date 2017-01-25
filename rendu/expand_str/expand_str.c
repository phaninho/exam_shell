#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putspace()
{
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar(' ');
}
int		is_alpha(char c)
{
	if (c >= '!' && c <= '~')
		return (0);
	return (1);
}

void	check_str(char *str)
{
	int	i = 0;
	if (is_alpha(str[0]))
	{
		while (str && str[i] && is_alpha(str[i]))
			i++;
		if (!is_alpha(str[i]))
		{
			while (str && str[i] && !is_alpha(str[i]))
			{
				ft_putchar(str[i]);
				i++;
			}
//			ft_putspace();
		}
	}
	else if (!is_alpha(str[0]))
	{
		while (str && str[i] && !is_alpha(str[i]))
		{
			ft_putchar(str[i]);
			i++;
		}
		ft_putspace();
	}
	while (str && str[i])
	{
		while (str && str[i] && is_alpha(str[i]))
			i++;
		if (is_alpha(str[i - 1]) && !is_alpha(str[i]))
			ft_putspace();
		while (str && str[i] && !is_alpha(str[i]))
			ft_putchar(str[i++]);
		if (str[i] && is_alpha(str[i - 1]))
			ft_putspace();
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	check_str(av[1]);
	return (0);
}
