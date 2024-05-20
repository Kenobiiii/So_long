/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:44:52 by paromero          #+#    #+#             */
/*   Updated: 2024/05/20 20:03:34 by paromero         ###   ########.fr       */
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

void	ft_map_checker(char **av, t_res	*game)
{
	game->fd = open(av[1], O_RDONLY);
	read_file(game->fd, game);
	close (game->fd);
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
	if (!check_floodfill(game, av))
	{
		perror("La salida no está disponible");
		exit(EXIT_FAILURE);
	}
}

// int	main(int ac, char **av)
// {
// 	t_res	*game;

// 	game = init_game();
// 	if (ac == 2)
// 	{
// 		ft_ber(av[1]);
// 		ft_map_checker(av, game);
// 	}
// 	else
// 		ft_printf("Uso: ./so_long mapa.ber\n");
// 	free (game);
// 	return (0);
// }
