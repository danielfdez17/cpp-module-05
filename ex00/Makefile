# * Colors
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m
OK = $(GREEN)[OK]$(RESET)

# * Program name
NAME = bureaucrat

# * Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

# * Removal
RM = rm -rf

# * Includes
INCLUDES = -I ./inc/

# * Objects dir
OBJ_DIR = ./obj/

# * Sources files
BUREAUCRAT_DIR = ./src/
BUREAUCRAT_SRCS = 	Bureaucrat.cpp \
					GradeTooHighException.cpp \
					GradeTooLowException.cpp \
					main.cpp

SRCS = $(BUREAUCRAT_SRCS)

# * Object files
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# ! RULES
$(OBJ_DIR)%.o: $(BUREAUCRAT_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(OK) $(GREEN)$(NAME)$(RESET)"

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJS)
	@echo "$(OK) $(RED)Removed object files$(RESET)"

fclean: clean
	@echo "$(OK) $(RED)Removed $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all
	@echo "$(OK) $(YELLOW)Rebuilt $(NAME)$(RESET)"

run: all
	clear
	./$(NAME)

.PHONY: all obj clean fclean re

.DEFAULT_GOAL: all
