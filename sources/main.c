#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_settings(&game);
	parse(&game, argc, argv);
	return (EXIT_SUCCESS);
}
