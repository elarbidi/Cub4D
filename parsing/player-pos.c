# include "../cub3d.h"

void	player_pos(t_parse *parse) {
	parse->i = 0;
	while (parse->map_elmnt[parse->i]) {
		parse->j = 0;
		while (parse->map_elmnt[parse->i][parse->j]) {
			if (parse->map_elmnt[parse->i][parse->j] == 'S'
				|| parse->map_elmnt[parse->i][parse->j] == 'N'
				|| parse->map_elmnt[parse->i][parse->j] == 'W'
				|| parse->map_elmnt[parse->i][parse->j] == 'E') 
			{
				parse->posx = parse->j + 1;
				parse->posy = parse->i + 1;
			}
			parse->j++;
		}
		parse->i++;
	}
}