# pfork
Daemonize given program. Detach from terminal.

## Building

### Requirements
**pfork** is a simple project. You need:

* A C99 compiler
* POSIX make
* [scdoc][] (optional, for man page generation)

Standard makefile. Here are some installation examples

    # compile and install
    make
    make install

    # compile with optimization
    make CFLAGS=-O2

    # compile only binary (if you don't want manpage)
    make pfork

    # you can set some variables. like PREFIX, BINDIR
    make PREFIX=/usr install

## Copying
License under GPL-3.0-or-later. See file LICENSE for details.

## History
Created by [sulincix][]. Forked and redesigned by [kurth4cker][].

[sulincix]: https://gitlab.com/sulincix/fork
[kurth4cker]: https://gitlab.com/kurth4cker/pfork
[scdoc]: https://sr.ht/~sircmpwn/scdoc
