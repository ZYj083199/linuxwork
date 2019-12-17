#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <wait.h>
#include <pthread.h>
#include <limits.h>
#include <semaphore.h>
#define LOOP 10000000
#define NUM 4
#define TN 100
#define WRITER_FIRST
