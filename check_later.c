

/* Checks if argv is numbers only*/
static int	arg_is_number(t_node *p_s)
{
	int				neg;
	long long int	i;

	i = 0;
	neg = 1;
	while (p_s->argv == '-')
	{
		neg = -1;
		++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((neg * i) > 2147483647 || (neg * i) < -2147483648)
		ft_error();
	return (neg * i);
}