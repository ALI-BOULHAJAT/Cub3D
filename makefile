NAME = cub3d

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

CC = cc

########## PATH ########

PARC_DIR = ./source/parcing

UTIL_DIR = ./source/utils

LIBFT_DIR = ./libft

########################

SRCS = ${PARC_DIR}/cub3d.c ${PARC_DIR}/map_storage.c ${PARC_DIR}/texture_utils.c ${PARC_DIR}/map_utils.c ${UTIL_DIR}/get_next_line.c ${UTIL_DIR}/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

_libft :
	@make bonus -C $(LIBFT_DIR)

$(NAME) : $(OBJS) _libft
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)

%.o:%.c $(SRCS)
	@$(CC) $(CFLAGS) -c $<  -o  $@

clean : 
	@rm -rf $(OBJS)
	@make fclean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re