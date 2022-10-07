DEPS=Rectangle.h
OBJ=Rectangle.o main.o
CC=g++ -Wall
all: clean main run

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $<

main: $(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	del -f *.o *.exe

run:main
	./main





# DEPS=Rectangle.h
# OBJ=Rectangle.o main.o
# CC=g++
# CFLAGS=-c -Wall

# %.o: %.cpp $(DEPS)
# 	$(CC) -c -o $@ $<

# main: $(OBJ)
# 	$(CC) -o $@ $^
# clean:
# 	rm -f *.o main.exe



# main: main.o Rectangle.o # `main` depends on `main.o` and `Rectangle.o`
# # command to build `main` from `main.o` and `Rectangle.o`
# 	g++ -o main main.o Rectangle.o

# main.o: main.cpp Rectangle.h # `main.o` depends on `main.cpp` and `Rectangle.h`
# # command to build `main.o` from `main.cpp`
# 	g++ -c main.cpp

# Rectangle.o: Rectangle.cpp Rectangle.h # `Rectangle.o` depends on `Rectangle.cpp` and `Rectangle.h`
# # command to build `Rectangle.o` from `Rectangle.cpp`
# 	g++ -c Rectangle.cpp


