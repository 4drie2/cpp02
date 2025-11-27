# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrien <adrien@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 17:59:30 by adrien            #+#    #+#              #
#    Updated: 2025/11/27 18:22:16 by adrien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME		= ex00

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Directories
SRCDIR		= ../FixedPoint
OBJDIR		= obj

# Source files
SRCS		= main.cpp \
			  $(SRCDIR)/FixedPoint.cpp

# Object files
OBJS		= $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Include directories
INCLUDES	= -I$(SRCDIR)

# Colors for output
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(RESET)"

$(OBJDIR)/$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)Compiling: $<$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
