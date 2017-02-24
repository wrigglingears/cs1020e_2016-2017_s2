CC=g++
CFLAGS=-std=c++11 -Wall
FNAME=social
NTESTS=10

default:
	$(CC) $(CFLAGS) *.cpp -o _run

%:
	./_run* < input/$(FNAME)$@.in | diff output/$(FNAME)$@.out -; echo; echo $@ Tested!

test:
	for i in {1..$(NTESTS)}; do echo Testing $$i; ./_run* < input/$(FNAME)$$i.in | diff output/$(FNAME)$$i.out -; done; echo; echo all tested!

clean:
	rm _run*