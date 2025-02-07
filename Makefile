CC= cc
FLAGS= -Wall -Wextra -Werror
RM= rm -f
FILES= mandatory/event.c mandatory/fractol.c mandatory/initialize.c mandatory/main.c  mandatory/math.c mandatory/render.c mandatory/utils.c
OBJECT=	$(FILES:.c=.o)
MLX = libmlx.a
NAME=fractol

all: $(NAME)

$(NAME): $(MLX) $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mandatory/%.o: mandatory/%.c include/fractol.h
	$(CC) $(FLAGS) -I include -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all
