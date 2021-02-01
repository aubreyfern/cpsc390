BUILD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
OUT = *.out

all: aubreyfernando_assignment2.out

input.o: Makefile input.cpp
	$(CC) $(BUILD_FLAGS) -c input.cpp -o input.o

manhattan.o: Makefile manhattan.cpp
	$(CC) $(BUILD_FLAGS) -c manhattan.cpp -o manhattan.o

euclidean.o: Makefile euclidean.cpp
	$(CC) $(BUILD_FLAGS) -c euclidean.cpp -o euclidean.o

gh.o: Makefile gh.cpp
	$(CC) $(BUILD_FLAGS) -c gh.cpp -o gh.o

aubreyfernando_assignment2.out: Makefile input.o manhattan.o euclidean.o gh.o main.cpp
	$(CC) $(BUILD_FLAGS) input.o manhattan.o euclidean.o gh.o main.cpp -o aubreyfernando_assignment2.out

clean:
	$(RM) $(OUT)
