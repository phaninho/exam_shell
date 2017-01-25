#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i = 0;
	int		nb = 0;

	while (str && str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

int		is_prime(int nb)
{
	int		mod;

	mod = nb - 1;
	while (mod > 1)
	{
		if (nb % mod == 0)
			return (0);
		mod--;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	add_prime(char *str)
{
	int		nb;
	int		rsl = 0;

	nb = ft_atoi(str);
	while (nb > 1)
	{
		if (is_prime(nb))
			rsl = rsl + nb;
		nb--;
	}
	ft_putnbr(rsl);
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (1);
	}
	if (av[1][0] == '-')
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (1);
	}
	add_prime(av[1]);
	return (0);
}
