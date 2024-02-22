#include "so_long.h"

t_img	*load_tree_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*tree;

	tree = mlx_load_png("./sprites/tree.png");
	if (!tree)
		error_message("Problem with loading png1");
	img->tree = mlx_texture_to_image(mlx, tree);
	if (!img->tree)
		error_message("Problem with texture to image2");
	mlx_delete_texture (tree);
	return (img);
}
t_img	*load_gravestone_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*gravestone;

	gravestone = mlx_load_png("./sprites/gravestone.png");
	if (!gravestone)
		error_message("Problem with loading png3");
	img->gravestone = mlx_texture_to_image(mlx, gravestone);
	if (!img->gravestone)
		error_message("Problem with texture to image4");
	mlx_delete_texture (gravestone);
	return (img);
}
t_img *load_eyeball_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*eyeball;

	eyeball = mlx_load_png("./sprites/eyeball.png");
	if (!eyeball)
		error_message("Problem with loading png5");
	img->eyeball = mlx_texture_to_image(mlx, eyeball);
	if (!img->eyeball)
		error_message("Problem with texture to image6");
	mlx_delete_texture (eyeball);
	return (img);
}

t_img	*load_player_texture(mlx_t *mlx, t_img *img)
{
	mlx_texture_t	*player;

	player = mlx_load_png("./sprites/horseman.png");
	if (!player)
		error_message("Problem with loading png7");
	img->player = mlx_texture_to_image(mlx, player);
	if (!img->player)
		error_message("Problem with texture to image8");
	mlx_delete_texture (player);
	return (img);
}

t_img *load_floor_texture(mlx_t *mlx, t_img *img)
{
		mlx_texture_t	*floor;

	floor = mlx_load_png("./sprites/floor.png");
	if (!floor)
		error_message("Problem with loading png9");
	img->floor = mlx_texture_to_image(mlx, floor);
	if (!img->floor)
		error_message("Problem with texture to image10");
	mlx_delete_texture (floor);
	return (img);
}

t_img	*load_enemy_texture(mlx_t *mlx, t_img *img)
{
		mlx_texture_t	*enemy;

	enemy = mlx_load_png("./sprites/enemy.png");
	if (!enemy)
		error_message("Problem with loading png11");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		error_message("Problem with texture to image12");
	mlx_delete_texture (enemy);
	return (img);
}