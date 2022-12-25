/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:27:56 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/24 18:20:13 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int i)
{
	if (i == 1)
		ft_printf("\033[1;31m🛑ERROR: can't read the wall!");
	else if (i == 2)
		ft_printf("\033[1;31m🛑ERROR: check the map components!");
	else if (i == 3)
		ft_printf("\033[1;31m🛑ERROR: invalid map name!");
	else if (i == 4)
		ft_printf("\033[1;31m🛑ERROR: map's not rectangular!");
	else if (i == 5)
		ft_printf("\033[1;31m🛑ERROR: invalid path..!");
	else if (i == 6)
		ft_printf("\033[1;31m🛑ERROR: new line found! remove it..!");
	else if (i == 7)
		ft_printf("\033[1;31m🛑ERROR: different character found! remove it..!");
	else if (i == 8)
		ft_printf("\033[1;31m🛑ERROR: empty map!");
	exit(0);
}