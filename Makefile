SRC = ft_mapper.c \
	  ft_printf.c \
	  ft_pf_chr.c \
	  ft_pf_dbl.c \
	  ft_pf_int.c \
	  ft_pf_len.c \
	  ft_pf_str.c \
	  pf_buf.c \
	  pf_format.c \
	  pf_utility.c

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a
CC = gcc
RM = @rm -fv
TEST_FILE = test.out
.PHONY: all, test, clean, fclean, re, force

all: $(NAME)

force:
	@true

$(LIB): force
	@make -C libft/

test: $(TEST_FILE)

$(TEST_FILE): main.c $(NAME)
	$(CC) -o $@ $< -L. -l$(NAME:lib%.a=%)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $<

$(NAME): $(LIB) $(OBJ) ft_printf.h Makefile
	rm -fv $(NAME)
	ar -rc $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIB) 2> /dev/null
	ranlib $(NAME)

clean:
	@echo "Cleaning objects:"
	$(MAKE) -C libft/ fclean
	$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning library:"
	$(RM) $(NAME)
	$(RM) $(TEST_FILE)

re: fclean all
