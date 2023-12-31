#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	parse(&game, argc, argv);
	setup_game(&game);
	mlx_loop_hook(game.mlx, hook, &game);
	mlx_key_hook(game.mlx, keyboard, &game);
	mlx_scroll_hook(game.mlx, zoom_minimap, &game);
	mlx_mouse_hook(game.mlx, mouse, &game);
	mlx_resize_hook(game.mlx, resize_window, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	if (PRINT)
		printf("\033[K\rThanks for playing\n");
	return (EXIT_SUCCESS);
}
