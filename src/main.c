/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:09:51 by paromero          #+#    #+#             */
/*   Updated: 2024/06/03 09:42:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_line(t_res *game)
{
	free(game);
	perror("Error:\nEl archivo esta vacío");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	static t_res	game;

	if (ac != 2)
	{
		ft_printf("Uso: ./so_long mapa.ber.\n");
		exit(EXIT_FAILURE);
	}
	ft_ber(av[1]);
	ft_map_checker(av, &game);
	ft_png_to_txt(&game);
	load_imgs(&game);
	load_player(&game);
	mlx_key_hook(game.mlx, &ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_all(&game);
	return (0);
}
