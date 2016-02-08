DOCC=doxygen
CXX = g++
CXXFLAGS = -Wall -g

REFDIR=.
SRCDIR=$(REFDIR)/src
DOCDIR=$(REFDIR)/docu
CSOURCE = $(SRCDIR)/main.cpp $(SRCDIR)/Dvector.cpp

all: doc 

$(DOCDIR)/html/documentation.html: $(DOCDIR)/Doxyfile $(CSOURCE) 
	$(DOCC) $(DOCDIR)/Doxyfile

docu: $(CSOURCE) 
	doxygen Doxyfile

clean:
	rm -rf $(DOCDIR)/html/
