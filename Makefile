CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared -ldl

TARGET = ragemp-conf-override.so

SRC = src/ragemp-conf-override.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
