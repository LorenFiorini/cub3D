#include "../../include/render.h"

int64_t	get_distance_between(t_vector vector, t_vector origin)
{
	t_vector	distance;

	distance.x = vector.x - origin.x;
	distance.y = vector.y - origin.y;
	distance.z = vector.z - origin.z;
	return (sqrt(pow(distance.x, 2) + pow(distance.y, 2) + pow(distance.z, 2)));
}

bool	is_wall(t_game *game, t_vector vector)
{
	size_t	x;
	size_t	y;

	x = vector.x / TILE_SIZE;
	y = vector.y / TILE_SIZE;
	if (x <= 0 || y <= 0 || x >= game->map.max_width || y >= game->map.height)
		return (true);
	return (game->map.map[y][x] == '1' || game->map.map[y][x] == ' ');
}

t_vector	vector_difference(t_vector a, t_vector b)
{
	t_vector	diff;

	diff.x = a.x - b.x;
	diff.y = a.y - b.y;
	diff.z = a.z - b.z;
	return (diff);
}
