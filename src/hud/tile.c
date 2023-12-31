#include "../../include/cub3D.h"

static void	draw_plus(t_hud *hud, uint32_t x, uint32_t y, uint32_t color)
{
	put_pixel(hud, x, y, color);
	put_pixel(hud, x + 1, y, color);
	put_pixel(hud, x - 1, y, color);
	put_pixel(hud, x, y + 1, color);
	put_pixel(hud, x, y - 1, color);
}

static void	draw_square(t_game *game, uint32_t x, uint32_t y, uint32_t color)
{
	int8_t	i;
	int8_t	j;

	i = -game->hud.minimap_half_tile_size - 1;
	while (++i < game->hud.minimap_half_tile_size)
	{
		j = -game->hud.minimap_half_tile_size - 1;
		while (++j < game->hud.minimap_half_tile_size)
			draw_plus(&game->hud, x + rotate(game, j, i, 1),
				y + rotate(game, i, -j, 1), color);
	}
	i = -game->hud.minimap_half_tile_size - 2;
	j = game->hud.minimap_half_tile_size + 1;
	while (++i < j + 1)
	{
		put_pixel(&game->hud, x + rotate(game, j, i, 1),
			y + rotate(game, i, -j, 1), color);
		put_pixel(&game->hud, x + rotate(game, -j, i, 1),
			y + rotate(game, i, j, 1), color);
		put_pixel(&game->hud, x + rotate(game, i, -j, 1),
			y + rotate(game, -j, -i, 1), color);
		put_pixel(&game->hud, x + rotate(game, i, j, 1),
			y + rotate(game, j, -i, 1), color);
	}
}

void	draw_tile(t_game *game, uint32_t x, uint32_t y, uint32_t color)
{
	double	rel_x;
	double	rel_y;

	rel_x = x + 0.5 - game->player.pos.x;
	rel_y = y + 0.5 - game->player.pos.y;
	draw_square(game, game->hud.minimap_center + rotate(game, rel_x, rel_y,
			game->hud.minimap_tile_size), game->hud.minimap_center
		+ rotate(game, rel_y, -rel_x, game->hud.minimap_tile_size), color);
}
