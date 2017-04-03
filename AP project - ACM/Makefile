all: compile


compile: main.cpp feature_model.o
	g++ main.cpp feature_model.o node.o alternative_node.o mandatory_node.o optional_node.o or_node.o sample_node.o -o ACM

feature_model.o: feature_model.cpp feature_model.h node.o
	g++ -c feature_model.cpp

node.o: node.cpp node.h alternative_node.o mandatory_node.o optional_node.o or_node.o sample_node.o
	g++ -c node.cpp

alternative_node.o: alternative_node.cpp alternative_node.h
	g++ -c alternative_node.cpp

mandatory_node.o: mandatory_node.cpp mandatory_node.h
	g++ -c mandatory_node.cpp

optional_node.o: optional_node.cpp optional_node.h
	g++ -c optional_node.cpp

or_node.o: or_node.cpp or_node.h
	g++ -c or_node.cpp

sample_node.o: sample_node.cpp sample_node.h
	g++ -c sample_node.cpp



gdb:
	g++ *.cpp -g -std=c++11

clean:
	rm *.o ACM a.out

run:
	./ACM < input
