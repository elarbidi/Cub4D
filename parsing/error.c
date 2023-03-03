# include "../cub3d.h"

int check_errs(t_parse *parse, char **av) {
	if (check_map(parse, av) == 1) {
		free (parse);
		return (ERROR);
	}
	is_valid_path(parse);
	if (check_textures(parse) == 1)
		return (ERROR);
	if (check_colors(parse) == 1) {
		putstr_fd_color(RED, "Error:\n in map file", 2);
		return (ERROR);
	}
	if (check_color_values(parse) == 1) {
		putstr_fd_color(RED, "Error:\n in map file", 2);
		return (ERROR);
	}
	parse->checker = 6;
	if (check_components(parse) == 1) {
		putstr_fd_color(RED, "Error:\n in map file", 2);
		return (ERROR);
	}
	return (SUCCES);
}

int check_all(t_parse *parse, char **av) {
	if (check_errs(parse, av) == 1)
		return (ERROR);
	parse->map_elmnt += 6;
	if (check_elements_num(parse) == 1) {
		putstr_fd_color(RED, "Error:\n in map file", 2);
		return (ERROR);
	}
	return (SUCCES);
}

