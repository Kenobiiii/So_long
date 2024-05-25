/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:22:44 by paromero          #+#    #+#             */
/*   Updated: 2024/05/25 12:11:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	free_map_txt(t_res *game)
{
	if (game->collect_t)
		mlx_delete_texture(game->collect_t);
	if (game->floor_t)
		mlx_delete_texture(game->floor_t);
	if (game->wall_i)
		mlx_delete_texture(game->wall_t);
	if (game->player_t)
		mlx_delete_texture(game->player_t);
	if (game->exit_t)
		mlx_delete_texture(game->exit_t);
	if (game->exit_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->wall_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->floor_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->collect_i)
		mlx_delete_image(game->mlx, game->exit_i);
	if (game->player_i)
		mlx_delete_image(game->mlx, game->player_i);
}

void	free_all(t_res	*game)
{
	if (game)
	{
		if (game->map)
			free_matriz(game->map);
		if (game)
			free_map_txt(game);
		free(game);
	}
}
