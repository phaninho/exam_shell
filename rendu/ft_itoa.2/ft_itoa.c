#include <stdlib.h>
#include <limits.h>
#include<unistd.h>
#include <stdio.h>
char		*ft_itoa(int nbr)
{
	int		len;
	int		tmp;
	int		neg;
	char	*rsl;

	neg = 0;
	len = 0;
	if (nbr == 0)
	{
		if (!(rsl = (char *)malloc(sizeof(char) * (2))))
			return (NULL);
		rsl[0] = '0';
		rsl[1] = '\0';
		return (rsl);
	}
	if (nbr == INT_MIN)
	{
		if (!(rsl = (char *)malloc(sizeof(char) * (12))))
			return (NULL);
		rsl[11] = '\0';
		rsl[0] = '-';
		rsl[1] = '2';
		rsl[2] = '1';
		rsl[3] = '4';
		rsl[4] = '7';
		rsl[5] = '4';
		rsl[6] = '8';
		rsl[7] = '3';
		rsl[8] = '6';
		rsl[9] = '4';
		rsl[10] = '8';
		return (rsl);
	}
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
		neg = 1;
	}
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	if (!(rsl = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rsl[len] = '\0';
	tmp = nbr;
	len--;
	while (len >= 0)
	{
		rsl[len] = (tmp % 10) + '0';
		tmp /= 10;
		len--;
		if (!len && neg)
		{
			rsl[0] = '-';
			return (rsl);
		}
	}
	return (rsl);
}

int		main()
{
	char *str;
	int	n = 0;
	str = ft_itoa(n);
	printf("dans le main : %s\n", str);
	return (0);
}
