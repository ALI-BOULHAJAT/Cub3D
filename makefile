NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

CC = cc

########## PATH ########

PARC_DIR = ./source/parcing

DRAW_DIR = ./source/drawing

UTIL_DIR = ./source/utils

LIBFT_DIR = ./libft

########################

SRCS = ${PARC_DIR}/cub3d.c ${PARC_DIR}/map_storage.c ${PARC_DIR}/texture_utils.c ${PARC_DIR}/map_utils.c ${PARC_DIR}/check_closed_map.c ${PARC_DIR}/check_circle.c \
		${DRAW_DIR}/ft_window.c ${DRAW_DIR}/ft_draw.c \
		${UTIL_DIR}/get_next_line.c ${UTIL_DIR}/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

_libft :
	@ make bonus -C $(LIBFT_DIR)

$(NAME) : $(OBJS) _libft
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "\x1b[32m  ✅     Make successfully    💯 ✅\033[0m\n"

%.o:%.c $(SRCS)
	@$(CC) $(CFLAGS) -c $<  -o  $@

clean : 
	@rm -rf $(OBJS)
	@make fclean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)
	@printf "\x1b[36m  ✅ Make fclean successfully 💯 ✅\033[0m\n"

re : fclean all

.PHONY : all clean fclean re