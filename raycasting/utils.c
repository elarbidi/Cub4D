#include "../cub3d.h"

void    screendiam(t_parse *parse);



void getWidth(t_parse *parse)
{
    int i;
    int biglen;
    int len;
    char    **str = parse->map_elmnt;

    biglen = 0;
    i = 0;
    while(str[i])
    {
        len = ft_strlen(str[i]);
        if(len > biglen)
            biglen = len;
        i++;    
    }
    parse->game = malloc(sizeof(t_game));
    parse->game->width = biglen * 64;
    parse->game->hight = i * 64;
}
