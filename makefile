FLAGS = -Wall -Wextra -std=c99

bstrees: bstrees.o bst.o vbst.o rbt.o handlestring.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o
	gcc $(FLAGS) bstrees.o bst.o vbst.o rbt.o handlestring.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o -o bstrees
bstrees.o: bstrees.c bst.h vbst.h comparator.h integer.h real.h string.h handlestring.h
	gcc $(FLAGS) -c bstrees.c
bst.o: bst.c bst.h
	gcc $(FLAGS) -c bst.c
vbst.o: vbst.c vbst.h bst.h
	gcc $(FLAGS) -c vbst.c
rbt.o: rbt.c rbt.h bst.h
	gcc $(FLAGS) -c rbt.c
scanner.o: scanner.c scanner.h
	gcc $(FLAGS) -c scanner.c
comparator.o: comparator.c comparator.h
	gcc $(FLAGS) -c comparator.c
integer.o: integer.c integer.h
	gcc $(FLAGS) -c integer.c
real.o: real.c real.h
	gcc $(FLAGS) -c real.c
string.o: string.c string.h
	gcc $(FLAGS) -c string.c
sll.o: sll.c sll.h
	gcc $(FLAGS) -c sll.c
queue.o: queue.c queue.h sll.h
	gcc $(FLAGS) -c queue.c
handlestring.o: handlestring.c handlestring.h scanner.h string.h
	gcc $(FLAGS) -c handlestring.c
# max_min.o: max_min.c max_min.h bst.h
# 	gcc $(FLAGS) -c max_min.c

cleanbuild:
	clear
	make clean
	make
clean:
	rm -f bstrees.o bst.o vbst.o rbt.o handlestring.o max_min.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o bstrees

test: ./bstrees
	