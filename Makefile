all: clean build

clean:
	rm -rf build

build:
	mkdir build || true
	gcc -o build/fork src/main.c src/daemon.c -O3 -s 

install:
	mkdir -p $(DESTDIR)/usr/bin
	install build/fork $(DESTDIR)/usr/bin/fork
