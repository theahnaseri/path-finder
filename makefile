CXX = gcc
CXX_FLAGS =

BIN = bin
SRC = src
INCLUDE = include
LIBRARIES =

EXECUTABLE = main

all: release

release: clean $(SRC)/*.c
	@echo Building for $(OS) ...
	mkdir $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $(SRC)/*.c -o $(BIN)/$(EXECUTABLE) $(LIBRARIES)

debug: clean $(SRC)/*.c
	@echo Debuging for $(OS)
	mkdir $(BIN)
	$(CXX) $(CXX_FLAGS) -g -I$(INCLUDE) $(SRC)/*.c -o $(BIN)/$(EXECUTABLE) $(LIBRARIES)

release_2: main.o grid.o algorithms.o
	gcc -o main main.o grid.o algorithms.o

main.o: src/main.c src/grid.h src/algorithms.h
	gcc -c src/main.c

grid.o: src/grid.c src/grid.h
	gcc -c src/grid.c

algorithms.o: src/algorithms.c src/algorithms.h
	gcc -c src/algorithms.c
	

clean:
	@echo Cleaning up ...
	rm -f $(BIN)/*
	rm -rf $(BIN)
