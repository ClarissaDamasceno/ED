CC      = gcc
CFLAGS  = -g
RM      = rm -f


default: all

all: selection_insertion

Hello: selection_insertion.c
    $(CC) $(CFLAGS) -o selection_insertion selection_insertion.c

clean veryclean:
    $(RM) selection_insertion