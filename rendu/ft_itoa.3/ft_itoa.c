#include <stdlib.h>
#include <limits.h>

int			ft_strlen(char *str)
{
	int		i = 0;

	while (str && str[i])
		i++;
	return (i);
}

char		*ft_strcpy(char *src, char *dest)
{
	int		i = 0;

	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char		*ft_strdup(char *str)
{
	int		len = 0;
	char	*dest;

	len = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	dest = ft_strcpy(str, dest);
	return (dest);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len = 0;
	int		neg;
	int		tmp;

	if (nbr == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (nbr == 0)
		return (ft_strdup("0"));
	neg = 0;
	if (nbr < 0)
	{
		len++;
		neg = 1;
		nbr = -nbr;
	}
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
		if (len == 0 && neg)
		{
			str[len] = '-';
			break;
		}
	}
	return (str);
}
