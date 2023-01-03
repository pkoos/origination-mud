all:
	g++ -std=c++20 -o orig.o origination.cpp MudServer.cpp MudEntity.cpp

clean:
	rm *.o
run:
	./orig.o

tests:
	g++ -std=c++20 -o Tests.o MudEntity.cpp MudEntity.test.cpp
