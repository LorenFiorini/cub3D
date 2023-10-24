
#include "../../include/cub3D.h"

void	render_background(t_game *game)
{
	uint32_t	img_row;
	uint32_t	img_col;
	uint32_t	color;

	img_row = 0;
	while (img_row < game->image->height)
	{
		img_col = 0;
		if (img_row < game->image->height / 2)
			color = game->ceiling_color;
		else
			color = game->floor_color;
		while (img_col < game->image->width)
		{
			mlx_put_pixel(game->image, img_col, img_row, color);
			img_col++;
		}
		img_row++;
	}
}
