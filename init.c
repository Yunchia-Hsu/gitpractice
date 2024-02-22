#include "so_long.h"

//initialize_game_struct(map_array);

// t_img	*load_texture(mlx_t *mlx, t_img *img, char *str, mlx_image_t *s)
// {
// 	mlx_texture_t *sprite;
	
// 	sprite = mlx_load_png(str);
// 	if (!sprite)
// 		error_message("png loading failed");
// 	s = mlx_texture_to_image(mlx, sprite);
// 	if (!s)
// 		error_message("png loading failed");
// 	mlx_delete_texture(sprite);
// 	return (img);
// }


// t_img	*initialize_img_struct(mlx_t *mlx)
// {
// 	t_img *assets;

// 	assets = (t_img *)ft_calloc( 1, sizeof(t_img));
// 		if (!assets)
// 			return NULL; 
// 	assets = load_texture(mlx, assets, "./sprites/tree.png", (assets->tree));
// 	assets = load_texture(mlx, assets, "./sprites/gravestone.png",(assets->gravestone));
// 	assets = load_texture(mlx, assets, "./sprites/floor.png", (assets->floor));
// 	assets = load_texture(mlx, assets, "./sprites/eyeball.png" , (assets->eyeball));
// 	assets = load_texture(mlx, assets, "./sprites/horseman.png", (assets->player));
// 	assets = load_texture(mlx, assets, "./sprites/enemy.png",(assets->enemy));
// 	return (assets);
// }





t_img	*initialize_img_struct(mlx_t *mlx)
{
	t_img	*assets;

	assets = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!assets)
		return (NULL);
	assets = load_tree_texture(mlx, assets);
	assets = load_gravestone_texture(mlx, assets);
	assets = load_eyeball_texture(mlx, assets);
	assets = load_player_texture(mlx, assets);
	//assets = load_exit_texture(mlx, assets);
	assets = load_floor_texture(mlx, assets);
	assets = load_enemy_texture(mlx, assets);
	return (assets);
}
t_game    *initialize_data(char *str)
{
	char *map_str;
	char **map_array;
	t_game *data;

	map_str = read_map(str);
	//check_empty(map_str);
	check_empty_line(map_str);
	check_map_content(map_str);
	map_array = ft_split(map_str, '\n');
	check_map_shape(map_str);
	data = initialize_game_struct(map_array);
	check_wall(data);
	flood_fill(data);
	free(map_str);
	return(data);
}