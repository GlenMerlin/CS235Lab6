all:
	g++ -g main.cpp -o llist

test:
	g++ -g main.cpp -o llist
	valgrind ./llist