CC  = cc
INP = AL-Pyload-Creator
OUT = *.c
ARG = -g -Wall

all:
	$(CC) $(ARG) -o $(INP) $(OUT)
