
#include "cub3D.h"

// static void	game_loop(t_game *game)
// {
// 	// Render Background
// 	// Render Map
// 	// Render Minimap
// 	mlx_key_hook(game->mlx, key_hook, game);
// 	mlx_loop(game->mlx);
// }

void	init_settings(t_game *game)
{
	game->mlx = NULL;
	// game->window_height = HEIGHT;
	// game->window_width = WIDTH;
	game->map = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->ceiling_color = 0;
	game->floor_color = 0;
	// game->speed = SPEED;
	game->orientation = 0;
}

// void	init_game(t_game *game)
// {
	// game->mlx = mlx_init(game->window_width, game->window_height, "Cub3d", false);
	// game_loop(game);
// }