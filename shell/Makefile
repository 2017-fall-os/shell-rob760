all: shell

CFLAGS = -g -O2

shell:  shell.o
	cc -o shell shell.o

clean:
	rm -f *.o shell shell.exe

demo: shell
	./shell