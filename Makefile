all: clean build

clean:
	rm -rf build

build:
	mkdir build || true
	gcc -o build/pfork src/main.c src/daemon.c -O3 -s 

install:
	mkdir -p $(DESTDIR)/usr/bin
	install build/pfork $(DESTDIR)/usr/bin/pfork
