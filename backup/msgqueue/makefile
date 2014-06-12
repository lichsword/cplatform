##########################################
# '#': comments
# ':': dependency
##########################################
PROJ = msgqueue

C = gcc
OUT = -o
#paths
#LIBS = -framework OpenGl -framework GLUT
LIBS = 
INCLUDE = -I /usr/include/nptl 
#/usr/include/ncurses
#LINK = -L /usr/lib/nptl -lcurses
LINK = -lcurses -lsqlite3
MACRO = -D _REENTRANT

# 1:enable 0:disable
DEBUG = 1
# debug flag: -g
DFLAG = -g
#OBJS = $(PROJ).o $(LOG).o $(MOD).o
OBJS = $(PROJ).o
# -D name=definition
#cc -D _REENTRANT -I /usr/include/nptl thread1.c -o thread1 -L /usr/lib/nptl -l pthread
# link
$(PROJ):$(OBJS)
	$(CC) $(DFLAG) $(MACRO) $(OUT) $(PROJ) $(OBJS) $(LIBS) $(LINK)
#build
$(PROJ).o:$(PROJ).c
	$(CC) $(DFLAG) -c $(PROJ).c
#$(LOG).o:$(LOG).c $(COM).h
#	$(CC) $(DFLAG) -c $(LOG).c
#$(MOD).o:$(MOD).c $(LOG).h $(COM).h
#	$(CC) $(DFLAG) -c $(MOD).c
clean:
	rm *.o $(PROJ)
