/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:16 by paromero          #+#    #+#             */
/*   Updated: 2024/05/13 12:41:17 by paromero         ###   ########.fr       */
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
		if (matrix[i][0] != 1 || matrix[i][game->width - 1] != 1)
			return (0);
		i++;
	}
	while (j < game->width)
	{
		if (matrix[0][j] != 1 || matrix[game->height - 1][j] != 1)
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
			if (matrix[i][j] != 32 && matrix[i][j] != 21 && matrix[i][j] != 19)
			{
				if (matrix[i][j] != 1 && matrix[i][j] != 0)
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
		map_dup->exit++;
	floodfill(map_dup, x, y - 1);
	floodfill(map_dup, x, y + 1);
	floodfill(map_dup, x - 1, y);
	floodfill(map_dup, x + 1, y);
}

int	check_floodfill(t_res *game, int fd)
{
	t_res	*map_dup;

	map_dup = init_game();
	read_file(fd, map_dup);
	ft_objects(map_dup->map, map_dup);
	floodfill(map_dup, map_dup->character_x, map_dup->character_y);
	if (map_dup->chest == game->chest && map_dup->exit == 1)
	{
		free_all(map_dup);
		return (1);
	}
	return (0);
}
// void	print_matrix(int matrix[MAX_ROWS][MAX_COLS], res *dimensions)
// {
// 	ft_printf("Matriz:\n");
// 	for (int i = 0; i < dimensions->height; i++)
// 	{
// 		for (int j = 0; j < dimensions->width; j++)
// 		{
// 			printf("%d ", matrix[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

// void	ft_ber(char	*str)
// {
// 	char	*file;

// 	file = ft_strrchr(str, '.');
// 	if (file == 0)
// 	{
// 		perror("El arhcivo no tiene extensión");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (ft_strncmp(file, ".ber", 4) != 0)
// 	{
// 		perror("El archivo no es .ber");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	ft_character_pos(int matrix[MAX_ROWS][MAX_COLS], res *structa)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	structa->character_y = 0;
// 	structa->character_x = 0;
// 	while (i < structa->height)
// 	{
// 		j = 0;
// 		while (j < structa->width)
// 		{
// 			if (matrix[i][j] == 32)
// 			{
// 				structa->character_y = i;
// 				structa->character_x = j;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	ft_empty(int matrix[MAX_ROWS][MAX_COLS])
// {
// 	if (matrix[0][0] == '\0')
// 	{
// 		perror("La matriz está vacía");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	ft_map_checker(int file)
// {
// 	res	dimensions;
// 	int	matrix[MAX_ROWS][MAX_COLS];

// 	read_file(file, matrix, &dimensions);
// 	ft_character_pos(matrix, &dimensions);
// 	ft_empty(matrix);
// 	if (!ft_borders(matrix, &dimensions))
// 	{
// 		perror("La matriz no está rodeada por unos");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!ft_rectangule(matrix, &dimensions))
// 	{
// 		perror("La matriz no es rectangular");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!ft_objects(matrix, &dimensions))
// 	{
// 		perror("La matriz no tiene todos los caracteres");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!ft_caracteres(matrix, &dimensions))
// 	{
// 		perror("La matriz tiene caracteres incorrectos");
// 		exit(EXIT_FAILURE);
// 	}
// }

// int	main(int ac, char **av)
// {
// 	int	file;

// 	ft_ber(av[1]);
// 	file = open(av[1], O_RDONLY);
// 	if (ac == 2)
// 	{
// 		ft_map_checker(file);
// 	}
// 	close (file);
// 	return (0);
// }

int main(int ac, char **av) {
    int file;
    t_res *game;
    int surrounded;
    int rectangular;

    ft_ber(av[1]);
    file = open(av[1], O_RDONLY);
    if (file == -1) {
        perror("Error al abrir archivo");
        exit(EXIT_FAILURE);
    }

    // Llama a la función para leer el archivo y llenar la estructura 'game'
    read_file(file, game);

    // Implementa la lógica para encontrar la posición del personaje en el mapa
    ft_character_pos(game->map, game);

    // Implementa la lógica para verificar si el mapa está vacío
    ft_empty(game->map);

    printf("Ancho: %d\n", game->width);
    printf("Altura: %d\n", game->height);
    printf("Pos_X: %d\n", game->character_x);
    printf("Pos_y: %d\n", game->character_y);

    // Implementa la lógica para verificar si el mapa está rodeado por unos
    surrounded = ft_borders(game->map, game);
    if (surrounded) {
        printf("El mapa está rodeado por unos.\n");
    } else {
        printf("El mapa no está rodeado por unos.\n");
    }
    // Implementa la lógica para verificar si el mapa tiene todos los caracteres necesarios
    int collect = ft_objects(game->map, game);
    if (collect) {
        printf("El mapa tiene todos los caracteres necesarios.\n");
    } else {
        printf("El mapa no tiene todos los caracteres necesarios.\n");
    }

    // Implementa la lógica para verificar si el mapa tiene caracteres incorrectos
    int enemy = ft_caracteres(game->map, game);
    if (enemy) {
        printf("El mapa no tiene caracteres incorrectos.\n");
    } else {
        printf("El mapa tiene caracteres incorrectos.\n");
    }

    // Implementa la lógica para verificar si el flood fill alcanza todos los objetivos
    int reachable = check_floodfill(game, file);
    if (reachable) {
        printf("El flood fill alcanza todos los objetivos.\n");
    } else {
        printf("El flood fill no alcanza todos los objetivos.\n");
    }

    close(file);
    return 0;
}