compile:
	gcc -o signal signal.c

run: signal
	./signal

clean:
	rm signal
	rm *~
