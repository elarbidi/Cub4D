/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:13:11 by aelarbid          #+#    #+#             */
/*   Updated: 2023/03/09 01:57:39 by aelarbid         ###   ########.fr       */
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

void dda(t_parse *p, int x_start, int x_end, int y_start, int y_end, int colors)
{
    int dx = x_end - x_start;
    int dy = y_end - y_start;
 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
 
    float xbegin = (float)x_start;
    float ybegin = (float)y_start;
    int i = 0;
    while (i < steps) {
        if (ybegin > p->game->hight)
            ybegin = p->game->hight;
        if (xbegin > p->game->width)
            xbegin = p->game->width;
        p->game->add[(int)ybegin * p->game->width + (int)xbegin] = colors;
        xbegin += x_inc;
        ybegin += y_inc;
        i++;
    }
}
 


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

void    draw_ver(t_parse *p, float ang)
{
    p->player.vflag = 0;
    float   rx = 0, ry = 0, ra = 0, xo = 0, yo = 0;
    int     mx = 0, my = 0, mp = 0, dof = 0;

    if (ang > 2 * PI)
        ang -= 2 * PI;
    if (ang < 0)
        ang += 2 * PI;
    ra = ang;
    dof = 0;
    float atan = -tan(ra);
    if (ra > (PI / 2) && ra < (3 * PI / 2))
    {
        rx = (int)(p->player.x/30) * 30 - 0.0001;
        ry = (p->player.x - rx) * atan + p->player.y;
        xo = -30;
        yo = -xo * atan;
    }
    else if (ra < (PI / 2) || ra > (3 * PI / 2))
    {
        rx = (int)(p->player.x/30) * 30 + 30;
        ry = (p->player.x - fabsf(rx)) * atan + p->player.y;
        xo = 30;
        yo = -xo * atan;
    }
    else if (ra == (PI / 2) || ra == (3 *PI / 2))
    {
        ry = p->player.y;
        rx = p->player.x;
        dof = 18;
    }
    while (dof<18)
    {
        mx = (int)(rx)/30;
        my = (int)(ry)/30;
        mp = my * p->game->width + mx;
        // printf("x==>[%d/%d]\ny==>[%d/%d]\n", mx, (p->game->width/30), my, (p->game->hight/30));
        if (my < 0 || mx < 0 || my >= (p->game->hight/30) || mx >= (p->game->width/30))
            break;
        if ( mp > 0 && mp < p->game->width * p->game->hight && p->map_elmnt[my][mx] == '1')
        {
            p->player.vflag = 1;
            dof = 18;
        }
        else
        { 
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }
    p->player.vx = rx;
    p->player.vy = ry;
}

void    draw_hor(t_parse *p, float ang)
{
    float   rx, ry, ra, xo, yo;
    int mx, my, mp, dof;

    if (ang > 2 * PI)
        ang -= 2 * PI;
    if (ang < 0)
        ang += 2 * PI;
    p->player.hflag = 0;
    ra = ang;
    // if (ang > PI/6)
    //     ra = p->player.angle - ang;
    // else
    //     ra = p->player.angle + ang;
    dof = 0;
    float atan = -1/tan(ra);
    if (ra > PI && ra < 2 * PI)
    {
        ry = (int)(p->player.y/30) * 30 - 0.0001;
        rx = (p->player.y - ry) * atan + p->player.x;
        yo = -30;
        xo = -yo * atan;
    }
    else if (ra < PI && ra > 0.0)
    {
        ry = (int)(p->player.y/30) * 30 + 30;
        rx = (p->player.y - ry) * atan + p->player.x;
        yo = 30;
        xo = -yo * atan;
    }
    else if (ra == 0.0 || ra == PI)
    {
        ry = p->player.y;
        rx = p->player.x;
        dof = 18;
    }
    while (dof<18)
    {
        mx = (int)(rx)/30;
        my = (int)(ry)/30;
        mp = my * p->game->width + mx;
        if (my < 0 || mx < 0 || my >= (p->game->hight/30) || mx >= (p->game->width/30))
            break;
        if ( mp > 0 && mp < p->game->width * p->game->hight && p->map_elmnt[my][mx] == '1')
        {
            p->player.hflag = 1;
            dof = 18;
        }
        else
        { 
            rx += xo;
            ry += yo;
            dof += 1;
        }
    }

    p->player.hx = rx;
    p->player.hy = ry;
}

void ft_shortest(t_parse* p)
{
    int colors = 0x6E6259;
    
    float h = sqrt(pow(p->player.x - p->player.hx, 2.0) + pow(p->player.y - p->player.hy, 2.0));
    float v = sqrt(pow(p->player.x - p->player.vx, 2.0) + pow(p->player.y - p->player.vy, 2.0));
    if (p->player.vflag == 0)
        v = 12212155.0;
    if (p->player.hflag == 0)
        h = 12212155.0;
    if (v < h)
    {
        p->player.px = p->player.vx;
        p->player.py = p->player.vy;
        colors = 0xFFFF00;
    }
    else
    {
        p->player.px = p->player.hx;
        p->player.py = p->player.hy;
        colors = 0xFFFF00;
    }
    dda(p, p->player.x, p->player.px, p->player.y, p->player.py, colors);
}

void player(t_parse *p, float ang)
{
    draw_player(p);
    check_wall(p);
    draw_hor(p, ang);
    draw_ver(p, ang);
    ft_shortest(p);
}


int move(int key,t_parse *p)
{
    if(key == W )
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        
        if (p->player.angle == 0.0)
            p->player.y -= 5;
        else
        {
            p->player.x += p->player.xdem;
            p->player.y += p->player.ydem;
        }
        
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
            
    }
    else if(key == S)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        
        if (p->player.angle == 0.0)
            p->player.y += 5;
        else
        {
            p->player.x -= p->player.xdem;
            p->player.y -= p->player.ydem;
        }
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    else if(key == D)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        
        p->player.xdem = cos(p->player.angle + PI/2) * 5;
        p->player.x += p->player.xdem;
        p->player.ydem = sin(p->player.angle + PI/2) * 5;
        p->player.y += p->player.ydem;
        
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    else if(key == A)
    {
        p->player.xprev = p->player.x;
        p->player.yprev = p->player.y;
        
        p->player.xdem = cos(p->player.angle + PI/2) * 5;
        p->player.x -= p->player.xdem;
        p->player.ydem = sin(p->player.angle + PI/2) * 5;
        p->player.y -= p->player.ydem;
        
        if (p->player.x >= p->game->width)
            p->player.x = p->player.xprev;
        if (p->player.y >= p->game->hight)
            p->player.y = p->player.yprev;
    }
    if (key == LEFT)
    {
        p->player.angle -= 0.1;
        if (p->player.angle < 0)
            p->player.angle += 2 * PI;
        p->player.xdem = cos(p->player.angle) * 5;
        p->player.ydem = sin(p->player.angle) * 5;
    }
    if (key == RIGHT)
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
    map(p);
    float ra = p->player.angle - FOV;
    int x = 0;
    while (x < p->game->width)
    {
        if (ra > 2*PI)
            ra -= 2*PI;
        if (ra < 0)
            ra += 2*PI;
        player(p, ra);
        x += 1;
        ra += (PI/3) / p->game->width;
    }
    
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
    p->player.speed = 3;
    if (p->n)
    {
        printf("north\n");
        p->player.angle = (PI * 3)/2;
    }
    else if (p->s)
    {
        printf("south\n");
        p->player.angle = PI/2;       
    }
    else if (p->w)
    {
        printf("west\n");
        p->player.angle = PI;       
    }
    else if (p->e)
    {
        printf("east\n");
        p->player.angle = 0.0;        
    }
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