#include "../../include/cub3D.h"

void	rotate_player(t_game *game, t_player_action action)
{
	double	new_orientation;

	new_orientation = game->player.orientation;
	if (action == ROTATE_CCW)
		new_orientation -= ROTATE_SPEED;
	else if (action == ROTATE_CW)
		new_orientation += ROTATE_SPEED;
	if (new_orientation < 0)
		new_orientation += 2 * M_PI;
	else if (new_orientation >= 2 * M_PI)
		new_orientation -= 2 * M_PI;
	game->player.orientation = new_orientation;
	generate_render(game);
	print_render(&game->render);						// DEBUG
	print_ray(&game->render.rays[0]);					// DEBUG
	print_ray(&game->render.rays[WINDOW_WIDTH /3]);	// DEBUG
	print_ray(&game->render.rays[WINDOW_WIDTH - 1]);	// DEBUG
}
