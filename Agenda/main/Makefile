
# Author: Julio Conchas
# Email:  conchasjimenez@gmail.com
# Path:   main/
# File:   MakeFile

OBJETOS=main.o \
	     menu.o \
		  personlist.o \
		   node.o \
		    persona.o
	 # agentemenu.o \
	 #  cliente.o \
	 #   agente.o \
	 #    customtime.o \
	 #     customdate.o \
	 #      nodecliente.o \
		#    nodeagente.o \
		#     clientelist.o \
		# 	 agentelist.o \
		# 	  loggin.o \
		# 	   user.o

CFLAGS=-I../libs
COMPILER=c++ -c -g

practicauno: $(OBJETOS)
	c++  $(OBJETOS) -o practicauno

menu.o: ../libs/menu.cpp
	$(COMPILER) ../libs/menu.cpp -o menu.o

personlist.o: ../libs/personlist.cpp
	$(COMPILER) ../libs/personlist.cpp -o personlist.o

node.o: ../libs/node.cpp
	$(COMPILER) ../libs/node.cpp -o node.o

persona.o: ../libs/persona.cpp
	$(COMPILER) ../libs/persona.cpp -o persona.o

main.o: main.o ../libs/menu.h
	$(COMPILER)  $(CFLAGS) main.cpp -o main.o

#utility targets
run:
	make clean
	./practicauno
clean:
	rm -Rf *.o
