#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int file = open(argv[1], O_RDONLY);
    int i = 0;

    char *data;

    while ((data = get_next_line(file)))
    {
        printf("La linea es:\n%s\n", data);
        free(data);
        i++;
    }
    close(file);

    return (0);
}