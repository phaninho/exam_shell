#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			is_the_one(int i, char *str, char c)
{
	i--;
	while (i >= 0)
	{
		if (str[i] == c)
			return (1);
		i--;
	}
	return(0);
}

void		inter(char *s1, char *s2)
{
	int		i = 0;
	int		j;

	while (s1 && s1[i])
	{
		j = -1;
		while (s2 && s2[++j])
		{
			if (!is_the_one(i, s1, s1[i]) && s1[i] == s2[j])
			{
				ft_putchar(s1[i]);
				break;
			}
		}
		i++;
	}
}

int			main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}
