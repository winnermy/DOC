#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "apue.h"

int main()
{
    int n, w, i;
    char *buf = "abc";

    n = open("abc", O_WRONLY|O_CREAT, 0666);
    if (n == -1)
        err_sys("open error");
    for(i = 0; i < 1468802; i++) {
        w = write(n, buf, 1);
        if (w != 1)
            err_sys("write error");
        }

    exit(0);
}
