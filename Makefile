CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -L/usr/X11R6/lib -lXext -lX11 -lm -D BUFFER_SIZE=45
SRC = file_1.c file_2.c file_3.c file_4.c file_5.c file_6.c file_7.c get_next_line/*.c printf/*.c
EXEC = test

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXEC)

re: clean all