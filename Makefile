

CC=clang
CFLAGS=-g -Wall
BIN=prog
BINDIR=bin
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

TEST=tests
TESTS=$(wildcard $(TEST)/*.c)
TESTOBJS=$(filter-out $(OBJ)/main.o, $(OBJS))
TESTBINS=$(patsubst $(TEST)/%.c, $(TEST)/bin/%, $(TESTS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(BINDIR)/$@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.c
	$(CC) $(CFLAGS) -I/opt/homebrew/include -L/opt/homebrew/lib $< $(TESTOBJS) -o $@ -lcriterion

$(OBJ):
	mkdir $@

$(BINDIR):
	mkdir $@

$(TEST)/bin:
	mkdir $@

test: $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	rm -r $(BINDIR)/* $(OBJ)/* $(TEST)/bin/* 
