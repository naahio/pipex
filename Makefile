NAME=pipex
CC=gcc
CFLAGS=-Wall -Werror -Wextra
INCLUDES=.
SRC= ft_putchar_fd.c ft_putendl_fd.c ft_strchr.c ft_putstr_fd.c ft_strlen.c ft_split.c ft_strjoin.c files.c pipex.c
OBJ=$(SRC:.c=.o)
REM=rm -f
all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) -I$(INCLUDES) $^ $(CFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) -g -c  $(CFLAGS) $<
	@echo  Compiling $< :"\x1B[1;32m[ok]\x1B[0m"

clean:
	$(REM) $(OBJ) $(BOBJ)
		
fclean: clean
	$(REM) $(NAME)

re:	fclean all
.PHONY: all clean fclean re bonus re_bonus