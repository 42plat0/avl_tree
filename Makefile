name = main
lib = myavltree

run: $(name)
	./$(name)

main: $(name).o $(lib).o
	gcc -o $(name) $(name).o $(lib).o 

main.o: $(name).c $(lib).h
	gcc -c -g $(name).c

myavltree.o: $(lib).c $(lib).h
	gcc -c -g $(lib).c

gdb: 
	rm -rf $(name)
	gcc -g -o $(name) $(name).c
	gdb ./$(name)
	
clean:
	rm -rf $(name)

valgrind:
	valgrind ./$(name)
