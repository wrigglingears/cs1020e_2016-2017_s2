CC=g++
CFLAGS=-std=c++11 -Wall
TUT=T04
QNS=1 2 4

all: $(QNS)
	echo All made!

%:
	$(CC) $(CFLAGS) $(TUT)_Q$@.cpp -o _run$@

clean:
	rm _run*