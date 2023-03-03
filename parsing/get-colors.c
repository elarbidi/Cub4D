# include "../cub3d.h"

char	*remove_space_end(char *s)
{
    int len;
	
	len = ft_strlen(s);
    while (len > 0 && s[len-1] <= 32) {
        len--;
    }
    return (ft_substr(s, 0, len));
}

char	*remove_space_start(char *s)
{
	int i;
	
	i = 0;
	while (s[i] && s[i] <= 32)
		i++;
	return (ft_substr(s, i, ft_strlen(s) - i));
}

int only_comma_num(char *str)
{
    int i;
	
	i = 0;
    while (str[i])
    {
        if (str[i] == ',')
            i++;
        if (str[i] > '9' || str[i] < '0')
            return 1;
        i++;
    }
    return (SUCCES);
}

char	*adjust_color(t_parse *parse) {
	char	*color;
	char	*begin;
	char	*end;
	
	color = ft_strchr(parse->map_elmnt[parse->i], ' ');
	if (!color)
		return (NULL);
	begin = remove_space_start(color);
	if (!begin)
		return (NULL);
	end = remove_space_end(begin);
	if (!end)
		return (NULL);
	if (only_comma_num(end) == 1)
		return (NULL);
	if (ft_strcmp(end, "") == 0)
		return (NULL);
	color = ft_strcpy(color, end);
	free(begin);
	return (end);
}