
#include "../../include/cub3D.h"

static void	render_reset_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->image);
	game->image = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render_background(game);
}

void	generate_render(t_game *game)
{
	render_reset_image(game);
	init_render(game);
	while (game->render.ray_index < game->image->width)
	{
		init_ray(&game->render);
		find_ray_intersection(game, &game->render.rays[game->render.ray_index]);
		render_raycast(game, &game->render.rays[game->render.ray_index]);
		update_render(&game->render);
	}
}
