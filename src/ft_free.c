/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:22:44 by paromero          #+#    #+#             */
/*   Updated: 2024/05/20 17:48:17 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matriz(char **matriz, t_res *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	free_all(t_res	*game)
{
	if (game)
	{
		if (game->map)
		{
			free_matriz(game->map, game);
			game->map = NULL;
		}
		// if (game)
		// 	free_map_txt(game);
		free(game);
		game = NULL;
	}
}
