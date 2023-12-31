# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 14:47:40 by wfan              #+#    #+#              #
#    Updated: 2023/09/03 15:59:10 by wfan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
MLX 		= libmlx_Linux.a
LIBFT 		= libft.a

LFT_PATH 	= ./libft
MLX_PATH 	= ./minilibx-linux/
INCLUDES 	= ./includes
SRCDIR 		= ./srcs/

SRC 		= $(SRCDIR)main.c \
				$(SRCDIR)close.c \
				$(SRCDIR)color.c \
				$(SRCDIR)draw.c \
				$(SRCDIR)error.c \
				$(SRCDIR)init_utils.c \
				$(SRCDIR)init.c \
				$(SRCDIR)key_handle.c \
				$(SRCDIR)menu.c \
				$(SRCDIR)project.c \
				$(SRCDIR)read.c \
				$(SRCDIR)render.c \
				$(SRCDIR)rotate.c \
				$(SRCDIR)transform.c \
				$(SRCDIR)utils.c \
				$(SRCDIR)utils2.c \
				$(SRCDIR)get_next_line_utils.c \
				$(SRCDIR)get_next_line.c

OBJ=$(notdir $(SRC:.c=.o))
#OBJ= fdf.o

#compilation
CF 			= -Wall -Wextra -Werror
CC 			= gcc
MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
CFI 		= -I$(INCLUDES) -Ilibft -Iminilibx-linux
# DEBUG		= -fsanitize=address -g

#common commands
RM =rm -f

#rules
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@printf "\n$(CY)Generating FdF executable...$(RC)\n"
	$(CC) $(CF) $(DEBUG) -o $(NAME) $(OBJ) -L $(LFT_PATH) -L $(MLX_PATH) -lft $(MLX_CF)
	@printf "$(GR)Done!$(RC)\n\n"

$(OBJ): $(SRC)
	@printf "\n$(CY)Compiling source files...$(RC)\n"
	$(CC) $(CF) -g -c $(CFI) $(SRC)
	@printf "$(GR)Objects ready!$(RC)\n\n"

$(MLX):
	@printf "\n$(CY)Generating MiniLibX...$(RC)\n"
	@make -C $(MLX_PATH)
	@printf "$(GR)MiniLibX created!$(RC)\n\n"

$(LIBFT):
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	@make -C $(LFT_PATH)
	@printf "$(GR)Libft created!$(RC)\n\n"

bonus: all

re: fclean all

rebonus: fclean bonus

# leaks: 
# 	$(LEAKS) $(LF)
# 	@printf "$(GR)Leaks log ready! Check valgrind-out.txt $(RC)\n\n"

# cleanleaks: 
# 	$(RM) $(LEAKS_FILE)
# 	@printf "$(GR)Leaks log file deleted.$(RC)\n\n"

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(RC)\n"
	@make clean -C $(LFT_PATH)
	@printf "$(GR)Libft objects removed!$(RC)\n\n"
	$(RM) -rf $(OBJ) $(BONUS_OBJ) objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(RC)\n"
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@printf "$(GR)All libraries removed!$(RC)\n\n"

install: 
	sudo apt-get install gcc make xorg libxext-dev libbsd-dev -y
	@printf "$(GR)All dependencies ready!$(RC)\n\n"

.PHONY: clean fclean re all

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m
