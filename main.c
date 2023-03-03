# include "cub3d.h"
# include <string.h>

int main(int ac, char **av) {
	int res;
	res = (init_parse(ac, av) == 1) ? ERROR : SUCCES;
	return (res);
}
