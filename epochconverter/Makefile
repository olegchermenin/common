CC = g++
SOURCES = main.cpp epochconverter.cpp epochconverter.h
EXECUTABLE = epochconverter

all: $(EXECUTABLE)

$(EXECUTABLE): main.o epochconverter.o
	$(CC) main.o epochconverter.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) -c main.cpp

epochconverter.o: epochconverter.cpp epochconverter.h
	$(CC) -c epochconverter.cpp

clean:
	rm -rf *.o $(EXECUTABLE)
