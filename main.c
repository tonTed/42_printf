#include <stdio.h>

int	ft_lennb_16(unsigned int nb)
{
	int	len;

	len = 1;
	while (nb > 16)
	{
		nb %= 16;
		len++;
	}
	return (len);
}

int main()
{
	// int nb = -1400000000;
	
	printf("%d\n", ft_lennb_16(0));
	// printf("%X\n", nb);
	// printf("%p\n", nb);
	return 0;
}
