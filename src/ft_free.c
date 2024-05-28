/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:22:44 by paromero          #+#    #+#             */
/*   Updated: 2024/05/28 09:50:47 by paromero         ###   ########.fr       */
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

void	free_all(t_res	*game)
{
	free_matriz(game->map);
}
