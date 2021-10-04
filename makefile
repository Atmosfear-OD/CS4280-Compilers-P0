P0: main.o tree.o
	g++ main.o tree.o -o P0

main.o: main.cpp
	g++ -c main.cpp

tree.o: tree.cpp
	g++ -c tree.cpp

clean:
	rm -rf *.o *.inorder *.postorder *.preorder P0
