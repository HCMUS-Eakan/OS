#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int value;
    int fd;
    fd = open("/dev/random", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open character device file!");
        return -1;
    }
    read(fd, &value, sizeof(value));
    printf("Random 4-byte integer generated by character device: %d\n", value);
    close(fd);
    return 0;
}
