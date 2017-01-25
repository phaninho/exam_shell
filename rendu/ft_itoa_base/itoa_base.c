#include <stdlib.h>

int		conv_ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char	*itoa_base(int value, int base)
{
	int					i;
	char				*str;
	int				tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}
#include <stdio.h>
int main()
{
		char *rsl;
		int nb = 255;
		rsl = itoa_base(nb, 2);
		printf("nb: %s\n", rsl);
		return (0);
}
