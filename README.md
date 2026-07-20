# ARCHIVAL NOTE
Project is moved back to where it started first. See:
https://gitlab.com/kurth4cker/pfork

# pfork
Daemonize given program. Detach from terminal.

## Building

### Requirements
**pfork** is a simple project. You need:

* A C99 compiler
* [scdoc][] (optional, for man page generation)

```
    # Bootstrap build system
    cc -o nob nob.c

    # Build **pfork** and it's man page
    ./nob
```

## Copying
License under GPL-3.0-or-later. See file LICENSE for details.

## History
Created by [sulincix][]. Forked and redesigned by [kurth4cker][].

[sulincix]: https://gitlab.com/sulincix/fork
[kurth4cker]: https://gitlab.com/kurth4cker/pfork
[scdoc]: https://sr.ht/~sircmpwn/scdoc
