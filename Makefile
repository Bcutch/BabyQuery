all: babyQuery babiesQuery

babyQuery: removeCommas.o babyQuery.o
	gcc -ansi -Wall babyQuery.o removeCommas.o -o babyQuery

babiesQuery: removeCommas.o babiesQuery.o
	gcc -ansi -Wall babiesQuery.o removeCommas.o -o babiesQuery

babyQuery.o: babyQuery.c
	gcc -ansi -Wall -c babyQuery.c

babiesQuery.o: babiesQuery.c
	gcc -ansi -Wall -c babiesQuery.c

clean: 
	rm -f babyQuery.o babiesQuery.o babyQuery babiesQuery
