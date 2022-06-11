NAME = push_swap
LIBFT_A = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I./libft -I./includes

LIBFT = libft/

SRCS = ${shell find ./srcs -name "*.c"}
OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

%.o:	%.c
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):		$(OBJS)
				make -C $(LIBFT)
				make -C $(LIBFT) bonus
				# FOR MAC
				$(CC) $(CFLAGS) $(INC) ./libft/libft.a $(OBJS) -o $(NAME)
				# FOR LINUX
				# $(CC) $(CFLAGS) $(INC) -L./libft $(OBJS) -l:$(LIBFT_A) -o $(NAME)
					

clean:
				make clean -C $(LIBFT)
				rm -rf $(OBJS)

fclean:	clean
				make fclean -C $(LIBFT)
				rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
