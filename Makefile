name = myavltree

run: $(name)
	./$(name)

make: $(name).c
	gcc $(name).c -o $(name)

gdb: 
	rm -rf $(name)
	gcc -g -o $(name) $(name).c
	gdb ./$(name)
	
clean:
	rm -rf $(name)

valgrind:
	valgrind ./$(name)