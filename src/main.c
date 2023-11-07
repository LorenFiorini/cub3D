#include "../include/cub3D.h"

void	leaks(void)//DEBUG
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_game	game;

	// atexit(leaks);//DEBUG
	init_game(&game);
	parse(&game, argc, argv);
	setup_game(&game);
	mlx_loop_hook(game.mlx, hook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	printf("\033[K\rThanks for playing\n");
	return (EXIT_SUCCESS);
}
