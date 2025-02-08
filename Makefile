CC= cc
FLAGS= -Wall -Wextra -Werror
RM= rm -f
FILES= mandatory/event.c mandatory/fractol.c mandatory/initialize.c mandatory/main.c  mandatory/math.c mandatory/render.c mandatory/utils.c
OBJECT=	$(FILES:.c=.o)
BFILES= bonus/event_bonus.c bonus/fractol_bonus.c bonus/initialize_bonus.c bonus/main_bonus.c  bonus/math_bonus.c bonus/render_bonus.c bonus/utils_bonus.c
BOJECT= $(BFILES:.c=.o)
MLX = libmlx.a
NAME= fractol
BNAME = fractol_bonus 

all: $(NAME)

$(NAME): $(MLX) $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(MLX) $(BOJECT)
	$(CC) $(FLAGS) $(BOJECT) $(MLX) -framework OpenGL -framework AppKit -o $(BNAME)

bonus/%.o: bonus/%.c include/fractol_bonus.h
	$(CC) $(FLAGS) -I include -c $< -o $@

mandatory/%.o: mandatory/%.c include/fractol.h
	$(CC) $(FLAGS) -I include -c $< -o $@

clean:
	$(RM) $(OBJECT) $(BOJECT)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all
