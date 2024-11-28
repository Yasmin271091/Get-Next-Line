/*#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main() {
    int fd;
    char *line;

    fd = open("archivo.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error al abrir el archivo");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}*/