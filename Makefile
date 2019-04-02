CFLAGS=-Wall -Wextra --pedantic -g

ceesv: src/ceesv.c
	cc $(CFLAGS) src/ceesv.c -o ceesv
