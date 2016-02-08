DOCC=doxygen
CXX = g++
CXXFLAGS = -Wall -g

REFDIR=.
SRCDIR=$(REFDIR)/src
DOCDIR=$(REFDIR)/doc
CSOURCE = $(SRCDIR)/main.cpp $(SRCDIR)/Dvector.cpp

all: doc 

$(DOCDIR)/html/documentation.html: $(DOCDIR)/Doxyfile $(CSOURCE) 
	$(DOCC) $(DOCDIR)/Doxyfile

doc: $(DOCDIR)/html/documentation.html

clean:
	rm -rf $(DOCDIR)
