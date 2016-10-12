cc=gcc
numbers_obj= Numbers.o
files= Pipe_two.c Pipe.c Numbers.c makefile
#compile all programs
all:pipes

pipes: Pipe Pipe_two

Numbers.o: Numbers.c
	$(cc) -g -I. -c Numbers.c -o Numbers.o

Pipe: Pipe.c
	$(cc) -g -I. Pipe.c -o Pipe

Pipe_two: $(numbers_obj) Pipe_two.o
	$(cc) -g -I. $(numbers_obj) Pipe_two.o  -o Pipe_two

Pipe_two.o: Pipe_two.c 
	$(cc) -g -I. -c Pipe_two.c -o Pipe_two.o

clean:
	rm Pipe Pipe_two Numbers.o

git:
	git add $(files)

