run: myavltree
	./myavltree

make: myavltree.c
	gcc myavltree.c -o myavltree

clean:
	rm -rf myavltree