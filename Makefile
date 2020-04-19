#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=accumulate.hpp cycle.hpp filter_false.hpp permutation.hpp zip_longest.hpp
OBJECTS=
# NOTE: there are no objects -- all code is in the header files, since this is template code! 

run: test
	./$^

test: TestRunner.o Test1.o Test2.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test
