SRCDIR=src
OUTDIR=bin
TARGET=$(OUTDIR)/main

all: main

# Link files

main: $(OUTDIR) $(OUTDIR)/main.o $(OUTDIR)/csv.o $(OUTDIR)/expenditure.o
	g++ -o $(TARGET) $(OUTDIR)/main.o $(OUTDIR)/csv.o $(OUTDIR)/expenditure.o

# Create object files

$(OUTDIR)/main.o: $(SRCDIR)/main.cpp
	g++ -c $(SRCDIR)/main.cpp -o $(OUTDIR)/main.o

$(OUTDIR)/csv.o: $(SRCDIR)/csv.cpp
	g++ -c $(SRCDIR)/csv.cpp -o $(OUTDIR)/csv.o

$(OUTDIR)/expenditure.o: $(SRCDIR)/expenditure.cpp
	g++ -c $(SRCDIR)/expenditure.cpp -o $(OUTDIR)/expenditure.o

# Create output directory
$(OUTDIR):
	mkdir $@

clean:
	rm -rf bin/