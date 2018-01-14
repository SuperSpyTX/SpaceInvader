define colorecho
	@tput setaf 6
	@echo $1
	@tput sgr0
endef

NAME = SpaceInvaders
CC = clang++
FLAGS = -Wall -Wextra -Werror -lncurses
FILES = main.cpp Ncurse.class.cpp



all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(FILES) -o $(NAME)
	$(call colorecho,"Executable $(NAME) Created")


clean :
	@rm -rf $(NAME)
	$(call colorecho, "Executable $(NAME) Removed")

re : clean all