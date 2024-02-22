/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:05:07 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/22 17:21:03 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void fill_background(t_game *data)
{
    size_t x;
    size_t y;
    
    y = 0;
    while ( y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (mlx_image_to_window(data->mlx, data->img->floor, x * PIXELS, y * PIXELS) < 0)
            x++;
        }
        y++;
    }   
}


int main (int argc, char *argv[])
{
    t_game  *game;
    t_img   *images;
    
    //parse the map into data 
    if (argc != 2)
        error_message("NoNo. One file  only!");
    //check map validation
	check_file_extension(argv[1]);//chek fille name .ber
    game = initialize_data(argv[1]);

    //init window 
    game->mlx = mlx_init(game->width * PIXELS, game->height * PIXELS, "so_long", false);
    if (!game->mlx)
        return(EXIT_FAILURE);
   
    images = initialize_img_struct(game->mlx);//create, maintain a loop to run the window , create images
    game->img = images;
    fill_background(game);//render map and elements

     
    //render_map(game);
    //pust_enemies(game);
    //strig_to_screen(game);
        //create an event loop to handle input
    //mlx_key_hook(game->mlx,  move_hook, game);
    //mlx_loop_hook(game->mlx, enemy_patrol, game);
    mlx_loop(game->mlx);
    //mlx_terminate(game->mlx);
    return (EXIT_SUCCESS);
}

// typedef struct mlx_image
// {
// 	const uint32_t	width;
// 	const uint32_t	height;
// 	uint8_t*		pixels;
// 	mlx_instance_t*	instances;
// 	size_t			count;
// 	bool			enabled;
// 	void*			context;
// }	mlx_image_t; // delete

// typedef struct mlx_texture
// {
// 	uint32_t	width;
// 	uint32_t	height;
// 	uint8_t		bytes_per_pixel;
// 	uint8_t*	pixels;
// }	mlx_texture_t