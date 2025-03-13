
#include "so_long.h"

static char **copy_map(t_game *game)
{
    int i;
    char **map_cpy;

    map_cpy = (char **)malloc(game->height * sizeof(char *));
    if (!map_cpy)
        return (NULL);
    i = 0;
    while (i < game->height)
    {
        map_cpy[i] = ft_strdup(game->map[i]);
        if (!map_cpy[i])
            return (error_map(map_cpy),NULL);
        i++;
    }
    return map_cpy;
}

static void player_position(t_game *game)
{
    int i;
    int j;
    i = 1;
    while (i < game->height - 1)
    {
        j = 1;
        while (j < game->width - 1)
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = i;
                game->player_y = j;
                return;
            }
            j++;
        }
        i++;
    }
}

static void flood_fill(t_game *game, char **map, int x, int y)
{
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '1' || map[y][x] == 'F')
        return;    
    map[y][x] = 'F';
    if (map[y][x] == 'C') 
        game->count++; 
    if (map[y][x] == 'E') 
    {
        game->exit_count = 2;
        return;
    }
    flood_fill(game, map, x - 1, y);
    flood_fill(game, map, x + 1, y);
    flood_fill(game, map, x , y - 1);
    flood_fill(game, map, x, y + 1);
}

void flood_fill_controller(t_game *game)
{
    char **new_map;
    new_map = copy_map(game);
    if (!new_map)
        return(error_game(game));
    player_position(game);
    game->count = 0;
    flood_fill(game, new_map, game->player_x, game->player_y);
    if (game->exit_count != 2 || game->count != game->collectibles)
    {
        error_game(game);
        error_map(new_map);
    }
    free(new_map);
}
