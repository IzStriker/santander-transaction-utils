SRCDIR=src
OUTDIR=bin
TARGET=$(OUTDIR)/main

all: main

# Link files

main: $(OUTDIR) $(OUTDIR)/main.o
	g++ -o $(TARGET) $(OUTDIR)/main.o

# Create object files

$(OUTDIR)/main.o: $(SRCDIR)/main.cpp
	g++ -c $(SRCDIR)/main.cpp -o $(OUTDIR)/main.o

# Create output directory
$(OUTDIR):
	mkdir $@

clean:
	rm -rf bin/