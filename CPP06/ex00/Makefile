# Setup
NAME 		:=	converter
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g3

# Colors
DEF_COLOR	:=	\033[0;39m
GREEN 		:=	\033[0;92m
CYAN 		:=	\033[0;96m

# Sources and Objects
SRC			:= main.cpp \
				ScalarConverter.cpp \
				type.cpp \
				print.cpp \
				convert.cpp
				
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
clean: clear_files
	rm -rf $(BIN_DIR)
	@echo "$(CYAN)binary file(s) cleaned !$(DEF_COLOR)"

# Full Clean, Objects and Binaries
fclean: clean
	rm -f $(NAME)
	@echo "$(CYAN)exec file(s) cleaned !$(DEF_COLOR)"

clear_files: 
	@rm -f *_shrubbery

# Remake
re: fclean $(NAME)
	@echo "$(GREEN)Cleaned and rebuilt everything !$(DEF_COLOR)"

.PHONY: all clean fclean re