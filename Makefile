CC = cc
SCDOC = scdoc

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
MANPREFIX = $(PREFIX)/share/man

CFLAGS = -g -Wall -Wextra

PROGRAM = pfork
OBJECTS = main.o pfork.o
HEADERS = pfork.h
MAN1_PAGES = pfork.1

INTERNAL_CFLAGS = -I. $(CFLAGS)

all: $(PROGRAM) $(MAN1_PAGES)

$(PROGRAM): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(OBJECTS): $(HEADERS)

clean:
	rm -rf $(PROGRAM) $(MAN1_PAGES) *.o

# user should first run make all
install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f $(PROGRAM) $(DESTDIR)$(BINDIR)
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	cp -f $(MAN1_PAGES) $(DESTDIR)$(MANPREFIX)/man1

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(PROGRAM)

.SUFFIXES: .c .o .scd
.c.o:
	$(CC) $(INTERNAL_CFLAGS) -c -o $@ $<

.scd:
	$(SCDOC) < $< > $@
