/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:09:51 by paromero          #+#    #+#             */
/*   Updated: 2024/05/20 20:04:11 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_res	*init_game(void)
{
	t_res	*game;

	game = (t_res *)ft_calloc(1, sizeof(t_res));
	if (!game)
		perror("Error while allocating memory");
	return (game);
}

int main(int ac, char **av)
{
	t_res *game;

	game = init_game();
	if (!game)
		perror("Memoria mal alocada");
	if (ac != 2)
		perror("Uso: ./so_long mapa.ber");
	ft_ber(av[1]);
	ft_map_checker(av, game);
	
	free (game);
	return (0);
}
