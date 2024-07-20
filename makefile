EXECUTAR = inserction.exe
OBJ = inserction.o
CC = gcc
CFLAGS = -Wall -lrt

SRCS = inserction.c

OBJS = $(SRCS:.c = .o)

all: $(EXECUTAR)

$(EXECUTAR): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTAR) $(OBJS)

%.o %.c
	$(CC) $(CFLAGS) -c $< -o $@

rm -f $(OBJS) $(EXECUTAR)