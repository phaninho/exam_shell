#include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int		div;

	while (1)
	{
		if (nb == 0 || nb == 1)
		{
			nb == 0 ? printf("0") : printf("1");
			break;
		}
		div = 2;
		while (div <= nb)
		{
			if (nb % div == 0)
			{
				printf("%d",div);
				nb /= div;
				break;
			}
			div++;
		}
		if (nb == 1)
			break;
		else
			printf("*");
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	if (ac != 2 || atoi(av[1]) < 0)
	{
		printf("\n");
		return (0);
	}
	fprime(atoi(av[1]));
	return (0);
}
