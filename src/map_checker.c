/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:44:52 by paromero          #+#    #+#             */
/*   Updated: 2024/05/11 19:28:34 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber(char	*str)
{
	char	*file;

	file = ft_strrchr(str, '.');
	if (file == 0)
	{
		perror("El arhcivo no tiene extensión");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(file, ".ber", 4) != 0)
	{
		perror("El archivo no es .ber");
		exit(EXIT_FAILURE);
	}
}

void	ft_character_pos(int matrix[MAX_ROWS][MAX_COLS], t_res *structa)
{
	int	i;
	int	j;

	i = 0;
	structa->character_y = 0;
	structa->character_x = 0;
	while (i < structa->height)
	{
		j = 0;
		while (j < structa->width)
		{
			if (matrix[i][j] == 32)
			{
				structa->character_y = i;
				structa->character_x = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_empty(int matrix[MAX_ROWS][MAX_COLS])
{
	if (matrix[0][0] == '\0')
	{
		perror("La matriz está vacía");
		exit(EXIT_FAILURE);
	}
}

void	ft_map_checker(int file)
{
	t_res	dimensions;
	int		matrix[MAX_ROWS][MAX_COLS];

	read_file(file, matrix, &dimensions);
	ft_character_pos(matrix, &dimensions);
	ft_empty(matrix);
	if (!ft_borders(matrix, &dimensions) || !ft_rectangule(matrix, &dimensions))
	{
		perror("La matriz no está rodeada por unos o no es rectangular");
		exit(EXIT_FAILURE);
	}
	if (!ft_objects(matrix, &dimensions))
	{
		perror("La matriz no tiene todos los caracteres");
		exit(EXIT_FAILURE);
	}
	if (!ft_caracteres(matrix, &dimensions))
	{
		perror("La matriz tiene caracteres incorrectos");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int	file;

	if (ac == 2)
	{
		ft_ber(av[1]);
		file = open(av[1], O_RDONLY);
		ft_map_checker(file);
		close (file);
	}
	else
		ft_printf("Uso: ./so_long mapa.ber\n");
	return (0);
}
