/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:13:11 by aelarbid          #+#    #+#             */
/*   Updated: 2023/03/03 21:18:44 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void map(t_parse *p)
{
    int j = 0;
    int i = 0;
     while (j < p->game->hight)
    {
        i = 0;
        while (i < p->game->width)
        {
            if (i%30 == 0)
                i++;
            else if (j%30 == 0)
                j++;
            if (p->map_elmnt[j/30][i/30] == '1')
                p->game->add[j * p->game->width + i] = 0x964B00;
            else if (p->map_elmnt[j/30][i/30] == 'N')
                p->game->add[j * p->game->width + i] = 0x0C0C0C;
            else
                p->game->add[j * p->game->width + i] = 0x646464;
            i++;
        }
        
        j++;
    }
}

void player(t_parse *p)
{
    int i = p->player.x;
    int j = p->player.y;

    p->game->add[j * p->game->width + i] = 0x0000FF00;
}

int action(t_parse *p)
{
    map(p);
    player(p);
    mlx_put_image_to_window(p->game->mlx, p->game->win, p->game->img, 0, 0);

    return 0;
       
}


void init_mc(t_parse *p)
{
    int j =0;
    int i = 0;
    while (p->map_elmnt[j] != NULL)
    {
        i = 0;
        while (p->map_elmnt[j][i] != '\0')
        {
            if (p->map_elmnt[j][i] == 'N' || p->map_elmnt[j][i] == 'S' || p->map_elmnt[j][i] == 'W' ||p->map_elmnt[j][i] == 'E' )
            {
                p->player.x = i * 30 + 15;
                p->player.y = j * 30 + 15;
                return ;
            }   
            i++;
        }
        
        j++;
    }
}
void    init_game(t_parse *parse)
{
    getWidth(parse);
    parse->game->mlx = mlx_init();
    parse->game->win = mlx_new_window(parse->game->mlx, parse->game->width
    ,parse->game->hight,"Cub3D");
    parse->game->img = mlx_new_image(parse->game->mlx, parse->game->width,parse->game->hight);
    parse->game->add = (int *)mlx_get_data_addr(parse->game->img, &parse->game->bpp, &parse->game->len, &parse->game->end);
    init_mc(parse);
    mlx_loop_hook(parse->game->mlx, action, parse);
    mlx_loop(parse->game->mlx);
}