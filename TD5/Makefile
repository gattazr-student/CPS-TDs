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
EXECS=exo1 exo2 exo5

SRCS_0=exo1.c
OBJS_0=${SRCS_0:.c=.o}

SRCS_1=exo2.c
OBJS_1=${SRCS_1:.c=.o}

SRCS_2=exo5.c
OBJS_2=${SRCS_2:.c=.o}

#-------------------------------------------------
#                     LINKINGS
#-------------------------------------------------
all: $(EXECS)

exo1: $(OBJS_0)
	$(CC) $(CFLAGS) -o exo1 $(OBJS_0) $(LIBRARIES)

exo2: $(OBJS_1)
	$(CC) $(CFLAGS) -o exo2 $(OBJS_1) $(LIBRARIES)

exo5: $(OBJS_2)
	$(CC) $(CFLAGS) -o exo5 $(OBJS_2) $(LIBRARIES)

#-------------------------------------------------
#                   DEPENDENCIES
#-------------------------------------------------

#-------------------------------------------------
#                     CLEANING
#-------------------------------------------------
clean_exo1:
	rm -f exo1 $(OBJS_0)

clean_exo2:
	rm -f exo2 $(OBJS_1)

clean_exo5:
	rm -f exo5 $(OBJS_2)

clean: clean_exo1 clean_exo2 clean_exo5
