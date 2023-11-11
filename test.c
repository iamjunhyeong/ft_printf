
#include <unistd.h>

void	ft_putadr(unsigned long long adr)
{
	char	digits[] = "0123456789abcdef";

	if (adr >= 16)
	{
		ft_putadr(adr / 16);
		write(1, &digits[adr % 16], 1);
	}
	else if (adr > 0)
	{
		write(1, &digits[adr % 16], 1);
	}
}

int	ft_print_p(void *p)
{
	if (!p)
		return (-1);
	write(1, "0x", 2);
	ft_putadr((unsigned long long)p);
	return 1;
}

int main()
{
	void *a = "12345674567";

	printf("%p\n\n", a);
	if (ft_print_p(a))
		printf("\n\nsucces\n");
}

