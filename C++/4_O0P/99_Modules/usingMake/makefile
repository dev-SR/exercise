all:mycar

mycar: main.o car.o
	g++ -Wall -o mycar main.o car.o

main.o: main.cpp
	g++ -c -Wall main.cpp

car.o: car.cpp
	g++ -c -Wall car.cpp

clean:
	rm car.o
	rm main.o