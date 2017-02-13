#include <limits.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest = NULL;
	int		i = 0;
	while (src && src[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dest[i] = '\0';
	i--;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

char	ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	return (nb + '0');
}

char	*ft_itoa_base(int value, int base)
{
	int		neg = 0;
	int		i = 0;
	int		tmp;
	char	*nb;

	if (value < 0 && base == 10)
	{
		neg++;
		i++;
	}
	if (value < 0)
		value = -value;
	if (value == INT_MIN)
		return (ft_strdup("-2147483648"));
	tmp = value;
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	if (!(nb = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		nb[i] = ex(tmp);
		value /= base;
		i--;
		if (neg && i == 0 && base == 10)
		{
			nb[i] = '-';
			break;
		}
	}
	return (nb);
}
