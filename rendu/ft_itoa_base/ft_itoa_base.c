#include <stdlib.h>
#include<limits.h>
//#include<stdio.h>

int			ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	return (nb + '0');
}

char		*ft_strdup(char *str)
{
	char	*s = NULL;
	int		i = 0;
	int		len = 0;

	while (str && str[i])
		i++;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	while (len < i)
	{
		s[len] = str[len];
		len++;
	}
	return (s);
}

char		*ft_itoa_base(int value, int base)
{
	int		i = 0;
	char	*str;
	int		tmp = value > 0 ? value : -value;
	int		neg = 0;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == INT_MIN && base == 10)
		return (ft_strdup("-2147483648"));
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	if (value < 0 && base == 10)
	{
		i++;
		neg++;
	}
	else if (value < 0)
		value = -value;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = ex(tmp);
		value /= base;
		i--;
		if (neg && i == 0)
			str[i--] = '-';
	}
	return (str);
}
 /*int		main()
{
	printf("%s\n",ft_itoa_base(23, 16));
	return (0);
}*/
