# C++ build/dev system example.

This is a minimalistic example of how I manage a C++ project. I tend to have a
makefile in the main directory, which neatly handles build binaries and objects,
and I also tend to create helper scripts (e.g. valgrind.sh) with which to do
extended profiling (on top of your basic static analysis and gdb, say).

The particular example in this project is one of a handler class managing it's
associated clients, with a facility for message passing between clients and
handler. It's not intended to be particularly big or clever, but it stands as
an example of forward declaration that I often mess up.

I've put this here so that I can re-use it next time I have to do a quick test
in C++, and so that others may also get something useful from it.
