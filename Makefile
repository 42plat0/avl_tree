run: myavltree
	./myavltree

make: myavltree.c
	gcc myavltree.c -o myavltree

gdb: 
	rm -rf myavltree
	gcc -g -o myavltree myavltree.c
	gdb ./myavltree
	
clean:
	rm -rf myavltree