# include "../cub3d.h"

int	check_identifier_num(t_parse *p)
{
	if (p->s >= 2)
		return (ERROR);
	if (p->w >= 2)
		return (ERROR);
	if (p->n >= 2)
		return (ERROR);
	if (p->e >= 2)
		return (ERROR);
	if (p->e + p->s + p->w + p->n > 1
		|| p->e + p->s + p->w + p->n == 0)
		return (ERROR);
	return (SUCCES);
}

int check_elements_num(t_parse *parse) {
    parse->s = 0;
    parse->e = 0;
    parse->n = 0;
    parse->w = 0;
    parse->i = 0;
    while (parse->map_elmnt[parse->i]) {
        parse->j = 0;
        while (parse->map_elmnt[parse->i][parse->j]) {
            if (parse->map_elmnt[parse->i][parse->j] == 'S')
                parse->s++;
            if (parse->map_elmnt[parse->i][parse->j] == 'N')
                parse->n++;
            if (parse->map_elmnt[parse->i][parse->j] == 'W')
                parse->w++;
            if (parse->map_elmnt[parse->i][parse->j] == 'E')
                parse->e++;
            parse->j++;
        }
        parse->i++;
    }
    if (check_identifier_num(parse) == 1)
        return (ERROR);
    return (SUCCES);
}

int check_c(t_parse *parse) {
    int     k;
    int     size;

    size = ft_strlen(parse->map_elmnt[parse->i]);
    k = 0;
    while (k < size) {
        if (parse->map_elmnt[parse->i][k] == 'C')
            break ;
        if (parse->map_elmnt[parse->i][k] >= 32)
            return (ERROR);
        k++;
    }
    return (SUCCES);
}

int check_f(t_parse *parse) {
    int     k;
    int     size;

    size = ft_strlen(parse->map_elmnt[parse->i]);
    k = 0;
    while (k < size) {
        if (parse->map_elmnt[parse->i][k] == 'F')
            break ;
        if (parse->map_elmnt[parse->i][k] >= 32)
            return (ERROR);
        k++;
    }
    return (SUCCES);
}