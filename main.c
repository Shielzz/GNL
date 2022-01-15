#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int     fd = open("test", O_RDONLY);
    char    buffer[BUFFER_SIZE + 1];
    int     ret = read(fd, buffer, BUFFER_SIZE);
    char    *str = get_next_line(fd);



    printf("%d\n", fd);
    printf("%d", ret);
    printf("%s", str);
    printf("\n");
    return(0);
}
