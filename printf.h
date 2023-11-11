#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_print_sx(unsigned int x);
int		ft_print_bx(unsigned int x);
int		ft_print_u(unsigned int u);
int		ft_print_d(int d);
int		ft_print_p(void *p);
int		ft_print_s(char *s);
int		ft_print_c(int c);
void	ft_putadr(unsigned long long adr, int caps);
void	ft_putstr(char *s);
int		check_type(const char c, va_list listp);
int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
char	*ft_itoa_un(unsigned int n);
size_t	ft_strlen(const char *s);

#endif