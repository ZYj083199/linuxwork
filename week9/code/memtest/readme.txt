gcc memtest.c -o memtests
valgrind --track-fds=yes --leak-check=full --undef-value-errors=yes ./memtest
