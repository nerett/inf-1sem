executable:	main.c libtree.a tree.h
	gcc -Wall -Wextra -g -fsanitize=address,leak main.c -L. -ltree -o executable
	./executable

libtree.a:	tree.o
	ar cr libtree.a tree.o
	ranlib libtree.a

tree.o: tree.c 
	gcc -Wall -Wextra -g -c tree.c -o tree.o
