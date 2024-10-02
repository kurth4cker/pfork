CC = cc

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

CFLAGS = -g -Wall -Wextra

PROGRAM = pfork
OBJECTS = main.o pfork.o
HEADERS = pfork.h

INTERNAL_CFLAGS = -I. $(CFLAGS)

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS): $(HEADERS)

clean:
	rm -rf $(PROGRAM) *.o

# user should first run make all
install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(PROGRAM) $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(PROGRAM)

.SUFFIXES: .c .o
.c.o:
	$(CC) $(INTERNAL_CFLAGS) -c -o $@ $<
