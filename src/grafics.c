/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:13 by paromero          #+#    #+#             */
/*   Updated: 2024/05/21 19:03:27 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_png_to_txt(t_res *juego)
{
	juego->mlx = mlx_init(juego->width * 64,
			juego->height * 64, "so_long", false);
	juego->floor_t = mlx_load_png("sprites/floor.png");
	juego->wall_t = mlx_load_png("sprites/wall.png");
	juego->exit_t = mlx_load_png("sprites/exit.png");
	juego->player_t = mlx_load_png("sprites/player.png");
	juego->collect_t = mlx_load_png("sprites/colective.png");
	if (!juego->floor_t || !juego->wall_t
		|| !juego->exit_t || !juego->player_t || !juego->collect_t)
		{
			perror("Fallo al cargar las texturas");
			exit(EXIT_FAILURE);
		}
	juego->floor_i = mlx_texture_to_image(juego->mlx, juego->floor_t);
	juego->wall_i = mlx_texture_to_image(juego->mlx, juego->wall_t);
	juego->exit_i = mlx_texture_to_image(juego->mlx, juego->exit_t);
	juego->player_i = mlx_texture_to_image(juego->mlx, juego->player_t);
	juego->collect_i = mlx_texture_to_image(juego->mlx, juego->collect_t);
	if (!juego->floor_i || !juego->wall_i
		|| !juego->exit_i || !juego->player_i || !juego->collect_i)
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