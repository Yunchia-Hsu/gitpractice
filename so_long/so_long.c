/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:05:07 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/16 11:18:59 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

initialize_game_struct(map_array);

char    *initialize_data(char *str)
{
	char *map_str;
	char **map_array;
	t_game *data;

	map_str = read_map(str);
	check_empty(map_str);
	check_empty_line(map_str); //?? 
	check_map_content(map_str);
	map_array = ft_split(map_str, '\n');
	check_map_shape(map_str);
	data = initialize_game_struct(map_array);
	check_walls(data);
	flood_fill(data);
	free(map_str);
	return(data);
}


int main (int argc, char *argv[])
{
    t_game  *game;
    t_img   *images;
    
    //parse the map into data 
    if (argc != 2)
        error_message("NoNo. One file  only!");
    //check map validation
	check_file_extention(argv[1]);//chek fille name .ber
    game = initialize_data(argv[1]);
    game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, "so_long", false);
    if (!game->mlx)
        return(EXIT_FAILURE);
   //init window 
    images = initialize_img_struct(game->mlx);
    game->img = images;
    fill_background(game);
    
    
    //create, maintain a loop to run the window
    
    //init images create images

    //render map and elements
    render_map(game);
    pust_enemies(game);
    strig_to_screen(game);
    //create an event loop to handle input
    mlx_key_hook(game->mlx,  move_hook, game);
    mlx_loop_hook(game->mlx, enemy_patrol, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
    return (EXIT_SUCCESS);
}