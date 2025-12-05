# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 00:00:00 by abidaux           #+#    #+#              #
#    Updated: 2025/12/05 05:06:01 by abidaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= ex02

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Source files
SRCS		= main.cpp \
			  Fixed.cpp

# Object files
OBJS		= $(SRCS:.cpp=.o)

# Colors for output
GREEN		= \033[0;32m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

# Default rule
all: $(NAME)

# Compile the program
$(NAME): $(OBJS)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BLUE)$(NAME) created successfully!$(RESET)"

# Compile object files
%.o: %.cpp
	@echo "$(GREEN)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS)

# Clean everything
fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
