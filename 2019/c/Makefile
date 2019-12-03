CC=gcc
LIBS = -lm
BINS= day1

DAY_BIN?=day1

OBJS = $(DAY_BIN).o aoc.o

$(DAY_BIN): $(OBJS)
	$(CC) -o $@ $^ -lm

clean:
	rm *.o

format: 
	astyle --style=kr --indent=spaces=4 --align-pointer=name --align-reference=name --convert-tabs --attach-namespaces --max-code-length=100 --max-instatement-indent=120 --pad-header --pad-oper $^

