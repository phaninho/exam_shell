#include <stdio.h>
#include <stdlib.h>

int		pgcd(int a, int b)
{
	int		rsl;
	int		mult;

	rsl = 0;
	mult = 1;
	while (mult <= (a < b ? a : b))
	{
		if (a % mult == 0 && b % mult == 0)
			rsl = mult;
		mult++;
	}
	return (rsl);
}

int		main(int ac, char **av)
{
	int		nb;
	int		a;
	int		b;

	if (ac != 3)
		printf("\n");
	else
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		nb = pgcd(a, b);
		printf("%d\n", nb);
	}
	return (0);
}
