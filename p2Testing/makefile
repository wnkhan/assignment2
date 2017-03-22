FLAGS = -Wall -Wextra -std=c99

bstrees: bstrees.o bst.o vbst.o rbt.o handlestring.o max_min.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o
	gcc $(FLAGS) bstrees.o bst.o vbst.o rbt.o handlestring.o max_min.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o -o bstrees
bstrees.o: bstrees.c bst.h vbst.h comparator.h integer.h real.h string.h handlestring.h max_min.h
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
max_min.o: max_min.c max_min.h bst.h
	gcc $(FLAGS) -c max_min.c

cleanbuild:
	clear
	make clean
	make
clean:
	rm -f bstrees.o bst.o vbst.o rbt.o handlestring.o max_min.o scanner.o comparator.o integer.o real.o string.o sll.o queue.o bstrees

test: ./bstrees
	
	# ./bstrees -v s9.0 display btest9.txt
	# ./bstrees -r s10.0 display btest10.txt
	# ./bstrees -v s11.0 display btest11.txt
	# ./bstrees -r s12.0 display btest12.txt
	# ./bstrees -v s13.0 display btest13.txt
	# ./bstrees -r s14.0 display btest14.txt
	# ./bstrees -v s15.0 display btest15.txt
	# ./bstrees -r w16.0 display btest16.txt
	# ./bstrees -v w17.0 display btest17.txt
	# ./bstrees -r w18.0 display btest18.txt
	# ./bstrees -v w19.0 display btest19.txt
	# ./bstrees -r w20.0 display btest20.txt
	# ./bstrees -v w21.0 display btest21.txt
	# ./bstrees -r w22.0 display btest22.txt
	# ./bstrees -v w23.0 display btest23.txt
	# ./bstrees -r w24.0 display btest24.txt

	# ./bstrees -r shakespeare.txt shakespeare.display btest33.txt

	#Testing against existing files

	# diff btest9.txt test9.txt
	# diff btest10.txt test10.txt
	# diff btest11.txt test11.txt
	# diff btest12.txt test12.txt
	# diff btest13.txt test13.txt
	# diff btest14.txt test14.txt
	# diff btest15.txt test15.txt
	# diff btest16.txt test16.txt
	# diff btest17.txt test17.txt
	# diff btest18.txt test18.txt
	# diff btest19.txt test19.txt
	# diff btest20.txt test20.txt
	# diff btest21.txt test21.txt
	# diff btest22.txt test22.txt
	# diff btest23.txt test23.txt
	# diff btest24.txt test24.txt

	# diff btest33.txt test33.txt
