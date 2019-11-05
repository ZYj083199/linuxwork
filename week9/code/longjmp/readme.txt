lonjum.c中进行O2优化后能执行压栈操作，结果会不同
gcc longjmp.c -o longjmp
./longjmp
gcc longjmp2.c -o longjmp2 -Wall -O2
./longjmp2
