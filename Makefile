SRCS	?= srcs/main.c \
		   srcs/parsing/check_valid_path/check_components.c \
		   srcs/parsing/check_valid_path/check_valid_path.c \
		   srcs/parsing/check_valid_path/fload_map.c \
		   srcs/parsing/check_valid_path/set_up_copy.c \
		   srcs/parsing/initialize_map/check_outline.c \
		   srcs/parsing/initialize_map/initialize_map.c \
		   srcs/parsing/check_argument.c \
		   srcs/parsing/check_valid_map.c \
		   srcs/parsing/parsing.c \
		   srcs/game/display_map/check_walls.c \
		   srcs/game/display_map/check_walls_2.c \
		   srcs/game/display_map/display_good_walls.c \
		   srcs/game/display_map/display_map.c \
		   srcs/game/enemies/enemies.c \
		   srcs/game/enemies/enemies_movements.c \
		   srcs/game/enemies/enemies_utils.c \
		   srcs/game/enemies/randomize_enemies.c \
		   srcs/game/enemies/randomize_enemies_utils.c \
		   srcs/game/keys/actions_key.c \
		   srcs/game/keys/check_key.c \
		   srcs/game/keys/key_utils.c \
		   srcs/game/keys/keyhook.c \
		   srcs/game/set_up_game/divise_map.c \
		   srcs/game/set_up_game/set_up_sprite.c \
		   srcs/game/set_up_game/set_up_var.c \
		   srcs/game/game_utils.c \
		   srcs/game/launch_animation_and_movement.c \
		   includes/libraries/srcs_double_list/ft_double_lstadd_back.c \
		   includes/libraries/srcs_double_list/ft_double_lstadd_front.c \
		   includes/libraries/srcs_double_list/ft_double_lstclear.c \
		   includes/libraries/srcs_double_list/ft_double_lstdelone.c \
		   includes/libraries/srcs_double_list/ft_double_lstlast.c \
		   includes/libraries/srcs_double_list/ft_double_lstnew.c \
		   includes/libraries/srcs_double_list/ft_double_lstsize.c 

OBJS 	?= ${SRCS:.c=.o}

NAME 	?= so_long

COMPILER ?= clang

RM		?= rm -f

CFLAGS 	?= -Wall -Werror -Wextra -g

LIBRARY ?= includes/libraries/libft/libft.a \
		  includes/libraries/libft/ft_printf/libftprintf.a \
		  includes/libraries/minilibx/libmlx.a

.c.o:		${OBJS}
			${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 		${NAME}

${NAME}:	${OBJS}
			make -C includes/libraries/libft
			make -C includes/libraries/minilibx
			${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBRARY} -lXext -lX11 

clean: 
			${RM} ${OBJS} ${BOBJS} 
			make -C includes/libraries/libft clean
			make -C includes/libraries/minilibx clean

fclean: 	clean
			${RM} ${NAME} ${BONUS}
			make -C includes/libraries/libft fclean

re:
			make fclean
			make

.PHONY: 	all bonus clean fclean re 
