#include <stdlib.h>

char		*ft_strdup(char *src)
{
	char	*cpy;
	int		len = 0;
	int		i = 0;

	if (!src)
		return (NULL);
	while (src && src[len])
		len++;
	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cpy[len] = '\0';
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
