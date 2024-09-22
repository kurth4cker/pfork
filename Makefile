CC = cc

PREFIX = /usr/local

all: clean build

clean:
	rm -rf build

build:
	mkdir -p build
	$(CC) -o build/libpfork.so -shared src/pfork.c -fPIC
	$(CC) -o build/pfork src/main.c -Isrc -O3 -s -Lbuild -lpfork

install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install build/pfork $(DESTDIR)$(PREFIX)/bin/pfork
	install build/libpfork.so $(DESTDIR)$(PREFIX)/lib/libpfork.so.1
	ln -sf ./libpfork.so.1 $(DESTDIR)$(PREFIX)/lib/libpfork.so
	install src/pfork.h $(DESTDIR)$(PREFIX)/include/pfork.h
