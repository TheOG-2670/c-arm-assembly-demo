default_compile: #compile and link all files in a single command
	rm hello_world
	gcc -o hello_world hello_world.c add.S

step_compile: #compile each assembly and C file individual and then link the object files together into the binary
	as -o add.o add.S
	gcc -c hello_world.c
	gcc -o hello_world hello_world.o add.o 
