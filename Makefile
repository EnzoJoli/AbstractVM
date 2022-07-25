##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

SRC 	= 	src/main.cpp	\
			src/Vm.cpp		\
			src/BigDecimal.cpp	\
			src/Double.cpp	\
			src/Float.cpp	\
			src/Int8.cpp	\
			src/Int16.cpp	\
			src/Int32.cpp	\
			src/Factory.cpp	\
			src/Parser.cpp

CC	=	g++

CPPFLAGS =	-Iincludes -Wall -Wextra

NAME	=	abstractVM

all :		$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
