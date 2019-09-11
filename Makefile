all: fake

fake: *.c *.h Makefile
	$(CC) *.c -o fake

clean:
	rm -f fake