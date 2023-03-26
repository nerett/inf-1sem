executable: tree_main.cpp libtree.a tree.h
	g++ -Wall -Wextra -g -fsanitize=adress,leak main.cpp -L. -ltree

libtree.a: tree.o
	ar cr libtree.a tree.o
	ranlib libtree.a

tree.o: tree.cpp
	gcc -Wall -Wextra -g -c tree.cpp -o tree.o
