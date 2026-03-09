CC = gcc
CFLAGS = -Wall -Wextra -I hdr
LDFLAGS = -pthread -lrt
TARGETS = writer reader

all: $(TARGETS)

writer: src/writer.c hdr/shared_chat.h
	$(CC) $(CFLAGS) src/writer.c -o writer $(LDFLAGS)

reader: src/reader.c hdr/shared_chat.h
	$(CC) $(CFLAGS) src/reader.c -o reader $(LDFLAGS)

clean:
	rm -f $(TARGETS)

.PHONY: all clean