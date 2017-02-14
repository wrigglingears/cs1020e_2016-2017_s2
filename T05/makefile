CC=g++
CFLAGS=-std=c++11 -Wall
TUT=T5
QNS=1 2 3

all: $(QNS)
	echo All made!

%:
	$(CC) $(CFLAGS) $(TUT)_Q$@.cpp -o _run$@

clean:
	rm _run*