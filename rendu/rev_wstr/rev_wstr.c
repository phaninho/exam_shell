#include <unistd.h>
#include <stdlib.h>

int		is_alpha(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	rev_wstr(char *str)
{
	int		tmp = 0;
	int		i = 0;
	int		word = 1;
	char	**tab;

	while (str && str[i])
	{
		if (str[i] == '\0' || is_space(str[i]))
			word++;
		i++;
	}
	tmp  = i - 1;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	tab[word] = NULL;
	while (i < word)
	{
		tab[i] = (char *)malloc(sizeof(char ) * (tmp + 1));
		tab[i][tmp] = '\0';
		i++;
	}
	tmp = 0;
	int		j = 0;
	i = 0;
	while (str && str[tmp])
	{
		if (is_alpha(str[tmp]))
		{
			tab[j][i] = str[tmp];
			i++;
		}
		if (i > 0 && is_space(str[tmp]))
		{
			tab[j][i] = '\0';
			j++;
			i = 0;
		}
		else if (str[tmp] == '\0')
			tab[j][i] = '\0';
		tmp++;
	}
	word--;
	while (word >= 0)
	{
		ft_putstr(tab[word]);
		word--;
		if ( word >= 0)
			ft_putchar(' ');
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
