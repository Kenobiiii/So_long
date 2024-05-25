/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:13 by paromero          #+#    #+#             */
/*   Updated: 2024/05/25 12:24:15 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_png_to_txt(t_res *game)
{
	game->mlx = mlx_init(game->width * 64,
			game->height * 64, "so_long", false);
	game->floor_t = mlx_load_png("sprites/floor.png");
	game->wall_t = mlx_load_png("sprites/wall.png");
	game->exit_t = mlx_load_png("sprites/exit.png");
	game->player_t = mlx_load_png("sprites/player.png");
	game->collect_t = mlx_load_png("sprites/colective.png");
	if (!game->floor_t || !game->wall_t
		|| !game->exit_t || !game->player_t || !game->collect_t)
	{
		perror("Fallo al cargar las texturas");
		exit(EXIT_FAILURE);
	}
	game->floor_i = mlx_texture_to_image(game->mlx, game->floor_t);
	game->wall_i = mlx_texture_to_image(game->mlx, game->wall_t);
	game->exit_i = mlx_texture_to_image(game->mlx, game->exit_t);
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t);
	game->collect_i = mlx_texture_to_image(game->mlx, game->collect_t);
	if (!game->floor_i || !game->wall_i
		|| !game->exit_i || !game->player_i || !game->collect_i)
	{
		perror("Fallo al cargar las imágenes");
		exit(EXIT_FAILURE);
	}
}

void	load_imgs(t_res *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == FLOOR || game->map[y][x] == COLLECT
				|| game->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, game->floor_i, x * IMG, y * IMG);
			if (game->map[y][x] == WALL)
				mlx_image_to_window(game->mlx, game->wall_i, x * IMG, y * IMG);
			if (game->map[y][x] == COLLECT)
				mlx_image_to_window(game->mlx, game->collect_i, x * IMG,
					y * IMG);
			if (game->map[y][x] == MAP_EXIT)
				mlx_image_to_window(game->mlx, game->exit_i, x * IMG, y * IMG);
			x++;
		}
		y++;
	}
}

void	load_player(t_res *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == PLAYER)
				mlx_image_to_window(game->mlx, game->player_i, x * IMG,
					y * IMG);
			x++;
		}
		y++;
	}
}
