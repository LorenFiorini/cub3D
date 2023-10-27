
#include "../../include/cub3D.h"

/**
 * @attention t_vector (x, y, z)
*/

void	init_ray(t_render *render)
{
	t_ray	*ray;

	ray = &render->rays[render->ray_index];
	ray->id = render->ray_index;
	ray->angle = render->theta;
	ray->origin = copy_vector(render->pov);
	ray->hit = init_vector(0, 0, 0);
	ray->length = 0;
	ray->hor_inter = init_vector(0, 0, 0);
	ray->ver_inter = init_vector(0, 0, 0);
	ray->d_hor = init_vector(0, 0, 0);
	ray->d_ver = init_vector(0, 0, 0);
	ray->hor_length = 0;
	ray->ver_length = 0;
	ray->texture = NULL;
}

void	print_ray(t_ray *ray)
{
	printf("\nRAY:\n");
	printf(" id: %zu\n", ray->id);
	printf(" angle: %f ran ~ %f deg\n", ray->angle, ray->angle * 180 / M_PI);
	print_vector(&ray->origin, "origin", true);
	print_vector(&ray->hit, "hit", true);
	printf(" length: %lld\n", ray->length);
	print_vector(&ray->hor_inter, "hor_inter", true);
	print_vector(&ray->ver_inter, "ver_inter", true);
	print_vector(&ray->d_hor, "d_hor", true);
	print_vector(&ray->d_ver, "d_ver", true);
	printf(" hor_length: %lld\n", ray->hor_length);
	printf(" ver_length: %lld\n", ray->ver_length);

}
