CFLAGS=-g -O3

all: tokenizer

tokenizer.o: tokenizer.h
uimain.o: tokenizer.h

tokenizer: tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
