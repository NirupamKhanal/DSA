CC=gcc
CFLAGS =-g -Wall
BINS=Tries

all: $(BINS)

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	$(RM) -r $(BINS) *.dSYM