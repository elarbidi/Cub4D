# include "../cub3d.h"

int check_textures(t_parse *p) {
	if (!p->path_so || !p->path_no || !p->path_ea || !p->path_we) {
		putstr_fd_color(RED, TEXTURES_ERROR, 2);
		return (ERROR);
	}
	return (SUCCES);
}