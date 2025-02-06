int	ft_str_alpha_num(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if ((*s < 'a' || *s > 'z')
			&& (*s < 'A' || *s > 'Z')
			&& (*s < '0' || *s > '9'))
			return (0);
		s++;
	}
	return (1);
}
