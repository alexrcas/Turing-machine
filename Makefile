CC=g++ 
CXXFLAGS=-g

OBJS = main.o turing.o delta.o interface.o transition_t.o state.o infinite_tape.o

 all: ${OBJS}
	$(CC) $(CXXFLAGS) -o turing ${OBJS}

clean: 
	rm -rf *.o