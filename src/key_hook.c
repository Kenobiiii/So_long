/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:55:59 by paromero          #+#    #+#             */
/*   Updated: 2024/05/23 18:53:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_res *game, int dir)
{
	game->map[game->character_y][game->character_x] = FLOOR;
	if (dir == UP)
	{
		game->character_y--;
		(game->player_i)->instances[0].y -= IMG;
	}
	if (dir == RIGHT)
	{
		game->character_x++;
		(game->player_i)->instances[0].x += IMG;
	}
	if (dir == DOWN)
	{
		game->character_y++;
		(game->player_i)->instances[0].y += IMG;
	}
	if (dir == LEFT)
	{
		game->character_x--;
		(game->player_i)->instances[0].x -= IMG;
	}
	game->map[game->character_y][game->character_x] = PLAYER;
	game->move_count++;
	ft_printf("Moves %d\n", game->move_count);
}

void	check_exit_move(t_res *game, int dir)
{
	if (game->chest == 0)
	{
		move_player(game, dir);
		ft_printf("You win. All collectible reached!!\n");
		mlx_terminate(game->mlx);
		free_all(game);
		exit(EXIT_SUCCESS);
	}
}

void	reload_player(t_res *game)
{
	mlx_delete_texture(game->player_t);
	mlx_delete_image(game->mlx, game->player_i);
	game->player_t = mlx_load_png("./sprites/player.png");
	game->player_i = mlx_texture_to_image(game->mlx, game->player_t);
	if (!game->player_i)
		return ;
	mlx_image_to_window(game->mlx, game->player_i,
		game->character_x * 64, game->character_y * 64);
}

void	check_move(t_res *game, int dir, int y, int x)
{
	if (y < game->height && x < game->width && y >= 0 && x >= 0)
	{
		if (game->map[y][x] != WALL)
		{
			if (game->map[y][x] == COLLECT)
			{
				game->map[y][x] = FLOOR;
				game->chest--;
				if (mlx_image_to_window(game->mlx,
						game->floor_i, x * IMG, y * IMG) < 0)
					perror("Error rendering floor.");
				if (game->chest == 0)
					game->exit_c = 1;
				reload_player(game);
				move_player(game, dir);
			}
			else if (game->map[y][x] == MAP_EXIT)
				check_exit_move(game, dir);
			else
				move_player(game, dir);
		}
	}
}

void	ft_hook(mlx_key_data_t keydata, void *game)
{
	t_res	*temp;

	temp = game;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		check_move(temp, UP, temp->character_y - 1, temp->character_x);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		check_move(temp, DOWN, temp->character_y + 1, temp->character_x);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		check_move(temp, RIGHT, temp->character_y, temp->character_x + 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		check_move(temp, LEFT, temp->character_y, temp->character_x - 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_all(temp);
		exit (0);
	}
}
