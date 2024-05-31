/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:44:52 by paromero          #+#    #+#             */
/*   Updated: 2024/05/31 09:24:38 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber(char	*str)
{
	int		len;
	char	*extension;

	len = ft_strlen(str);
	if (len < 4)
	{
		perror("Error:\nEl archivo no tiene extensión");
		exit(EXIT_FAILURE);
	}
	extension = &str[len - 4];
	if (ft_strncmp(extension, ".ber", 4) != 0)
	{
		perror("Error:\nEl archivo no es .ber");
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
		perror("Error:\nLa matriz no está rodeada por unos o no es rectangular");
		exit(EXIT_FAILURE);
	}
	if (!ft_objects(game->map, game))
	{
		perror("Error:\nLa matriz no tiene todos los caracteres");
		exit(EXIT_FAILURE);
	}
	if (!ft_caracteres(game->map, game))
	{
		perror("Error:\nLa matriz tiene caracteres incorrectos");
		exit(EXIT_FAILURE);
	}
	if (!check_floodfill(game, av))
	{
		perror("Error:\nLa salida no está disponible");
		exit(EXIT_FAILURE);
	}
}
