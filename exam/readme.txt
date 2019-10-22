gcc -rdynamic -o dynamiclibtest dynamiclibtest.c -ldl -I../dynamiclib
./dynamiclibtest
gcc -o staticlibtest staticlibtest.c ../dynamiclib/libdylib.so -I../dynamiclib
./staticlibtest
