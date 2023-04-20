#include "../cub3d.h"


void    texel_coor(t_parse *p, t_vesion  *v_field)
{
    t_txt *tex = &p->tx;
    p->player.dest = v_field->tp + (v_field->dest_plan / 2) - (p->game->hight / 2);
        // v_field->width_text : size of texture
    v_field->ty = p->player.dest * (v_field->width_text / v_field->dest_plan);
    p->player.colors = 0;
    if (v_field->ty > v_field->width_text)
        v_field->ty = v_field->width_text;
    if (v_field->ty < 0)
        v_field->ty = 0;
    if (p->player.hflag == 1 && p->player.hx == p->player.px)
    {
        // printf("test ===> \n");
        // printf("this is width for texture ==> %d\n==> %d\n==> %d\n", v_field->width_text,  v_field->ty,  v_field->tx);
        if (v_field->h_active == 2)
        {
            // printf("north check!!!\n");

            p->player.colors = p->tx.no[(v_field->width_text * v_field->ty) + v_field->tx];
        }
        else
        {
            // printf("south check!!!\n");
            // p->player.colors = 0xFFFF00;
            p->player.colors = p->tx.so[(v_field->width_text * v_field->ty) + v_field->tx];
        }
    }
    else
    {
        // printf("skiiip ====> \n");
        if (v_field->v_active == 2)
        {
            // printf("west check!!!\n");
            // p->player.colors = 0x00FF00;
            p->player.colors = p->tx.we[(v_field->width_text * v_field->ty) + v_field->tx];
        }
        else
        {
            // printf("east check!!!\n");
            // p->player.colors = 0x0000FF;
            p->player.colors = p->tx.ea[(v_field->width_text * v_field->ty) + v_field->tx];
        }
    }
} 