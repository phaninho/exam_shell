#include <limits.h>

int		is_power_of_2(unsigned int n)
{
	unsigned int	tmp;

	tmp = n;
	if (n == 0)
		return (0);
	if (n >= UINT_MAX)
		return (0);
	while (tmp != 1)
	{
		if (!(tmp % 2))
			tmp /=2;
		else
			return (0);
	}
	if (tmp == 1)
		return (1);
	return (0);
}
