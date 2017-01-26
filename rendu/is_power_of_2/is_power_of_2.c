int		is_power_of_2(unsigned int n)
{
	int		pw = 2;
	unsigned int	rsl = 1;
	while (rsl < n)
		rsl *= pw;
	if (rsl - n != 0)
		return (0);
	return (1);
}
