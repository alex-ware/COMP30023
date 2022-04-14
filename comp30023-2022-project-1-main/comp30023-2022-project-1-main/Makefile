CC = gcc
CFLAGS = -Wall
LDFLAGS = -lpthread
EXE_DETECT = detect 


all: $(EXE_DETECT)

detect: detect.c 
		$(CC) $(CFLAGS) -o $(EXE_DETECT) $<

%.o: %.c %.h
		$(CC) -c -o $@ $< $(CFLAGS)

clean:
		rm -f *.o $(EXE_DETECT)

format:
	clang-format -i *.c *.h
