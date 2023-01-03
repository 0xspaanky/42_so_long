/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_and_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:33:10 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/27 15:14:09 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x(char **str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

int	get_y(char **str)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i][0] == '1')
			counter++;
		i++;
	}
	return (counter);
}
