
#include <unistd.h>

int	check_if_double(char *str, char c, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int	i;
	int	i2;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			i2 = 0;
			while (argv[2][i2] != '\0')
			{
				if (argv[1][i] == argv[2][i2])
				{
					if (check_if_double(argv[1], argv[1][i], i))
					{
						write (1, &argv[1][i], 1);
						break ;
					}
				}
				i2++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}
