# ifndef PARSE_H
# define PARSE_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"
// Define Erros:

# define SUCCES 0
# define ERROR 1
#define PI 3.14159

# define NONVALID_FILE "ERROR:\n-- Non valid extension. Need a .cub file! --"
# define ARGC_ERROR "-- I only need a .cub file --"
# define EMPTY_FILE "ERROR:\n--Invalid components OR File is empty --"
# define FILE_DISCRIPTOR "ERROR:\n-- Invalid file discriptor! --"
# define LAST_LINE_EMPTY "-- Empty line --"

# define PATH_ERROR "-- Something went wrong processing png path --"
# define WRONG_NUMBER "-- Colors input needs to be in [0,255] range --"
# define RBG_ERROR "-- I need three colour inputs --"
# define COLOUR_INPUT_ERROR "-- I need floor or ceiling input --"
# define TEXTURES_ERROR "-- I need all textures --"

# define GNL_ERROR "-- Something went wrong while reading .cub file --"
# define NO_PATH "-- File input is invalid, fix the path/colour data --"

# define MISSING_WALL "-- Missing wall surrounding the map --"
# define MISSING_PLAYER "-- Missing player --"
# define TOO_MANY_PLAYERS "-- Too many players in the map --"
# define UNKNOWN_CHAR "-- Unknown character in map --"
# define NONVALID_MONITOR "-- Your monitor size is too small --"

// Define Colors:

# define RED "\033[0;31m"
# define HYEL "\e[0;93m"
# define RESET "\e[0m"

// Define Structs:

/* I attached below an overview of the variables 
	in the fucking struct and what they are used for
	Also in hovering you will easy know each var was used for. 
*/
typedef struct s_player {
	int	x;
	int y;
	int xprev;
	int yprev;
	float xdem;
	float ydem;
	int	radius;
	float angle;
	int	turn_direction;
	int walk_direction;
	double rotatio;
	int speed;
	double rotation_speed;
} t_player;

typedef struct s_game {
	void	*win;
	void	*mlx;
	void	*img;
	int		*add;
	int		bpp;
	int		len;
	int		end;
	int		width;
	int		hight;
	
}	t_game;

typedef struct s_parse
{
	void	*wall; // a pointer to a texture file for the walls in the game world
	void	*floor; // a pointer to a texture file for the floor in the game world
	int		posx; // the starting x-coordinate of the player in the game world
	int		posy; // the starting y-coordinate of the player in the game world
	int		i; // a counter variable used in loops for parsing the game map
	int		j; // a counter variable used in loops for parsing the game map
	int		s; // a flag indicating whether the "S" identifier for a texture file has been encountered
	int		n; // a flag indicating whether the "N" identifier for a texture file has been encountered
	int		e; // a flag indicating whether the "E" identifier for a texture file has been encountered
	int		w; // a flag indicating whether the "W" identifier for a texture file has been encountered
	int		checker; // a flag indicating whether the game map is currently being parsed for identifiers or map elements
	int		map_fd; // a file descriptor for the game map file
	char	*map; // a string containing the game map
	char	**map_elmnt; // a pointer to an array of strings containing the elements of the game map
	char	*path_so; // a string containing the file path to the texture file for the south-facing walls of the game world
	char	*path_no; // a string containing the file path to the texture file for the north-facing walls of the game world
	char	*path_ea; // a string containing the file path to the texture file for the east-facing walls of the game world
	char	*path_we; // a string containing the file path to the texture file for the west-facing walls of the game world
	int		*f_colors; // an array of integers containing the RGB values for the floor color in the game world
	int			*c_colors; // an array of integers containing the RGB values for the ceiling color in the game world
	t_game		*game;
	t_player	player;
}             t_parse;

///////////////////////////////////////////////////////////////// PARSING //////////////////////////////////////////////////////////////////

// Define init parse
int init_parse(int ac, char **av);
void	free_all(t_parse *parse);
// define check-map
int check_map(t_parse *parse, char **av);
// Define errors
int check_errs(t_parse *parse, char **av);
int check_all(t_parse *parse, char **av);
// Define player-pos
void	player_pos(t_parse *parse);
// Define str tools
void	putstr_fd_color(char *color, char *s, int fd);
// Define Tools functions
char	*ft_strstr(const char *haystack, const char *needle);
char	*skip_spaces(char *str);
int		check_spaces(char *str);
char	*ft_strcpy(char *s1, char *s2);
int	ft_strcmp(const char *s1, const char *s2);
// Define check Path
char	*check_xpm(char *s, t_parse *parse);
// Define is valid path
void	is_valid_path(t_parse *path);
// Define check-keys
int	check_identifier_num(t_parse *p);
int check_elements_num(t_parse *parse);
int check_c(t_parse *parse);
int check_f(t_parse *parse);
// define check_colors
int check_color_values(t_parse *parse);
int check_floor_color(t_parse *parse);
int check_ceiling_color(t_parse *parse);
int check_colors(t_parse *parse);
// Define check textures
int check_textures(t_parse *p);
// Define get colors
char	*remove_space_end(char *s);
char	*remove_space_start(char *s);
int 	only_comma_num(char *str);
char	*adjust_color(t_parse *parse);
// Define check components
int check_pos(t_parse *p);
int check_zero(t_parse *p);
int	check_elements(t_parse *parse);
int global_checks(t_parse *parse);
int check_components(t_parse *parse);
// Get next line
char    *gnl(int fd);


///////////////////////////////////////////////////////////////// RAYCASTING //////////////////////////////////////////////////////////////////
void	getWidth(t_parse *parse);
void    init_game(t_parse *parse);

# endif