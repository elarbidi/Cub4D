# include "../cub3d.h"

int check_color_values(t_parse *parse) {
	int i;

	i = 0;
	while (i < 3) {
		if (parse->f_colors[i] > 255 || parse->f_colors[i] < 0)
			return (ERROR);
		if (parse->c_colors[i] > 255 || parse->c_colors[i] < 0)
			return (ERROR);
		i++;
	}
	return (SUCCES);
}

static void free_color_elmnt(char **color_elmnt) {
	int i;

	i = 0;
	while (color_elmnt[i]) {
		free(color_elmnt[i]);
		i++;
	}
	free(color_elmnt);
}

int check_floor_color(t_parse *parse) {
	int i;
	char *color;
	char **color_elmnt;

	parse->f_colors = malloc(sizeof(int) * 3);
	if (!parse->f_colors)
		return (ERROR);
	if (check_f(parse) == ERROR)
		return (ERROR);
	color = adjust_color(parse);
	if (color == NULL || !parse->f_colors)
		return (ERROR);
	if (check_spaces(color) == ERROR)
		return (ERROR);
	color_elmnt = ft_split(color, ',');
	free(color);
	i = 0;
	while (i < 3) {
		if (color_elmnt[i] == NULL)
			return (ERROR);
		parse->f_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	free_color_elmnt(color_elmnt);
	return (SUCCES);
}

int check_ceiling_color(t_parse *parse) {
	int i;
	char *color;
	char **color_elmnt;

	parse->c_colors = malloc(sizeof(int) * 3);
	if (!parse->c_colors)
		return (ERROR);
	if (check_c(parse) == ERROR)
		return (ERROR);
	color = adjust_color(parse);
	if (color == NULL || !parse->c_colors)
		return (ERROR);
	if (check_spaces(color) == ERROR)
		return (ERROR);
	color_elmnt = ft_split(color, ',');
	free(color);
	i = 0;
	while (i < 3) {
		if (color_elmnt[i] == NULL)
			return (ERROR);
		parse->c_colors[i] = ft_atoi(color_elmnt[i]);
		i++;
	}
	free_color_elmnt(color_elmnt);
	return (SUCCES);
}

int check_colors(t_parse *parse) {
	parse->i = 0;
	while (parse->map_elmnt[parse->i]) {
		if (ft_strstr(parse->map_elmnt[parse->i], "F ") != NULL)
			if (check_floor_color(parse) == ERROR)
				return (ERROR);
		if (ft_strstr(parse->map_elmnt[parse->i], "C ") != NULL)
			if (check_ceiling_color(parse) == ERROR)
				return (ERROR);
		parse->i++;
	}
	return (SUCCES);
}