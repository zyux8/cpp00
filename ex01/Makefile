# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 20:16:52 by ohaker            #+#    #+#              #
#    Updated: 2026/02/22 17:14:20 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SRC = phonebook.cpp \
	contact.cpp
OBJS = $(SRC:.cpp=.o)

# Color definitions for terminal output
NONE		= \033[0m
GREEN		= \033[32;01m
RED			= \033[31;01m
ORANGE		= \033[33;01m

.SILENT:

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	echo "$(ORANGE)		- Compiling $(NAME)...$(NONE)"
	@$(CXX) $(CXXFLAGS) $^ -o $(NAME)
	echo "$(GREEN)		- $(NAME) Compiled -$(NONE)"

fclean: clean
	@$(RM) $(NAME)
	echo "$(ORANGE)		- Deleted object files$(NONE)"

clean:
	@$(RM) $(OBJS)
	echo "$(ORANGE)		- Deleted $(NAME)$(NONE)"

re:	fclean all

gitpush:
	cd ..; \
	git add .; \
	git status; \
	echo "$(ORANGE)		- Enter commit message:$(NONE)"; \
	read input; \
	if [ -z "$$input" ]; then \
		echo "$(RED)		- No commit message entered. Exiting.$(NONE)"; \
	else \
		current_branch=$$(git rev-parse --abbrev-ref HEAD); \
		TIMESTAMP=$$(date '+%Y-%m-%d %H:%M'); \
		git commit -m "$$input" -m "Commit date: $$TIMESTAMP"; \
		git push origin $$current_branch; \
		echo "$(GREEN)		- Pushed to branch '$$current_branch'$(NONE)"; \
	fi

.PHONY:	all clean fclean re gitpush