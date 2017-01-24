#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		len;
	int		*tab;
	int		i;

	i = 0;
	len = end > start ? end - start : start - end;
	tab = (int *)malloc(sizeof(int) * len);
	while (i <= len)
	{
		tab[i] = end;
		end > start ? end-- : end++;
		i++;
	}
	return (tab);
}
