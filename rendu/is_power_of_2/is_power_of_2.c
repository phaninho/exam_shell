#include <limits.h>

int		is_power_of_2(unsigned int n)
{
	unsigned int		rsl = 1;
	int		pow = 2;

	if (n >= UINT_MAX)
		return (0);
	while (rsl < n)
		rsl *= pow;
	if (rsl == n)
		return (1);
	return (0);
}
