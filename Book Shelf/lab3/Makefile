# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab3.zip lab3

#to compile the file lab3.c with the right tags
lab3: 
	gcc lab3.c -o lab3 -pedantic -ansi 

#to make a zip file with everything needed
lab3.zip: Makefile lab3.c
	zip lab3.zip Makefile lab3.c lab3.h lab3Readme
# so that a completely new compile of all items is required
clean:
	rm -rf *.o lab3 lab3.zip
