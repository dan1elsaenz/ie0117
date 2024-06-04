CC = gcc
CFLAGS = -Wall

SRCS = double_list.c main.c
OBJS = $(SRCS:.c=.o)

TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)
