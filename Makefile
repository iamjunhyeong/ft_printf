NAME = printf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
SRCS = ft_itoa_un.c \
	ft_itoa.c \
	ft_printf.c \
	option_utils.c \
	printf_option.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re 