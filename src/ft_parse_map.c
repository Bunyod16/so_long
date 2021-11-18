#include "../so_long.h"

int map_rectangle(char *map)
{
    char    *buf;
    int     len;
    int     temp;
    int     fd;

    buf = malloc(sizeof(char *) * 2);
    fd = open(map, O_RDONLY);
    len = 0;
    while (read(fd, buf, 1) > 0)
    {
        if (*buf == '\n')
            break;
        len++;
    }
    temp = 0;
    while (read(fd, buf, 1) > 0)
    {
        if (*buf == '\n')
        {
            if (temp == len)
                len = 0;
            else
                return 0;
        }
        temp++;
    }
    return (1);
}

int ft_parse_map(int argc, char **argv)
{
    int     fd;
    char    *buf;

    if (map_rectangle(argv[1]) == 0 || argc != 2)
        return 0;
    printf("passed");
    buf = malloc(sizeof(char *) * 2);
    fd = open(argv[1], O_RDONLY);
    while (read(fd, buf, 1) > 0)
    {
        printf("%c",*buf);
    }
    return (1);
}
