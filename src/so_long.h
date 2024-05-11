/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:26 by paromero          #+#    #+#             */
/*   Updated: 2024/05/11 19:26:15 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define MAX_ROWS 100
# define MAX_COLS 100

typedef struct s_res
{
	int				width;
	int				height;
	int				chest;
	int				exit;
	int				character;
	int				character_y;
	int				character_x;
	mlx_t			*mlx;
	mlx_image_t		*floor_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*player_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*collect_i;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*collect_t;
}	t_res;

//void
void	read_file(int fd, int matrix[MAX_ROWS][MAX_COLS], t_res *dimensions);

//int
int		ft_borders(int matrix[MAX_ROWS][MAX_COLS], t_res *dimensions);
int		ft_rectangule(int matrix[MAX_ROWS][MAX_COLS], t_res *structa);
int		ft_objects(int matrix[MAX_ROWS][MAX_COLS], t_res *structa);
int		ft_caracteres(int matrix[MAX_ROWS][MAX_COLS], t_res *structa);

#endif