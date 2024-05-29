C = gcc
CFLAGS =-g -Wall -pedantic -ansi -Werror 
OBJ = random.o main.o game.o terminal.o display.o blocking.o goal.o lock.o readFile.o color.o linkedList.o
EXEC = escape


$(EXEC) : $(OBJ)
	        $(CC) $(OBJ) -o $(EXEC)

main.o : main.c game.h 
	        $(CC) -c main.c  $(CFLAGS)
game.o : game.c random.h terminal.h display.h goal.h lock.h game.h readFile.h linkedList.h 
	        $(CC) -c game.c  $(CFLAGS)
readFile.o : readFile.c readFile.h 
	        $(CC) -c readFile.c $(CFLAGS)	
color.o : color.c color.h 
	        $(CC) -c color.c $(CFLAGS)						
display.o : display.c display.h color.h
	        $(CC) -c display.c $(CFLAGS)	
order.o : random.c random.h 
	        $(CC) -c random.c $(CFLAGS)
terminal.o : terminal.c terminal.h 
	        $(CC) -c terminal.c $(CFLAGS)
blocking.o : blocking.c blocking.h random.h linkedList.h 
	        $(CC) -c blocking.c $(CFLAGS)
goal.o : goal.c goal.h 
	        $(CC) -c goal.c $(CFLAGS)
linkedList.o : linkedList.c linkedList.h 
	        $(CC) -c linkedList.c $(CFLAGS)					
lock.o : lock.c lock.h 
	        $(CC) -c lock.c $(CFLAGS)				
clean:
	        rm -f $(EXEC) $(OBJ)

