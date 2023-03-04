/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:13:11 by aelarbid          #+#    #+#             */
/*   Updated: 2023/03/05 00:44:53 by aelarbid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#define W 13
#define A 0
#define D 2
#define S 1
#define LEFT 123
#define RIGHT 124

void map(t_parse *p)
{
    int j = 0;
    int i = 0;
    // printf("2**h:%d\nw:%d\n", p->game->hight, p->game->width);
     while (j < p->game->hight)
    {
        i = 0;
        while (i < p->game->width)
        {
            if (i%30 == 0)
                p->game->add[j * p->game->width + i] = 0xFFFFFF;
            else if (j%30 == 0)
                p->game->add[j * p->game->width + i] = 0xFFFFFF;
            else if (p->map_elmnt[j/30][i/30] == '1')
                p->game->add[j * p->game->width + i] = 0x646464;
            else
                p->game->add[j * p->game->width + i] = 0x000000;
            i++;
        }
        
        j++;
    }
}


void draw_player(t_parse *p)
{
    int scale = 4;
    int i = p->player.x - scale;
    int j = p->player.y - scale;

    while(j < (p->player.y + scale))
    {
        i = p->player.x - scale;
        while(i < (p->player.x + scale))
        {
            p->game->add[j * p->game->width + i] = 0x0000FF00;
            i++;
        }
        j++;
    }
    // p->game->add[(int)p->player.ydem * p->game->width * (int)p->player.xdem] = 0x0000FF00;
}

void DDA(t_parse *p, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - p->player.x;
    int dy = Y1 - p->player.y;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
 
    // Put pixel for each step
    float X = p->player.x;
    float Y = p->player.y;
    int j = 0;
    int k = 0;
    for (int i = 0; i <= steps; i++) {
        j = (int)round(Y);
        k = (int)round(X);
        if (j > p->game->hight)
            j = p->game->hight;
        if (k > p->game->width)
            k = p->game->width;
        p->game->add[j * p->game->width * k] = 0x00FFFF00;
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
        // delay(100); // for visualization of line-
                  // generation step by step
    }
}
 

// void draw_ang(t_parse *p)
// {
//     int i = 0;
//     int j = 0;
//     while (j < 5)
//     {
//         i = -1;
//         while (++i < 5)
//             p->game->add[((int)p->player.ydem + p->player.y + j) * p->game->width * ((int)p->player.xdem + p->player.x + i)] = 0x0000FF00;
        
//         j++;
//     }
    
// }


void check_wall(t_parse *p)
{
    int i = p->player.x / 30;
    int j = p->player.y / 30;

    if (p->map_elmnt[j][i] == '1')
    {
        p->player.x = p->player.xprev;
        p->player.y = p->player.yprev;
    }
}

void player(t_parse *p)
{
    draw_player(p);
    check_wall(p);
    // DDA(p, p->player.x + 5, p->player.y + 5);
    // draw_ang(p);
    //drawCircle(p);
}
int move(int key,t_parse *p)
{
    // int speed = 20;
    // printf("%d\n", key);
    // && p->map_elmnt[(int)(p->player.y + p->player.ydem) / 30][(int)(p->player.x + p->player.xdem) / 30] != '1'
    if(key == W )
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        p->player.x += p->player.xdem;
        p->player.y += p->player.ydem;
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
            
    }
    else if(key == S)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        p->player.x -= p->player.xdem;
        p->player.y -= p->player.ydem;
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    else if(key == D)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        p->player.x += cos(p->player.angle + PI/2) * 5;;
        p->player.y += sin(p->player.angle + PI/2) * 5;;
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    else if(key == A)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        p->player.x -= cos(p->player.angle + PI/2) * 5;;
        p->player.y -= sin(p->player.angle + PI/2) * 5;;
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    else if (key == LEFT)
    {
        p->player.angle -= 0.1;
        if (p->player.angle < 0)
            p->player.angle += 2 * PI;
        p->player.xdem = cos(p->player.angle) * 5;
        p->player.ydem = sin(p->player.angle) * 5;
    }
    else if (key == RIGHT)
    {
        p->player.angle += 0.1;
        if (p->player.angle > (PI * 2))
            p->player.angle -= 2 * PI;
        p->player.xdem = cos(p->player.angle) * 5;
        p->player.ydem = sin(p->player.angle) * 5;
    }
    return 0;
}

int	ft_close(int keycode, t_parse *p)
{
    printf("%d\n", keycode);
    if (keycode == 53)
    {
	    mlx_destroy_window(p->game->mlx, p->game->win);
	    exit(0);
    }
    else
        return 0;
}

int action(t_parse *p)
{
    mlx_clear_window(p->game->mlx, p->game->win);
    map(p);
    player(p);
    mlx_key_hook(p->game->win, move, p);
    mlx_hook(p->game->win, 2, 1L<<0, ft_close, p);
    mlx_put_image_to_window(p->game->mlx, p->game->win, p->game->img, 0, 0);
    return 0;
       
}


void init_mc(t_parse *p)
{
    int j =0;
    int i = 0;
    int stop = 0;
    while (!stop && p->map_elmnt[j] != NULL)
    {
        i = 0;
        while (p->map_elmnt[j][i] != '\0')
        {
            if (p->map_elmnt[j][i] == 'N' || p->map_elmnt[j][i] == 'S' || p->map_elmnt[j][i] == 'W' ||p->map_elmnt[j][i] == 'E' )
            {
                p->player.x = i * 30 + 15;
                p->player.y = j * 30 + 15;
                stop = 1;
                break;
            }   
            i++;
        }
        
        j++;
    }
    p->player.turn_direction = 0;
    p->player.walk_direction = 0;
    // p->player.rotatio = PI /2;
    p->player.speed = 3;
    if (p->n)
        p->player.angle = (PI * 3)/2;
    else if (p->s)
        p->player.angle = PI/2;
    else if (p->w)
        p->player.angle = PI;
    else if (p->e)
        p->player.angle = 0.0;
    
    printf("n: %d\ns: %d\ne: %d\nw: %d\n", p->n, p->s, p->e, p->w);
    // if (p.)
    p->player.rotation_speed = 3 * (PI / 180);
}


void    init_game(t_parse *parse)
{
    getWidth(parse);
    parse->game->mlx = mlx_init();
    parse->game->win = mlx_new_window(parse->game->mlx, parse->game->width
    ,parse->game->hight,"Cub3D");
    printf("1**h:%d\nw:%d\n", parse->game->hight, parse->game->width);
    parse->game->img = mlx_new_image(parse->game->mlx, parse->game->width,parse->game->hight);
    parse->game->add = (int *)mlx_get_data_addr(parse->game->img, &parse->game->bpp, &parse->game->len, &parse->game->end);
    init_mc(parse);
    mlx_loop_hook(parse->game->mlx, action, parse);
    mlx_loop(parse->game->mlx);
}