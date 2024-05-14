CC           = gcc
LIBFT_DIR    = ps_libft/
LIBFT        = $(LIBFT_DIR)libft.a
CFLAGS       = -Wall -Wextra -Werror
PUSH_SWAP_DIR  = ./
HEADERS      = -I $(PUSH_SWAP_DIR) -I $(LIBFT_DIR)
NAME         = push_swap
RM           = rm -rf

CFILES = $(wildcard $(PUSH_SWAP_DIR)/*.c)

OFILES = $(CFILES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) -L$(LIBFT_DIR) -lft -lm

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all