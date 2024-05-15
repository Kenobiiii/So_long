/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:00:26 by paromero          #+#    #+#             */
/*   Updated: 2024/05/15 11:37:02 by paromero         ###   ########.fr       */
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
# define IMG			64
# define WALL				'1'
# define FLOOR 				'0'
# define COLLECT  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define VISITED			'V'

typedef struct s_res
{
	char			**map;
	int				width;
	int				height;
	int				chest;
	int				exit_c;
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
void		read_file(int fd, t_res *dimensions);
void		free_all(t_res	*juego);
void		free_matriz(char **matriz, t_res	*game);
void		floodfill(t_res *map_dup, int x, int y);
void		ft_ber(char	*str);
void		ft_character_pos(char **matrix, t_res *structa);
void		ft_empty(char **matrix);
void		print_matrix(char **matrix, t_res *dimensions);

//int
int			ft_borders(char **matrix, t_res *dimensions);
int			ft_rectangule(char **matrix, t_res *structa);
int			ft_objects(char **matrix, t_res *structa);
int			ft_caracteres(char **matrix, t_res *structa);
int			check_floodfill(t_res *game, int fd);

//structs
t_res		*init_game(void);

#endif