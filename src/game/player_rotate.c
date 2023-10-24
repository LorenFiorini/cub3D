
#include "../../../include/cub3D.h"

void	rotate_player_left(t_game *game)
{
	game->player.orientation -= ROTATE_SPEED;
	if (game->player.orientation < 0)
		game->player.orientation += 2 * M_PI;
}


void	rotate_player_right(t_game *game)
{
	game->player.orientation += ROTATE_SPEED;
	if (game->player.orientation >= 2 * M_PI)
		game->player.orientation -= 2 * M_PI;
}

/* To be implemented later
 * rotate_player_up(t_game *game)
 * rotate_player_down(t_game *game)
 * 
 */