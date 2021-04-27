CC=gcc

CFLAGS=-Wall -Wextra -pedantic -fstack-protector-all -pedantic -std=c99
SANITY_FLAGS=-Wfloat-equal -Wshadow -Wpointer-arith

PREFIX ?= /usr

SOURCE=test.c parse.c strings.c

OUTPUT=parse

ALL: $(OUTPUT)

debug: CFLAGS += -g -O0
debug: $(OUTPUT)

release: CFLAGS += -static -O3
release: $(OUTPUT)

$(OUTPUT): Makefile $(SOURCE)
	$(CC) $(CFLAGS) $(SANITY_FLAGS) $(SOURCE) -o $(OUTPUT)

.PHONY:watch
watch: parse
	while true; do \
		clear; \
		(make parse && ./parse) || true; \
		inotifywait -qe modify ./parse.c ./test.c; \
	done
