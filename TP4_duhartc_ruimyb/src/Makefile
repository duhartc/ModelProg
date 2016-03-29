TESTS = main
OBJS = main.o
TEMP = Point.tpp Triangle.tpp Maillage.tpp
CXX = g++
CXXFLAGS = -Wall -Wextra -g


.PHONY : all clean check

all : $(TESTS)

$(TESTS) : $(OBJS) $(TEMP)
	$(CXX) $(CXXFLAGS) -o $@ $@.o

%.t : %.o $(TEMP)
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o : %cpp %h
	$(CXX) $(CXXFLAGS) -c $<

clean :
	-rm -f *.o $(TESTS)

