test.c 
绑定signal函数查看其kill-n pid n的参数不同造成的效果
test2.c
利用sigaction结构体实现信号处理，打印字符串
gcc test.c -o test
./test
kill -1 pid
kill -2	pid
kill -3 pid
kill -9 pid
gcc test2.c -o test2
./test2

