C = gcc
CFLAGS = -Wall -std=gnu99 -pedantic
MAIN = run
OBJS = main.c data.c support.c
all : $(MAIN)

$(MAIN) : $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

clean :
	rm *.o $(MAIN) core
