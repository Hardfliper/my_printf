##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile all prog
##

FOLDER	=	./lib/my/

SRCS	=	$(FOLDER)my_printf.c

CRITNAME =	unit_test

LDFLAGS	=	-L. -lmy

CRITERION =	-lcriterion --coverage

TEST	=	./tests/test.c

TEMP	=	*.gcno	\
		*.gcda

all:	$(CRITNAME)

$(CRITNAME):
	make -C $(FOLDER)

tests_run:
	gcc -o $(CRITNAME) $(SRCS) $(TEST) $(LDFLAGS) $(CRITERION)
	./unit_test

clean:
	rm -f $(OBJ)
	make clean -C $(FOLDER)

fclean:	clean
	make fclean -C $(FOLDER)
	rm -f $(CRITNAME) libmy.a
	rm -f $(TEMP)

re:	fclean all
	make re -C $(FOLDER)

.PHONY:	all clean fclean re
