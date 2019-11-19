test.c为ppt源代码可能因printf的问题无法将字符串一二全部读出
test2.c为改进版，可全部读出字符串一二
gcc test.c -o test
./test
gcc test2.c -o test2
./test2
work.c验证管道的最大缓存数量
