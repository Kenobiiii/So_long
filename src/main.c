/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:09:51 by paromero          #+#    #+#             */
/*   Updated: 2024/06/04 09:44:20 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_line(t_res *game)
{
	if (game->map != NULL)
	{
		free(game->map);
		game->map = NULL;
	}
	perror("Error:\nEl archivo esta vacío");
	exit(EXIT_FAILURE);
}

void	ft_rectangule(char **av)
{
	int		len;
	char	*line;
	int		initiallen;
	int		fd;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	initiallen = len;
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (len != initiallen)
		{
			perror("Error:\n The map is not a rectangle");
			exit(EXIT_FAILURE);
		}
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
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
