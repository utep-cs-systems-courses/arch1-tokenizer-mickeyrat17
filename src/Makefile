CFLAGS=-g -O3

all: history

tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

history: tokenizer.o history.o uimain.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o history

run: history
	./history
