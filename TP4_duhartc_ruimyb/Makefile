DOCC=doxygen
CXX = g++
CXXFLAGS = -Wall -g

REFDIR=.
SRCDIR=$(REFDIR)/src
DOCDIR=$(REFDIR)/docu
CSOURCE = $(SRCDIR)/main.cpp $(SRCDIR)/Dvector.cpp
PROG =$(SRCDIR)/Dvector
OBJS = $(SRCDIR)/Dvector.o $(SRCDIR)/main.o

all: docu check 

$(SRCDIR)/Dvector: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(DOCDIR)/html/documentation.html: $(DOCDIR)/Doxyfile $(CSOURCE) 
	$(DOCC) $(DOCDIR)/Doxyfile

check: $(SRCDIR)/Dvector

doc: $(CSOURCE) 
	doxygen Doxyfile

clean:
	rm -rf $(DOCDIR)/html/* $(SRCDIR)/*.o $(PROG)
