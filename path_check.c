/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:59:39 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/21 18:10:46 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	free_grid(char **grid, size_t height)
{
    size_t  i;
    
    i = 0;
    while(i < height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);// the function deallocates the memory allocated for the double pointer grid
}


int check_path(t_game *temp, size_t y, size_t x)
{
    if (temp->grid[y][x] == '1')
        return (0);
    if (temp->grid[y][x] == 'C')
        temp->eyeball--;
    if (temp->grid[y][x] == 'E')
    {
        temp->exit_x = 1;
        return (0);
    }
    temp->grid[y][x] = '1';
    if (check_path(temp, y, x + 1))
        return (1);
    if (check_path(temp, y, x - 1))
        return (1);
    if (check_path(temp, y + 1, x))
        return (1);
    if (check_path(temp, y - 1, x))
        return (1);
    return (0);
}


int	flood_fill(t_game *game)
{
    t_game temp;
    size_t  i;
    
    temp.width = game->width;  //temp is a struct not a pointer to a struct so use "temp.width"
    temp.height = game->height;
    temp.eyeball = game->eyeball;
    temp.player_x = game->player_x;
    temp.player_y = game->player_y;
    temp.exit_x = 0;
    temp.grid = (char **)malloc(temp.height * sizeof(char *)); //???
    if (!temp.grid)
        error_message("Memory allocation failed");
    i = 0;
    while (i < temp.height)
    {
        temp.grid[i] = ft_strdup(game->grid[i]);
        i++;
    }
    check_path(&temp, temp.player_x, temp.player_y);
    if (!(temp.eyeball == 0 && temp.exit_x == 1))
        error_message("No valid path available");
    
    free_grid(temp.grid, temp.height);
    return (0);
}

// #include <stdio.h>
// int main() 
// {
// 	t_game *data;
//     char **map_array;
//     char *map = "map1.ber";
//     // char *map = "1111111111\n"
//     //             "1000P00001\n"
//     //             "100C0C0001\n"
//     //             "1E00000001\n"
//     //             "1111111111";
    
// 	char *str = read_map(map);
    
//     //printf("read map check:%s\n", str);           
//     map_array = ft_split(str, '\n');
//     data = initialize_game_struct(map_array);
//     printf("eyeball:%zu\n", data->eyeball);
//     printf("exit:%zu\n", data->exit_x);
//     flood_fill(data);

//     printf("A eyeball:%zu\n", data->eyeball);
//     printf("A exit:%zu\n", data->exit_x);
    
//     return 0;
// }