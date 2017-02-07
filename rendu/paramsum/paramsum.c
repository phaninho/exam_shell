#include <unistd.h>

void	ft_putchar(char x)
{
	write(1, &x, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int		main(int ac, char **av)
{
	(void)av;
	if (ac < 2)
		write(1, "0", 1);
	else
		ft_putnbr(ac - 1);
	write (1, "\n", 1);
	return (0);
}
