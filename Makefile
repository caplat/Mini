NAME = minishell

SRCS = main.c \
parsing.c \
signal.c \
utils.c \
utils_bis.c \
free.c \
dollar.c \
triple.c \
heredoc.c \


CC = gcc -Wall -Wextra -Werror -g3

MY_OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIB = -lreadline -L/Users/$$USER/.brew/opt/readline/lib

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I /Users/$$USER/.brew/opt/readline/include -c $< -o $(<:.c=.o)

$(NAME): $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) $(LIBFT) -o $(NAME)

debug: $(MY_OBJECTS)
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIB) -fsanitize=address $(LIBFT) -o $(NAME)

RM=rm -f

clean:
	$(RM) $(MY_OBJECTS)
	$(MAKE) -C libft clean

fclean: clean
	${RM} ${NAME}
	$(MAKE) -C libft fclean

re:	fclean all