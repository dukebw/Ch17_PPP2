#
# A simple makefile for compiling C++ programs

CXXFLAGS = -std=c++11 -Wall
CXX = g++
SOURCES = Ex3_to_lower.cpp
OBJS = ${SOURCES:.cpp=.o}
TARGETS = Ex3_to_lower

$(TARGETS) : $(OBJS)
	$(CXX) -o $(TARGETS) $(OBJS)

# A rule to build .o file out of a .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# A rule to clean all the intermediates and targets
clean:
	rm -rf $(TARGETS) $(OBJS)
