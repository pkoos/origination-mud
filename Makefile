all:
	g++ -std=c++20 -o MudExec.o main.cpp MudServer.cpp MudEntity.cpp

clean:
	rm *.o
run:
	./MudExec

tests:
	g++ -std=c++20 -o Tests.o MudEntity.cpp MudEntity.test.cpp
