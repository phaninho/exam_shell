#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		mot;

	i = 1;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (av[i])
	{
		mot = 0;
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < 'a' || av[i][j] > 'z') && ((av[i][j] < 'A' || av[i][j] > 'Z')))
			{
				ft_putchar(av[i][j++]);
				mot++;
			}
			else if (av[i][j] && av[i][j] >= 'A' && av[i][j] <= 'Z' && !mot)
			{
				ft_putchar(av[i][j]);
				j++;
				mot++;
			}
			else if (av[i][j] && (av[i][j] >= 'a' && av[i][j] <= 'z') && !mot)
			{
				ft_putchar(av[i][j] - 32);
				j++;
				mot++;
			}
			else if (av[i][j] && av[i][j] >= 'A' && av[i][j] <= 'Z' && mot)
			{
				ft_putchar(av[i][j] + 32);
				j++;
			}
			else if (av[i][j] && mot)
			{
				ft_putchar(av[i][j]);
				j++;
			}
			while (av[i][j] && (av[i][j] == ' ' || av[i][j] == '\t'))
			{
				ft_putchar(av[i][j]);
				j++;
				mot = 0;
			}
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
