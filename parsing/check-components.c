# include "../cub3d.h"

int check_pos(t_parse *p) {
    if (p->map_elmnt[p->i][p->j] == 'W'
        || p->map_elmnt[p->i][p->j] == 'S'
        || p->map_elmnt[p->i][p->j] == 'N'
        || p->map_elmnt[p->i][p->j] == 'E'
        || p->map_elmnt[p->i][p->j] == '0') 
    {
        if (p->map_elmnt[p->i - 1] == NULL
            || p->map_elmnt[p->i - 1][p->j] <= 32
            || p->map_elmnt[p->i][p->j - 1] <= 32
            || p->map_elmnt[p->i][p->j + 1] <= 32
            || p->map_elmnt[p->i + 1] == NULL
            || p->map_elmnt[p->i + 1][p->j] <= 32
            || !p->map_elmnt[p->i + 1][p->j])
            return (ERROR);
    }
    return (SUCCES);
}

int check_zero(t_parse *p) {
    if (p->map_elmnt[p->i][0] == '0'
        || p->map_elmnt[p->i][0] == 'S'
        || p->map_elmnt[p->i][0] == 'N'
        || p->map_elmnt[p->i][0] == 'W'
        || p->map_elmnt[p->i][0] == 'E')
        return (ERROR);
    return (SUCCES);
}

int	check_elements(t_parse *parse)
{
	if (ft_strchr("10NWES ", parse->map_elmnt[parse->i][parse->j]) == NULL)
		return (ERROR);
	return (SUCCES);
}

int global_checks(t_parse *parse) {
    while (parse->map_elmnt[parse->i])
    {
        parse->j = 0;
        while (parse->map_elmnt[parse->i][parse->j])
        {
            if (parse->map_elmnt[parse->i][parse->j] >= 48)
            {
                if (check_elements(parse) == 1)
                    return (ERROR);
                if (check_pos(parse) == 1)
                    return (ERROR);
            }
            if (parse->map_elmnt[parse->i][parse->j] == '0')
            {
                if (check_zero(parse) == 1)
                    return (ERROR);
            }
            parse->j++;
        }
        parse->i++;
    }
    return (SUCCES);
}

int check_components(t_parse *parse) {
    parse->i = 0;
    if (parse->checker == 6) {
        parse->i = parse->checker;
        if (global_checks(parse) == 1)
            return (ERROR);
    }
    return (SUCCES);
}