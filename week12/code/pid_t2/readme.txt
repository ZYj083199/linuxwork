fork.c
查看在只能写不能读的情况下，linux对程序的处理




pid_t.c
三个子进程对一个文件进行写入，查看其共享文件指针的共享情况
gcc pid_t.c -o pid_t
./pid_t
more test.txt
