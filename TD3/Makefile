##################################################
#        Makefile automatically generated        #
# Brought to you by Jules HABLOT and Rémi GATTAZ #
##################################################

#-------------------------------------------------
#                    VARIABLES                    
#-------------------------------------------------
CC=gcc
CFLAGS=-g -Wall -pedantic
LIBRARIES=
EXECS=ex1 ex2 ex3 ex4 ex5

SRCS_0=ex1.c
OBJS_0=${SRCS_0:.c=.o}

SRCS_1=ex2.c
OBJS_1=${SRCS_1:.c=.o}

SRCS_2=ex3.c
OBJS_2=${SRCS_2:.c=.o}

SRCS_3=ex4.c
OBJS_3=${SRCS_3:.c=.o}

SRCS_4=ex5.c
OBJS_4=${SRCS_4:.c=.o}

#-------------------------------------------------
#                     LINKINGS                    
#-------------------------------------------------
all: $(EXECS)

ex1: $(OBJS_0)
	$(CC) $(CFLAGS) -o ex1 $(OBJS_0) $(LIBRARIES)

ex2: $(OBJS_1)
	$(CC) $(CFLAGS) -o ex2 $(OBJS_1) $(LIBRARIES)

ex3: $(OBJS_2)
	$(CC) $(CFLAGS) -o ex3 $(OBJS_2) $(LIBRARIES)

ex4: $(OBJS_3)
	$(CC) $(CFLAGS) -o ex4 $(OBJS_3) $(LIBRARIES)

ex5: $(OBJS_4)
	$(CC) $(CFLAGS) -o ex5 $(OBJS_4) $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES                  
#-------------------------------------------------

#-------------------------------------------------
#                     CLEANING                    
#-------------------------------------------------
clean_ex1: 
	rm -f ex1 $(OBJS_0)

clean_ex2: 
	rm -f ex2 $(OBJS_1)

clean_ex3: 
	rm -f ex3 $(OBJS_2)

clean_ex4: 
	rm -f ex4 $(OBJS_3)

clean_ex5: 
	rm -f ex5 $(OBJS_4)

clean: clean_ex1 clean_ex2 clean_ex3 clean_ex4 clean_ex5
