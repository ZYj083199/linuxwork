fork.c中指针操作，资源指针不共享
vfork.c指针共享，vfork2.c因子程序没有关闭指针而出现与vfork.c结果不同
gcc fork.c -o fork
./fork
gcc vfork.c -o vfork
./vfork
gcc vfork2.c -o vfork2
./vfork2

