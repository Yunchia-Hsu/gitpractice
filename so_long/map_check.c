/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:36:37 by yhsu              #+#    #+#             */
/*   Updated: 2024/02/16 13:09:37 by yhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
// void check_empty(char *map)
// {   
//     if (!map[0])
//         error_message("Map is Empty!");
// }


void    error_message(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putendl_fd(str, 2);
    exit(1);//terminates the entire program
}

void	check_file_extension(char *file) 
{
    int     len;

    len = ft_strlen(file);
    if (len < 4 || ft_strncmp(file + len - 4,  ".ber", 4) != 0)
        error_message("please provide a .ber file");
}

void check_empty_line(char *map)
{
    int i;

    i = 0; 
    if ( !map[0] || map[0] == '\n')
        error_message("Map is Empty!");
    while(map[i])
    {
        printf("map[i]:%c\n", map[i]);
        if ((map[i] == '\n' && map[i + 1] == '\n'))
            error_message("There is an Empty line!");
        i++;
    }
}

void    check_invalid_content(int i)
{
    if(!ft_strchr("PEC01\n" , i))//if cant find i in "pec01x"
        error_message("invalid character");
}

void    check_map_content(char *map)
{
    int exit;
    int eyeball;
    int player;
    int i;
    
    exit = 0;
    eyeball = 0;
    player = 0;
    i = 0;
    while (map[i])
    {
        if (map[i] == 'E')
            exit++;    
        else if (map[i] == 'C')
            eyeball++;
        else if(map[i] == 'P')
            player++;
        else
            check_invalid_content(map[i]);
        i++;
    }
    if (exit != 1 ||  eyeball != 1 || player!=1)
        error_message("Map content is not valid");
}

char *read_map(char *map)
{
    char *line;
    char *all_lines;
    int fd;

    fd = open(map,O_RDONLY);
    all_lines = ft_calloc(1, 1);
    if (!all_lines)
        return(NULL);
    while(1)
    {
        
        line = get_next_line(fd);
        if (line)
        {
            all_lines = ft_strjoin(all_lines, line);
            free(line);
        }
        else
            break;
    }
    close(fd);
    return (all_lines);
}
int count_eyeball(t_game *game)
{
    size_t  x;
    size_t  y;
    size_t  c;
    
    c = 0;
    x = 0;
    while(x < game->height)
    {
        y = 0;
        while(y < game->width)
        {
            if (game->grid[x][y] == 'C')
            {
                c++;
            }
            y++;       
        }
        x++;
    }
    return (c);
}

size_t  get_player_pos(t_game  *game, char c)
{
    size_t  x;
    size_t  y;
    
    x = 0;
    while(x < game->height)
    {
        y = 0;
        while(y < game->width)
        {
            if (game->grid[x][y] == 'P')
            {
                if (c == 'x')
                    return (x);
                else    
                    return  (y);
            }
            y++;       
        }
        x++;
    }
    return (0);
}
size_t  get_exit_pos(t_game  *game, char c)
{
    size_t  x;
    size_t  y;
    
    x = 0;
    while( x < game->height)
    {
        y = 0;
        while(y < game->width)
        {
            if (game->grid[x][y] == 'E')
            {
                if (c == 'x')
                    return (x);
                else
                    return (y);
            }
            
            y++;
        }
        x++;
    }
    return (0);
}

void check_map_shape(char *map)
{
	int len;
	int row; 
	int i;
	
	len = 0;
	i = 0;
	row = 0; 
	while(map[i] != '\n')
	{
		len++;
		i++;
	}
    while(map[i])
    {       
        i++;
        if (map[i] == '\n')
          row++;
        if ( map[i] == '\n' && (i - row) % len != 0)
        {  
            error_message("Map is not rectangular");
        }
    }
}
size_t row_count(char **map)
{
    size_t i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

t_game *initialize_game_struct(char **grid)
{
    t_game *game;
    
    
    game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
        error_message("struct memory allocation failed");
    game->grid = grid;
    game->width = ft_strlen(grid[0]);
    game->height =row_count(grid);
    game->eyeball = count_eyeball(game);
    game->steps = 0;
    game->player_x = get_player_pos(game,  'x');//player's position
    game->player_y = get_player_pos(game, 'y');
    game->exit_x = get_exit_pos(game, 'x');//exit's position
    game->exit_y = get_exit_pos(game, 'y');
    
    return (game);
}

void check_wall(t_game *game)
{
    size_t i;

    i = 0;
    while (game->grid[i])//check vertical
    {
            printf("%c\n", game->grid[i][0]);
            if (game->grid[i][0] != '1')
                error_message("The map is not surrounded by walls");
            if (game->grid[i][game->width - 1] != '1')
                error_message("The map is not surrounded by walls");
            i++;
    }
    i = 0; //check horizontal 
    while (game->grid[0][i] || game->grid[game->height - 1][i])
    {
            printf("%c\n", game->grid[0][i]);
            if (game->grid[0][i] != '1')
                error_message("The map is not surrounded by walls");
            if (game->grid[game->height - 1][i] != '1')
                error_message("The map is not surrounded by walls");
            i++;
    }
}



#include <stdio.h>
int main() 
{
	char **map_array;
    char *map = "map_empty.ber";
    t_game *data;
	char *str = read_map(map);
    
    printf("read map check:%s\n", str);
    check_empty_line(str);             
    map_array = ft_split(str, '\n');
    data = initialize_game_struct(map_array);
    
    
    return 0;
}


  // char str[] ="11111111111111111\n"
            //             "1110C000C000C0111\n"
            //             "1100X0000000X0011\n"
            //             "11001100C00110011\n"
            //             "110C110000011C011\n"
            //             "1100C000P000C0011\n"
            //             "1100000CEC0000011\n"
            //             "1110C0000000C0111\n"
            //             "11110011111001111\n"
            //             "1111X0101010X1111\n"
            //             "11111C0C0C0C11111\n"
            //             "11111111111111111";