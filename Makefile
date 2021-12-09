NAME	=	pipex

SRCS	=	pipex.c

HEADER	=	pipex.h

OBJ		=	$(SRCS%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	-I

СС		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf
#---------------------------------------------------------------------------------
RED		=	"\033[1;31m"
BLUE	=	"\033[1;34m"
YELLOW	=	"\033[1;33m"
WHITE	=	"\033[1;32m"
PUPURE	=	"\033[1;35m"
GRY		=	"\033[1;30m"
END		=	"\033[0m"
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)
libft:
			@$(MAKE) -C $(dir $(LIB))


$(NAME):	$(OBJ) %(LIB)
			$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJ)
			@echo "$(YELLOW)\n Complited $(NAME)\n$(YELLOW)"

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C $(dir $(LIB)) clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(YELLOW)"

fclean:		clean
			@$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)
			@echo "$(YELLOW)\n< All created files were deleted >\n$(YELLOW)"

re:			fclean all
			@echo "$(YELLOW)\n< Remake done >\n$(YELLOW)"


