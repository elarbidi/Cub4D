# include "../cub3d.h"

void	putstr_fd_color(char *color, char *s, int fd)
{
	if (!color || !s || fd < 0)
		return ;
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(RESET, fd);
}