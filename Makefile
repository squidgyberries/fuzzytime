CC = cc
override CFLAGS += -std=c17 -Wall

fuzzytime: fuzzytime.c
	${CC} -o fuzzytime fuzzytime.c ${CFLAGS}

clean:
	rm fuzzytime

install: fuzzytime
	mkdir -p /usr/local/bin
	cp fuzzytime /usr/local/bin
	chmod 755 /usr/local/bin/fuzzytime

uninstall:
	rm -f /usr/local/bin/fuzzytime