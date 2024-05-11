/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:56:32 by paromero          #+#    #+#             */
/*   Updated: 2024/05/09 13:04:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "./MLX42/include/MLX42/MLX42.h"
#include "./libft/libft.h"
#include <stdbool.h>
#include "./src/so_long.h"

typedef struct {
	int width;
	int height;
} res;

static mlx_image_t	*g_image;

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_hook(void	*param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_Q))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_image->instances[0].x += 5;
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	t_res result;

	result.height = 15;
	result.width = 10;
	mlx = mlx_init(result.width * 64, result.height * 64, "MLX42", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	texture = mlx_load_png("./sprites/Jorge.png");
	if (texture == NULL)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	g_image = mlx_texture_to_image(mlx, texture);
	if (!g_image)
		perror("Error en la img");
	if (mlx_image_to_window(mlx, g_image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
