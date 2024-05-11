/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:13 by paromero          #+#    #+#             */
/*   Updated: 2024/05/11 19:48:18 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_png_to_txt(t_res *juego)
{
	juego->mlx = mlx_init(juego->width * 64,
			juego->height * 64, "so_long", false);
	juego->floor_t = mlx_load_png(".sprite/floor.png");
	juego->wall_t = mlx_load_png(".sprite/wall.png");
	juego->exit_t = mlx_load_png(".sprite/exit.png");
	juego->player_t = mlx_load_png(".sprite/player.png");
	juego->colective_t = mlx_load_png(".sprite/colective.png");
	if (!juego_floor_t || !juego_wall_t
		|| !juego_exit_t || !juego_player_t || !juego_colective_t)
		return (0);
	juego->floor_i = mlx_texture_to_image(juego->mlx, juego->floor_t);
	juego->wall_i = mlx_texture_to_image(juego->mlx, juego->wall_t);
	juego->exit_i = mlx_texture_to_image(juego->mlx, juego->exit_t);
	juego->player_i = mlx_texture_to_image(juego->mlx, juego->player_t);
	juego->colective_i = mlx_texture_to_image(juego->mlx, juego->colective_t);
	if (!juego_floor_i || !juego_wall_i
		|| !juego_exit_i || !juego_player_i || !juego_colective_i)
		return (0);
}
