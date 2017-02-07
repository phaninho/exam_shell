void		sort_int_tab(int *tab, unsigned int size)
{
	unsigned int		i = 1;
	unsigned int		j;
	int		nb;

	while (i <= size)
	{
		j = 0;
		while (j <= i)
		{
			if (tab[j] >= tab[i])
			{
				nb = tab[i];
				tab[i] = tab[j];
				tab[j] = nb;
			}
			j++;
		}
		i++;
	}
}

/*#include<stdio.h>
#include<stdlib.h>
int	main(int ac, char **av)
{
	int *tab;
	int i = 1;
	tab = (int *)malloc(sizeof(int) * ac - 1);
	
	while (av && av[i])
	{
		tab[i - 1] = atoi(av[i]);
		i++;
	}
	i = 0;
	sort_int_tab(tab, ac - 1);
	while (i < ac - 1)
		printf("%d ", tab[i++]);
	printf("\n");
	return (0);
}*/
