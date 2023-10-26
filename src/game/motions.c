

#include "../../include/cub3D.h"

/**
 * TODO:	-	Wall collision
 * 			-	Door collision (if any)
 */

static t_pos	get_displacement(t_game *game, t_player_action action)
{
	t_pos	displacement;

	init_pos(&displacement);
	if (action == MOVE_FORWARD)
	{
		displacement.x = cos(game->player.orientation) * MOVE_SPEED;
		displacement.y = sin(game->player.orientation) * MOVE_SPEED;
	}
	else if (action == MOVE_BACKWARD)
	{
		displacement.x = -cos(game->player.orientation) * MOVE_SPEED;
		displacement.y = -sin(game->player.orientation) * MOVE_SPEED;
	}
	else if (action == MOVE_LEFT)
	{
		displacement.x = -sin(game->player.orientation) * MOVE_SPEED;
		displacement.y = cos(game->player.orientation) * MOVE_SPEED;
	}
	else if (action == MOVE_RIGHT)
	{
		displacement.x = sin(game->player.orientation) * MOVE_SPEED;
		displacement.y = -cos(game->player.orientation) * MOVE_SPEED;
	}
	return (displacement);
}

static t_pos	get_new_pos(t_game *game, t_player_action action)
{
	t_pos	new_pos;
	t_pos	displacement;

	new_pos = game->player.pos;
	displacement = get_displacement(game, action);
	new_pos.x = game->player.pos.x + displacement.x;
	new_pos.x = fmin(fmax(new_pos.x, 1), game->map.max_width - 2);
	new_pos.y = game->player.pos.y + displacement.y;
	new_pos.y = fmin(fmax(new_pos.y, 1), game->map.height - 2);
	/*
	Check if new_pos is a valid position
	*/
	return (new_pos);
}

void	move_player(t_game *game, t_player_action action)
{
	t_pos	new_pos;

	new_pos = get_new_pos(game, action);
	if (game->map.map[(int)new_pos.y][(int)new_pos.x] != '1' &&
		game->map.map[(int)new_pos.y][(int)new_pos.x] != ' ')
	{
		game->player.pos.x = new_pos.x;
		game->player.pos.y = new_pos.y;
	}
}
