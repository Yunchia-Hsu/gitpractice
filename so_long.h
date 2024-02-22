/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:32:55 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/22 17:24:27 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft/libft.h"
#include "./MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include<time.h>

#define PIXELS 105
#define EMOVE 25

typedef struct s_var
{
    int ran_x;
    int ran_y;
    int     *x;
    int     *y;
    int index_x;
    int index_y;
}   t_var;

typedef struct s_ing
{
    mlx_image_t	*tree;
	mlx_image_t	*floor;
	mlx_image_t	*eyeball;
	mlx_image_t	*player;
	mlx_image_t	*gravestone;
	//mlx_image_t	*exit_open;
	mlx_image_t	*enemy;
	mlx_image_t	*moves_print;
	mlx_image_t	*moves_nbr;
	mlx_image_t	*eyeball_2;
}	t_img;

typedef struct s_game
{
	char **grid;
	size_t width;
	size_t height;
	size_t eyeball;
	size_t steps;
	size_t collected;
	size_t player_x;
	size_t player_y;
	size_t exit_x;
	size_t exit_y;
	mlx_texture_t *player_up;
	mlx_texture_t *player_down;
	mlx_texture_t *player_left;
	mlx_texture_t *player_right;
	t_img *img;
	// mlx_texture_t *mlx;
	mlx_t *mlx;
}	t_game;

// make map

//make images

//move func

//map validation
char	*read_map(char *map);
void	error_message(char *msg);
void	check_map_shape(char *map);
//void	check_empty(char *map);
void	check_empty_line(char *map);
void	check_invalid_content(int i);
void    check_map_content(char *map);
void	check_file_extension(char *file);

void	check_wall(t_game *game);
//void	check_horo(t_game *game);
//void	check_vert(t_game *game);
int	flood_fill(t_game *game);
int		check_path(t_game *temp, size_t x, size_t y);
void	free_grid(char **grid, size_t height);

//mixed

//init
t_game	*initialize_game_struct(char **grid); 
t_game    *initialize_data(char *str);
t_img	*initialize_img_struct(mlx_t *mlx);

//load sprite
t_img	*load_tree_texture(mlx_t *mlx, t_img *img);
t_img	*load_gravestone_texture(mlx_t *mlx, t_img *img);
t_img *load_eyeball_texture(mlx_t *mlx, t_img *img);
t_img	*load_player_texture(mlx_t *mlx, t_img *img);
t_img *load_floor_texture(mlx_t *mlx, t_img *img);
t_img	*load_enemy_texture(mlx_t *mlx, t_img *img);
//so long



#endif