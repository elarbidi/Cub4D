# include "../cub3d.h"

/**
* @brief This function checks that the map file passed as an argument has a valid file extension,
opens the file, and reads its contents into a buffer.
* @param parse A pointer to the t_parse struct containing variables related to parsing the map.
* @param av An array of strings containing the command line arguments.
* @return SUCCESS if the function executes successfully, or ERROR if any of the steps fail.
*/

int check_map(t_parse *parse, char **av) {
	char	*extension;
	
	extension = ft_strrchr(av[1], '.');
	if (extension == NULL)
		return (ERROR);
	if (ft_strncmp(extension, ".cub", 4) != 0) {
		putstr_fd_color(RED, NONVALID_FILE, 2);
		return (ERROR);
	}
	parse->map_fd = open(av[1], O_RDONLY);
	if (parse->map_fd < 0) {
		putstr_fd_color(RED, FILE_DISCRIPTOR, 2);
		close(parse->map_fd);
		return (ERROR);
	}
	while (1)
	{
		char* line = gnl(parse->map_fd);
		if (line == NULL)
			break;
		int	old_size;
		if (parse->map == NULL)
			old_size = 0;
		else
			old_size = ft_strlen(parse->map);
		char* new_mapbuff = malloc(old_size + ft_strlen(line) + 1);
		ft_bzero(new_mapbuff, old_size + ft_strlen(line) + 1);
		if (parse->map != NULL)
			ft_strcpy(new_mapbuff, parse->map);
		ft_strcpy(new_mapbuff + ft_strlen(new_mapbuff), line);
		free(line);
		free(parse->map);
		parse->map = new_mapbuff;
	}
	if (parse->map == NULL) {
		putstr_fd_color(RED, EMPTY_FILE, 2);
		return (ERROR);
	}
	close(parse->map_fd);
	return (SUCCES);
}
