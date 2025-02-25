#include <fcntl.h>
#include <stdlib.h> 
#include <stdio.h> 
#include "so_long.h"

char    **read_map(char *file)
{
    int i;
    int fd;
    char *line;
    char **map;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;
    i = 0;    
    while (line = get_next_line(fd))
    {
        i++;
        free(line);
    }
    close(fd);
    map = malloc(i * sizeof(char *));
    if (!map)
        return NULL;
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (free(map),NULL);  
    i = -1;
    while (line = get_next_line(fd))
        map[++i] = line;
    return map, close(fd);   
}
int is_rectangular(char **map)
{
    int i;
    
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != strlen(map[0]))
            return (0); 
        i++;
    }
    return (1);
}


