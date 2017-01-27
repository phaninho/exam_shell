#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int		i = 0;
	int		rsl = 0;

	while (str && str[i])
	{
		rsl = rsl * 10 + str[i] - '0';
		i++;
	}
	return (rsl);
}

void 	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	fprime(int nbr)
{
	int		div;

	while (1)
	{
		div = 2;
		while (div <= nbr)
		{
			if (nbr % div == 0)
			{
				ft_putnbr(div);
				nbr /= div;
				break;
			}
			div++;
		}
		if (nbr == 1)
			break;
		else
			ft_putchar('*');
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	int	nbr;

	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	nbr = ft_atoi(av[1]);
	if (nbr == 0)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	if (nbr == 1)
	{
		ft_putchar('1');
		ft_putchar('\n');
		return (0);
	}
	fprime(nbr);
	return (0);
}
