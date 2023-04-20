# include "cub3d.h"

void	free_all(t_parse *parse) {
	int i;
	
	i = 0;
	while (parse->map_elmnt[i]) {
		free(parse->map_elmnt[i]);
		i++;
	}
	free(parse->map_elmnt);
	free(parse->f_colors);
	free(parse->c_colors);
	free(parse->map);
}

int init_parse(int ac, char **av) {
	t_parse	*parse;
	
	if (ac == 2) {
		parse = malloc(sizeof(t_parse));
		ft_bzero(parse, sizeof(t_parse));
		if (check_all(parse, av) == 1)
			return (1);
		player_pos(parse);
		init_game(parse);

		parse->map_elmnt = parse->map_elmnt - 6;
		free_all(parse);
		free(parse);
	}
	else {
		putstr_fd_color(RED, "Error:\n Usage </.Cub> + <map path>", 2);
		return (ERROR);
	}
	return (SUCCES);
}
