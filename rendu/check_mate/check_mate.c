
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	check_pos(char **board, int len)
{
	
}

int		main(int ac, char **av)
{
	int		len;
	int		i = 1;
	int		j;
	char	**board;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	board = (char **)malloc(sizeof(char *) * (ac - 2));
	while (av && av[i])
	{
		len = ft_strlen(av[i]);
		board[i - 1] = (char *)malloc(sizeof(char) * (len + 1));
		board[i - 1][len] = '\0';
		if (len != ac -1)
		{
			ft_putchar('\n');
			return (1);
		}
		j = 0;
		while (j < len)
		{
			if (av[i][j] != 'R' || av[i][j] != 'K' || av[i][j] != '.' || av[i][j] != 'P' || av[i][j] != 'Q' || av[i][j] != 'B')
			{
				ft_putchar('\n');
				return (1);
			}
			board[i - 1][j] = av[i][j];
			j++;
		}
		i++;
	}
	check_pos(board, len);
	i = 0;
	while (board[i])
		free(board[i++]);
	free(board);
	return (0);
}
