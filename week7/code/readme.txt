gcc forktest.c -o forktest
./forktest
./forktest > temp
gcc simplefork.c -o simplefork
./simplefork
gcc test3.c -o test3
./test3
