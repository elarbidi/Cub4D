# include "../cub3d.h"

void	is_valid_path(t_parse *path) {
	char	*xpm;
	char	*valid_paths;

	path->map_elmnt = ft_split(path->map, '\n');
	path->i = 0;
	while (path->map_elmnt[path->i]) {
		xpm = ft_strrchr(path->map_elmnt[path->i], '.');
		if (!xpm)
			return ;
		valid_paths = check_xpm(xpm, path);
		if (!valid_paths)
			return ;
		path->i++;
	}
	return ;
}