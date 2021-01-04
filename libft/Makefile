TARGET = libft.a
HEADER = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

BSRCS = $(wildcard *lst*.c)
SRCS = $(filter-out $(BSRCS), $(wildcard *.c))
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c =.o)

all: $(TARGET)

$(TARGET): $(OBJS)
		$(AR) $@ $^

bonus: $(BOBJS) $(OBJS)
		$(AR) $(TARGET) $^

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(BOBJS)

fclean: clean
		$(RM) $(TARGET)

re: fclean all
