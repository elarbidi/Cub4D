/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelarbid <aelarbid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:13:11 by aelarbid          #+#    #+#             */
/*   Updated: 2023/04/20 00:59:12 by aelarbid         ###   ########.fr       */
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
            if (i%64 == 0)
                p->game->add[j * p->game->width + i] = 0xFFFFFF;
            else if (j%64 == 0)
                p->game->add[j * p->game->width + i] = 0xFFFFFF;
            else if (p->map_elmnt[j/64][i/64] == '1')
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
    int i = p->player.x / 64;
    int j = p->player.y / 64;

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
    dof = 18;
    if (ang > 2 * PI)
        ang -= 2 * PI;
    if (ang < 0)
        ang += 2 * PI;
    ra = ang;
    dof = 0;
    float atan = -tan(ra);
    if (ra > (PI / 2) && ra < (3 * PI / 2))
    {
        rx = (int)(p->player.x/64) * 64 - 0.0001;
        ry = (p->player.x - rx) * atan + p->player.y;
        xo = -64;
        yo = -xo * atan;
    }
    else if (ra < (PI / 2) || ra > (3 * PI / 2))
    {
        rx = (int)(p->player.x/64) * 64 + 64;
        ry = (p->player.x - fabsf(rx)) * atan + p->player.y;
        xo = 64;
        yo = -xo * atan;
    }
    else if (ra == (PI / 2) || ra == (3 *PI / 2))
    {
        ry = p->player.y;
        rx = p->player.x;
        dof = 18;
    }
    while (1)
    {
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * p->game->width + mx;
        if (my < 0 || mx < 0 || my >= (p->game->hight/64) || mx >= (p->game->width/64))
            break;
        if ( mp > 0 && mp < p->game->width * p->game->hight && p->map_elmnt[my][mx] == '1')
        {
            p->player.vflag = 1;
            break;
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

    dof = 18;
    if (ang > 2 * PI)
        ang -= 2 * PI;
    if (ang < 0)
        ang += 2 * PI;
    p->player.hflag = 0;
    ra = ang;
    dof = 0;
    float atan = -1/tan(ra);
    if (ra > PI && ra < 2 * PI)
    {
        ry = (int)(p->player.y/64) * 64 - 0.0001;
        rx = (p->player.y - ry) * atan + p->player.x;
        yo = -64;
        xo = -yo * atan;
    }
    else if (ra < PI && ra > 0.0)
    {
        ry = (int)(p->player.y/64) * 64 + 64;
        rx = (p->player.y - ry) * atan + p->player.x;
        yo = 64;
        xo = -yo * atan;
    }
    else if (ra == 0.0 || ra == PI)
    {
        ry = p->player.y;
        rx = p->player.x;
        dof = 18;
    }
    while (1)
    {
        mx = (int)(rx)/64;
        my = (int)(ry)/64;
        mp = my * p->game->width + mx;
        if (my < 0 || mx < 0 || my >= (p->game->hight/64) || mx >= (p->game->width/64))
            break;
        if ( mp > 0 && mp < p->game->width * p->game->hight && p->map_elmnt[my][mx] == '1')
        {
            p->player.hflag = 1;
            break;
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
        p->player.dest = v;
    }
    else
    {
        p->player.px = p->player.hx;
        p->player.py = p->player.hy;
        p->player.dest = h;
    }
}

void player(t_parse *p, float ang)
{
    // draw_player(p);
    check_wall(p);
    draw_hor(p, ang);
    draw_ver(p, ang);
    ft_shortest(p);
}
int	ft_close(t_parse *p)
{
    if (!mlx_destroy_window(p->game->mlx, p->game->win))
        exit(0);
    return 0;
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
    if (key == 53)
        ft_close(p);

    return 0;
}

void vesion_field(t_parse* p, int ind, float ra)
{
    t_vesion v_field;
            /********** in function *******/
    p->player.dest = p->player.dest * cos(ra - p->player.angle); 
    v_field.dest_plan = 64 * p->game->hight / p->player.dest;
    v_field.center_plan = p->game->hight/2 - v_field.dest_plan/2;
    v_field.bottom_plan = v_field.center_plan + v_field.dest_plan;
    v_field.top_plan = v_field.center_plan;

    if (v_field.bottom_plan >= p->game->hight)
        v_field.bottom_plan = p->game->hight;
    if (v_field.top_plan < 0)
        v_field.top_plan = 0;

    v_field.width_text = 0;
    v_field.h_active = -1;
    v_field.v_active = -1;

            /*****************/
    if (p->player.vflag == 1 && p->player.vx == p->player.px)
    {
        // in fucntion
        if (ra > (PI / 2) && ra < (3 * PI / 2))
        {
            v_field.v_active = 2;
            v_field.width_text = p->tx.we_width;
        }
        else if (ra < (PI / 2) || ra > (3 * PI / 2))
        {
            v_field.v_active = 1;
            v_field.width_text = p->tx.ea_width;
        }
        v_field.tx = ((int)p->player.vy % 64) * (v_field.width_text / 64); 
    }
    else if (p->player.hflag == 1 && p->player.hx == p->player.px)
    {
        // in fucntion
        if (ra > PI && ra < 2 * PI)
        {
            v_field.h_active = 2;
            v_field.width_text = p->tx.no_width;
        }
        else if (ra < PI && ra > 0.0)
        {
            v_field.h_active = 1;
            v_field.width_text = p->tx.so_width;
        }
        v_field.tx = ((int)p->player.hx % 64) * (v_field.width_text / 64); 
    }
    v_field.tp = (int)v_field.top_plan;
    v_field.bp = (int)v_field.bottom_plan;
    while (v_field.tp < v_field.bp)
    {
        if (v_field.tx > v_field.width_text)
            v_field.tx = v_field.width_text;
        texel_coor(p, &v_field);
        p->game->add[p->game->width * v_field.tp + ind] = p->player.colors;
        v_field.tp++;
    }
}

void floor_ceiling(t_parse *p)
{
    int i = 0;
    int j = 0;
    while (j < p->game->hight/2)
    {
        i = 0;
        while (++i < p->game->width - 1)
        {
            p->game->add[p->game->width * j + i] = 0x87CEEB;
        }
        j++;
    }
    while (j < p->game->hight - 1)
    {
        i = 0;
        while (++i < p->game->width - 1)
        {
            p->game->add[p->game->width * j + i] = 0x964B00;
        }
        j++;
    }
    
}

int action(t_parse *p)
{
    floor_ceiling(p);
    float ra = p->player.angle - (PI/6);
    int x = 0;
    while (x < p->game->width)
    {
        if (ra > 2*PI)
            ra -= 2*PI;
        if (ra < 0)
            ra += 2*PI;
        player(p, ra);
        vesion_field(p, x, ra);
        x += 1;
        ra += ((PI/3) / p->game->width);
    }
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
                p->player.x = i * 64 + 15;
                p->player.y = j * 64 + 15;
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
        p->player.angle = (PI * 3)/2;
    else if (p->s)
        p->player.angle = PI/2;       
    else if (p->w)
        p->player.angle = PI;       
    else if (p->e)
        p->player.angle = 0.0;        
    p->player.rotation_speed = 3 * (PI / 180);
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
    init_texture(parse);
    mlx_loop_hook(parse->game->mlx, action, parse);
    mlx_hook(parse->game->win, 2, 0, move, parse);
    mlx_hook(parse->game->win, 17, 0, ft_close, parse);
    mlx_loop(parse->game->mlx);
}