cc = gcc
objects = hostp.o

hostp : $(objects)
	$(cc) -o hostp $(objects)

hostp.o : hostp.c 
	$(cc) -c hostp.c

clean :
	rm hostp $(objects)
