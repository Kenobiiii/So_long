/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:43:16 by paromero          #+#    #+#             */
/*   Updated: 2024/05/09 12:52:27 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(int fd, int matrix[MAX_ROWS][MAX_COLS], t_res *dimensions)
{
	char	*line;
	int		len;
	int		i;

	dimensions->height = 0;
	line = get_next_line(fd);
	while (dimensions->height < MAX_ROWS && line != NULL)
	{
		len = ft_strlen(line);
		dimensions->width = len;
		i = 0;
		while (i < len)
		{
			matrix[dimensions->height][i] = line[i] - '0';
			i++;
		}
		dimensions->height++;
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_borders(int matrix[MAX_ROWS][MAX_COLS], t_res *dimensions)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dimensions->height)
	{
		if (matrix[i][0] != 1 || matrix[i][dimensions->width - 1] != 1)
			return (0);
		i++;
	}
	while (j < dimensions->width)
	{
		if (matrix[0][j] != 1 || matrix[dimensions->height - 1][j] != 1)
			return (0);
		j++;
	}
	return (1);
}

int	ft_rectangule(int matrix[MAX_ROWS][MAX_COLS], t_res *structa)
{
	int	i;
	int	largo;

	largo = structa->width;
	while (i < largo)
	{
		if (structa->width != largo)
			return (0);
		i++;
	}
	return (1);
}

int	ft_objects(int matrix[MAX_ROWS][MAX_COLS], t_res *structa)
{
	int		i;
	int		j;

	i = 0;
	while (i < structa->height)
	{
		j = 0;
		while (j < structa->width)
		{
			if (matrix[i][j] == 32)
				structa->character++;
			else if (matrix[i][j] == 19)
				structa->chest++;
			else if (matrix[i][j] == 21)
				structa->exit++;
			j++;
		}
		i++;
	}
	if (structa->character == 1 && structa->exit == 1 && structa->chest >= 1)
		return (1);
	else
		return (0);
}

int	ft_caracteres(int matrix[MAX_ROWS][MAX_COLS], t_res *structa)
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

// int	main(int ac, char **av)
// {
// 	int	file;
// 	int	matrix[MAX_ROWS][MAX_COLS];
// 	res	dimensions;
// 	int	surrounded;
// 	int rectangular;

// 	ft_ber(av[1]);
// 	file = open(av[1], O_RDONLY);
// 	if (file == -1)
// 	{
// 		perror("Error al abrir archivo");
// 		exit(EXIT_FAILURE);
// 	}
// 	read_file(file, matrix, &dimensions);
// 	ft_character_pos(matrix, &dimensions);
// 	ft_empty(matrix);
// 	ft_printf("Ancho: %d\n", dimensions.width);
// 	ft_printf("Altura: %d\n", dimensions.height);
// 	ft_printf("Pos_X: %d\n", dimensions.character_x);
// 	ft_printf("Pos_y: %d\n", dimensions.character_y);
// 	print_matrix(matrix, &dimensions);
// 	surrounded = ft_borders(matrix, &dimensions);
// 	if (surrounded)
// 	{
// 		ft_printf("La matriz está rodeada por unos.\n");
// 	}
// 	else
// 	{
// 		ft_printf("La matriz no está rodeada por unos.\n");
// 	}
// 	rectangular = ft_rectangule(matrix, &dimensions);
// 	if (rectangular)
// 	{
// 		ft_printf("La matriz es rectangular.\n");
// 	}
// 	else
// 	{
// 		ft_printf("La matriz no es resctangular.\n");
// 	}
// 	int collect = ft_objects(matrix, &dimensions);
// 	if (collect)
// 	{
// 		ft_printf("La matriz tiene todos los caract.\n");
// 	}
// 	else
// 	{
// 		ft_printf("La matriz no tiene todos los carac.\n");
// 	}
// 	int enemy = ft_caracteres(matrix, &dimensions);
// 	if (enemy)
// 	{
// 		ft_printf("La matriz es correcta.\n");
// 	}
// 	else
// 	{
// 		ft_printf("La matriz no es correcta.\n");
// 	}
// 	return (0);
// }
