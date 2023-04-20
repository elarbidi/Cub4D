#include "../cub3d.h"

void    fill_arr(t_txt *tx, int *res)
{
    int    i;
    int    j;

    i = -1;
    j = -1;
    while (++j < tx->height_img)
    {
        i = -1;
        while (++i < tx->width_img)
        {
            res[(tx->width_img * j) + i] = tx->add[tx->width_img * j + i];
        }
    }
}

int    *fill_texture(t_parse *p, int red)
{
    int    *res;
    int    i;
    int    j;

    i = -1;
    j = -1;

    // p->tx.arr_tx[red] ==> dakchi li3talik
    p->tx.img = mlx_xpm_file_to_image(p->game->mlx, p->tx.arr_tx[red], &p->tx.width_img, &p->tx.height_img);
    if (!p->tx.img)
        return (NULL);
    p->tx.add = (int *)mlx_get_data_addr(p->tx.img, &p->game->bpp, &p->game->len, &p->game->end);
    res = (int *)malloc(sizeof(int) * (p->tx.height_img * p->tx.width_img));
    if (!res)
        return (0);
    fill_arr(&p->tx, res);
    mlx_destroy_image(p->game->mlx, p->tx.img);
    return (res);
}

void ft_perror(char *msg)
{
    perror(msg);
    exit(1);
}

void    init_texture(t_parse *p)
{
    t_txt tx = p->tx;
    p->tx.arr_tx[0] = strdup("./textures/game_texture/17835-copy.xpm");
    p->tx.arr_tx[1] = strdup("./textures/game_texture/tx3.xpm");
    p->tx.arr_tx[2] = strdup("./textures/game_texture/tx2_.xpm");
    p->tx.arr_tx[3] = strdup("./textures/game_texture/ex1.xpm");
    p->tx.no = fill_texture(p, 0);
    p->tx.no_width = p->tx.width_img;
    p->tx.so = fill_texture(p, 1);
    p->tx.so_width = p->tx.width_img;
    p->tx.we = fill_texture(p, 2);
    p->tx.we_width = p->tx.width_img;
    p->tx.ea = fill_texture(p, 3);
    p->tx.ea_width = p->tx.width_img;
    if (!p->tx.no || !p->tx.ea || !p->tx.so || !p->tx.we)
        ft_perror("Failed to create texture");
}