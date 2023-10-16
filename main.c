#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int file = open("file.txt", O_RDONLY);
    int i = 0;

    while (i != 4)
    {
        printf("La linea es:\n%s\n", get_next_line(file));
        i++;
    }
    close(file);

    return (0);
}