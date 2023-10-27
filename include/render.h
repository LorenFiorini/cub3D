
#ifndef RENDER_H
# define RENDER_H

/* ************************************************************************** */
/*                                  TYPEDEFS                                  */
/* ************************************************************************** */

typedef struct s_game	t_game;
# define WINDOW_WIDTH 1080


/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

/**
 * @brief Ray structure
 * 
 * @param id Index of the ray
 * @param angle Horizontal angle of the ray
 * @param origin Position of the player's eyes
 * @param hit Position of the first wall hit by the ray
 * @param length Distance between the player and the Projection Plane
 * @param hor_inter Horizontal intersection	(parallel to the X axis)
 * @param ver_inter Vertical intersection 		(parallel to the Y axis)
 * @param d_hor Delta of the horizontal intersection
 * @param d_ver Delta of the vertical intersection
 * @param texture Texture of the wall hit by the ray
 * 
 * @attention All angles are in radians
 * @attention Angle rotates clockwise. Negative in the cartesian plane
 * @attention HOR_IN <-> TILE_SIZE divides ray Y coordinate
 */

typedef struct s_ray
{
	size_t			id;
	double			angle;
	t_vector		origin;
	t_vector		hit;
	int64_t			length;
	t_vector		hor_inter;	// Player's eyes as origin
	t_vector		ver_inter;	// Player's eyes as origin
	t_vector		d_hor;		// Player's eyes as origin
	t_vector		d_ver;		// Player's eyes as origin
	int64_t			hor_length;	// Player's eyes as origin
	int64_t			ver_length;	// Player's eyes as origin
	mlx_texture_t	*texture;
}	t_ray;

/**
 * @brief Render structure
 * 
 * @param rays Array of rays
 * @param ray_index Index of the current ray
 * @param theta Angle of the current ray
 * @param delta Angle between two rays
 * @param distance Distance between the player and the Projection Plane
 * @param pov Point of View of the player
 * 
 * @attention All angles are in radians
 * @attention Alpha rotates clockwise (negative in the cartesian plane)
 */

typedef struct s_render
{
	t_ray		rays[WINDOW_WIDTH];
	size_t		ray_index;
	double		theta;
	double		delta;
	int64_t		distance;
	t_vector	pov;
}	t_render;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

/* background.c */
void		render_background(t_game *game);

/* init.c */
void		generate_render(t_game *game);

/* intersection.c */
void		find_ray_intersection(t_game *game, t_ray *ray);

/* ray_cast.c */
void		render_raycast(t_game *game, t_ray *ray);

/* ray.c */
void		init_ray(t_render *render);
void		print_ray(t_ray *ray);

/* render.c */
// t_render	init_render(t_game *game);
void		init_render(t_game *game);
void		update_render(t_render *render);
void		print_render(t_render *render);

/* utils.c */
int64_t		get_distance_between(t_vector vector, t_vector origin);
bool		is_wall(t_game *game, t_vector vector);



#endif
