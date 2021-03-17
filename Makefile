CXX = g++
CXXFLAGS=-g -std=c++11 -Wconversion -Wshadow -pedantic -I .

BINARIES = testP1 testP2

all: ${BINARIES}

testP1: testP1.o bst.o
	${CXX} ${CXXFLAGS} -o $@ $^ -lgtest -lgtest_main -lpthread

testP2: testP2.o matrix.o
	${CXX} ${CXXFLAGS} -o $@ $^ -lgtest -lgtest_main -lpthread

clean: 
	rm -rf ${BINARIES} *.o

run:
	./testP1
	./testP2