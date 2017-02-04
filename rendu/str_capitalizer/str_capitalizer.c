#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	to_upper(char c)
{
	return ((c - 'a') + 'A');
}

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		is_capital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	capitalize(char *str)
{
	int		i = 0;
	while (str && str[i])
	{
		if (i == 0 && is_alpha(str[i]) && !is_capital(str[i]))
			ft_putchar(to_upper(str[i]));
		else if (i > 0 && is_space(str[i - 1]) && is_alpha(str[i]) && !is_capital(str[i]))
			ft_putchar(to_upper(str[i]));
		else if (is_capital(str[i]))
			ft_putchar((str[i] - 'A' + 'a'));
		else
			ft_putchar(str[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i = 1;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	while (av[i])
	{
		capitalize(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
