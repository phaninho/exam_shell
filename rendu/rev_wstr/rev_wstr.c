#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

int			is_alpha(char c)
{
	if (c > 32 && c <= 126)
		return (1);
	return (0);
}

void		rev_str(char *str)
{
	int		i = 0;
	int		x = 0;
	int		j = 0;
	int		word = 1;
	int		len;
	char	**tab;
	while (str && str[i])
	{
		if (!is_alpha(str[i]))
			word++;
		i++;
	}
	i = 0;
	tab = (char **)malloc(sizeof(char *) * word);
	while (str && str[i])
	{
		len = 0;
		while (is_alpha(str[i]))
		{
			len++;
			i++;
		}
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		tab[j][len] = '\0';
		j++;
		if (str && str[i] && !is_alpha(str[i]))
			i++;
	}
	i = 0;
	j = 0;
	while (j < word)
	{
		x = 0;
		while (is_alpha(str[i]))
		{
			tab[j][x] = str[i];
			i++;
			x++;
		}
		j++;
		i++;
	}
	while (word - 1 >= 0)
	{
		ft_putstr(tab[word - 1]);
		if (word - 1 != 0)
		ft_putchar(' ');
		word--;
	}
}

int		main(int ac,  char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	if (av[1][0] == '\0')
	{
		ft_putchar('\n');
		return (1);
	}
	rev_str(av[1]);
	ft_putchar('\n');
	return (0);
}

