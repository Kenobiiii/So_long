/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:09:51 by paromero          #+#    #+#             */
/*   Updated: 2024/05/21 19:04:32 by paromero         ###   ########.fr       */
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
	{
		ft_printf("Uso: ./so_long mapa.ber.\n");
		exit(EXIT_FAILURE);
	}
	ft_ber(av[1]);
	ft_map_checker(av, game);
	ft_png_to_txt(game);
	load_imgs(game);
	load_player(game);
	mlx_key_hook(game->mlx, &ft_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free (game);
	return (0);
}
