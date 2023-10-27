
#include "../../include/cub3D.h"


void	render_raycast(t_game *game, t_ray *ray)
{
	t_pixel		pixel;

	pixel.x = ray->id;
	uint32_t distance_to_projection_plane = (WINDOW_WIDTH / 2) / tan(M_PI / 6);// * TILE_SIZE;
	uint32_t heigth_projection_plane = (TILE_SIZE * distance_to_projection_plane) / ray->length;
	// printf("distance_to_projection_plane: %d\n", distance_to_projection_plane);
	// printf("heigth_projection_plane  = (TILE_SIZE / ray->length) * distance_to_projection_plane;\n");
	// printf("heigth_projection_plane: %d  = (%d / %lld) * %d;\n", heigth_projection_plane,\
		//  TILE_SIZE, ray->length, distance_to_projection_plane);
	pixel.y = (game->image->height - heigth_projection_plane) / 2;
	// print_pixel_rgba(pixel.color);
	// printf("(%d,%d): (%d,%d)\n", pixel.x, pixel.y, pixel.x, (game->image->height + heigth_projection_plane) / 2);
	while (pixel.y < (game->image->height + heigth_projection_plane) / 2)
	{
		mlx_put_pixel(game->image, pixel.x, pixel.y, get_pixel_color(ray->texture, 32, 32));
		pixel.y++;
	}
}
