/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:20:38 by paromero          #+#    #+#             */
/*   Updated: 2024/05/06 15:37:05 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int ac, char **av)
{
    av[1] = 0;
    if (ac == 2)
    {
        ft_printf("%s\n", "correct");
    }
    else
        ft_printf("%s\n", "Uso: ./so_long 'mapa.ber'");
    return(0);
}