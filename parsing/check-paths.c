# include "../cub3d.h"

static int check_so(char *s, t_parse *parse) {
	char	*so;
	
	so = ft_strstr(parse->map_elmnt[parse->i], "SO");
	if (so != NULL) {
		so = skip_spaces(parse->map_elmnt[parse->i]);
		if (ft_strncmp(so, "SO", 2) != 0)
			return (ERROR);
		free (so);
		s = ft_strstr(parse->map_elmnt[parse->i], "SO");
		parse->path_so = ft_strchr(s, '.');
	}
	return (SUCCES);
}

static int check_no(char *s, t_parse *parse) {
	char	*no;
	
	no = ft_strstr(parse->map_elmnt[parse->i], "NO");
	if (no != NULL) {
		no = skip_spaces(parse->map_elmnt[parse->i]);
		if (ft_strncmp(no, "NO", 2) != 0)
			return (ERROR);
		free (no);
		s = ft_strstr(parse->map_elmnt[parse->i], "NO");
		parse->path_no = ft_strchr(s, '.');
	}
	return (SUCCES);
}

static int check_ea(char *s, t_parse *parse) {
	char	*ea;
	
	ea = ft_strstr(parse->map_elmnt[parse->i], "EA");
	if (ea != NULL) {
		ea = skip_spaces(parse->map_elmnt[parse->i]);
		if (ft_strncmp(ea, "EA", 2) != 0)
			return (ERROR);
		free (ea);
		s = ft_strstr(parse->map_elmnt[parse->i], "EA");
		parse->path_ea = ft_strchr(s, '.');
	}
	return (SUCCES);
}

static int check_we(char *s, t_parse *parse) {
	char	*we;
	
	we = ft_strstr(parse->map_elmnt[parse->i], "WE");
	if (we != NULL) {
		we = skip_spaces(parse->map_elmnt[parse->i]);
		if (ft_strncmp(we, "WE", 2) != 0)
			return (ERROR);
		free (we);
		s = ft_strstr(parse->map_elmnt[parse->i], "WE");
		parse->path_we = ft_strchr(s, '.');
	}
	return (SUCCES);	
}

char	*check_xpm(char *s, t_parse *parse) {
	if (!s || ft_strncmp(s, ".xpm", 4) != 0)
		return (NULL);
	if (check_so(s, parse) == ERROR)
		return (NULL);
	if (check_no(s, parse) == ERROR)
		return (NULL);
	if (check_ea(s, parse) == ERROR)
		return (NULL);
	if (check_we(s, parse) == ERROR)
		return (NULL);
	return (s);
}
