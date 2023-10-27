
#include "../../include/cub3D.h"


void	render_raycast(t_game *game, t_ray *ray)
{
	t_pixel		pixel;

	pixel.x = ray->id;
	uint32_t distance_to_projection_plane = (game->image->width / 2) / tan(game->player.fov / 2);// * TILE_SIZE;
	uint32_t heigth_projection_plane = (TILE_SIZE / ray->length) * distance_to_projection_plane;

	pixel.y = (game->image->height - heigth_projection_plane) / 2;
	while (pixel.y < (game->image->height + heigth_projection_plane) / 2)
	{
		mlx_put_pixel(game->image, pixel.x, pixel.y, get_color(32, 32, 32, 255));
		pixel.y++;
	}
}
