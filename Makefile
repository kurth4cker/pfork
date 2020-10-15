all: clean build

clean:
	rm -rf build

build:
	mkdir build || true
	gcc -o build/libpfork.so -shared src/pfork.c -fPIC
	gcc -o build/pfork src/main.c -Isrc -O3 -s -Lbuild -lpfork

install:
	mkdir -p $(DESTDIR)/usr/bin
	install build/pfork $(DESTDIR)/usr/bin/pfork
	install build/libpfork.so $(DESTDIR)/usr/lib/libpfork.so.1
	ln -s libpfork.so.1 $(DESTDIR)/usr/lib/libpfork.so || true
	install src/pfork.h $(DESTDIR)/usr/include/pfork.h
