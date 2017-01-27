#include <stdlib.h>
#include <limits.h>

char	*ft_itoa(int nbr)
{
	char	*str  = NULL;
	int		len = 0;
	int		neg = 0;
	int		tmp;

	if (nbr == 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (nbr == INT_MIN)
	{
		if (!(str = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		str[11] = '\0';
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		return (str);
	}
	if (nbr < 0)
	{
		len++;
		neg = 1;
		nbr = -nbr;
	}
	tmp = nbr;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (nbr)
	{
		str[len] = nbr % 10  + '0';
		nbr /= 10;
		len--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
#include <stdio.h>
int		main()
{
	char *str;
	int	nb = 0;
	str = ft_itoa(nb);
	printf("nb: %d & str: %s\n",nb,  str);
	return (0);
}
