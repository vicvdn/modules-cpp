# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victoirevaudaine <victoirevaudaine@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 14:00:04 by vvaudain          #+#    #+#              #
#    Updated: 2024/07/11 16:28:13 by victoirevau      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Setup
NAME 		:=	Serena
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g3 -Wshadow

# Colors
DEF_COLOR	:=	\033[0;39m
GREEN 		:=	\033[0;92m
CYAN 		:=	\033[0;96m

# Sources and Objects
SRC			:= main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \
				DiamondTrap.cpp
BIN_DIR		:= ./bin
OBJ			:= $(addprefix $(BIN_DIR)/,$(SRC:.cpp=.o))

# Default make
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN)program compiled!$(DEF_COLOR)"

$(BIN_DIR)/%.o:%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Objects
clean:
	rm -rf $(BIN_DIR)
	@echo "$(CYAN)binary file(s) cleaned !$(DEF_COLOR)"

# Full Clean, Objects and Binaries
fclean: clean
	rm -f $(NAME)
	@echo "$(CYAN)exec file(s) cleaned !$(DEF_COLOR)"

# Remake
re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything !$(DEF_COLOR)"

.PHONY: all clean fclean re