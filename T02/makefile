CC=g++
CFLAGS=-std=c++11 -Wall
TUT=T02
QNS=1 2 3

all: $(QNS)

%:
	$(CC) $(CFLAGS) $(TUT)_Q$@.cpp -o _run_$@

clean:
	rm _run_*