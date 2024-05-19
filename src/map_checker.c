/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:44:52 by paromero          #+#    #+#             */
/*   Updated: 2024/05/15 11:49:03 by paromero         ###   ########.fr       */
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

void	ft_character_pos(char **matrix, t_res *structa)
{
	int	i;
	int	j;

	i = 0;
	// structa->character_y = 0;
	// structa->character_x = 0;
	while (i < structa->height)
	{
		j = 0;
		while (j < structa->width)
		{
			if (matrix[i][j] == PLAYER)
			{
				structa->character_y = i;
				structa->character_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_objects(char **matrix, t_res *structa)
{
	int		i;
	int		j;

	i = 0;
	while (i < structa->height)
	{
		j = 0;
		while (j < structa->width)
		{
			if (matrix[i][j] == PLAYER)
				structa->character++;
			else if (matrix[i][j] == COLLECT)
				structa->chest++;
			else if (matrix[i][j] == MAP_EXIT)
				structa->exit_c++;
			j++;
		}
		i++;
	}
	if (structa->character == 1 && structa->exit_c == 1 && structa->chest >= 1)
		return (1);
	else
		return (0);
}

void	ft_map_checker(int	fd, t_res	*game)
{
	read_file(fd, game);
	print_matrix(game->map, game);
	ft_character_pos(game->map, game);
	if (!ft_borders(game->map, game))
	{
		perror("La matriz no está rodeada por unos o no es rectangular");
		exit(EXIT_FAILURE);
	}
	if (!ft_objects(game->map, game))
	{
		perror("La matriz no tiene todos los caracteres");
		exit(EXIT_FAILURE);
	}
	if (!ft_caracteres(game->map, game))
	{
		perror("La matriz tiene caracteres incorrectos");
		exit(EXIT_FAILURE);
	}
	if (!check_floodfill(game, fd))
	{
		perror("La salida no está disponible");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	int		file;
	int		file2;
	char	*buffer[1];
	t_res	*game;

	game = init_game();
	if (ac == 2)
	{
		ft_ber(av[1]);
		file = open(av[1], O_RDONLY);
		file2 = open(av[1], O_RDONLY);
		if (read(file, buffer, sizeof(buffer)) == 0)
		{
			perror ("El archivo está vacío");
			exit(EXIT_FAILURE);
		}
		close (file);
		ft_map_checker(file2, game);
	}
	else
		ft_printf("Uso: ./so_long mapa.ber\n");
	free (game);
	close (file2);
	return (0);
}
