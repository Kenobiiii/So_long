/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:16 by paromero          #+#    #+#             */
/*   Updated: 2024/05/15 11:49:14 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(int fd, t_res *game)
{
	char	*line;
	int		len;

	game->height = 0;
	game->map = malloc(MAX_ROWS * sizeof(char *));
	line = get_next_line(fd);
	if (!line)
	{
		perror("El archivo esta vacío");
		exit(EXIT_FAILURE);
	}
	while (game->height < MAX_ROWS && line != NULL)
	{
		len = ft_strlen(line);
		game->width = len;
		game->map[game->height] = malloc((len + 1) * sizeof(char));
		if (game->map[game->height] == NULL)
		{
			return ;
		}
		ft_strlcpy(game->map[game->height], line, len + 1);
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_borders(char	**matrix, t_res *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->height)
	{
		if (matrix[i][0] != WALL || matrix[i][game->width - 1] != WALL)
			return (0);
		i++;
	}
	while (j < game->width)
	{
		if (matrix[0][j] != WALL || matrix[game->height - 1][j] != WALL)
			return (0);
		j++;
	}
	return (1);
}

int	ft_caracteres(char **matrix, t_res *structa)
{
	int	i;
	int	j;

	i = 0;
	while (i < structa->height)
	{
		j = 0;
		while (j < structa->width)
		{
			if (matrix[i][j] != FLOOR && matrix[i][j] != PLAYER)
			{
				if (matrix[i][j] != MAP_EXIT && matrix[i][j] != COLLECT)
					if (matrix[i][j] != WALL)
						return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	floodfill(t_res *map_dup, int x, int y)
{
	if (x < 0 || y < 0 || y >= map_dup->height || x >= map_dup->width)
		return ;
	if (map_dup->map[y][x] == WALL)
		return ;
	if (map_dup->map[y][x] == COLLECT)
		map_dup->chest++;
	if (map_dup->map[y][x] == MAP_EXIT)
		map_dup->exit_c++;
	if (map_dup->map[y][x] != PLAYER)
		map_dup->map[y][x] = WALL;
	floodfill(map_dup, x + 1, y);
	floodfill(map_dup, x, y + 1);
	floodfill(map_dup, x - 1, y);
	floodfill(map_dup, x, y - 1);
}

// int	check_floodfill(t_res *game, int fd)
// {
// 	t_res	*map_dup;

// 	map_dup = init_game();
// 	read_file(fd, map_dup);
// 	ft_character_pos(map_dup->map, map_dup);
// 	floodfill(map_dup, map_dup->character_x, map_dup->character_y);
// 	if (map_dup->chest == game->chest && map_dup->exit_c == 1)
// 	{
// 		free_all(map_dup);
// 		return (1);
// 	}
// 	free_all(map_dup);
// 	return (0);
// }

int	check_floodfill(t_res *game, int fd)
{
    t_res	*map_dup;

    map_dup = init_game();
    read_file(fd, map_dup);
	print_matrix(map_dup->map, map_dup);
    ft_character_pos(map_dup->map, map_dup);
    floodfill(map_dup, map_dup->character_x, map_dup->character_y);

    // Debugging print statements
    printf("Chests found: %d (expected: %d)\n", map_dup->chest, game->chest);
    printf("Exits found: %d (expected: 1)\n", map_dup->exit_c);

    if (map_dup->chest == game->chest && map_dup->exit_c == 1)
    {
        free_all(map_dup);
        return (1);
    }
    free_all(map_dup);
    return (0);
}
void	print_matrix(char **matrix, t_res *dimensions)
{
	ft_printf("Matriz:\n");
	for (int i = 0; i < dimensions->height; i++)
	{
		for (int j = 0; j < dimensions->width; j++)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}
