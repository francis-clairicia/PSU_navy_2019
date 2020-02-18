##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC_NO_TEST			=	src/main.c						\
						src/navy.c

SRC_TEST			=	src/errors.c					\
						src/signal_handler.c			\
						src/send_receive_number.c		\
						src/check_navy_on_gameboard.c	\
						src/print_gameboard.c			\
						src/init_ships.c				\
						src/destroy_ships.c

SRC					=	$(SRC_NO_TEST) $(SRC_TEST)

CFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

override LDFLAGS	=	-L./lib

override LDLIBS		+=	-lmy

OBJ					=	$(SRC:.c=.o)

NAME				=	navy

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LDLIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

-lmy:
	$(MAKE) -s -C ./lib/my

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CFLAGS += -g
debug:	$(LDLIBS)
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all -lmy tests_run debug clean fclean re
