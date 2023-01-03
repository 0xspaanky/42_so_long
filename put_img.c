/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:13:23 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/03 15:54:01 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cooperate_with_put_img_to_window(t_window *window)
{
	if (window->map[window->y][window->x] == '0')
		mlx_put_image_to_window(window->mlx, window->win,
			window->img.background, window->h * 100, window->w * 100);
	else if (window->map[window->y][window->x] == '1')
		put_wall(window);
	else if (window->map[window->y][window->x] == 'C')
		put_collect(window);
	else if (window->map[window->y][window->x] == 'P')
		put_hero(window);
	else if (window->map[window->y][window->x] == 'E')
		put_exit(window);
}

void	put_img_to_window(t_window *window)
{
	window->y = 0;
	window->w = 0;
	while (window->map[window->y])
	{
		window->x = 0;
		window->h = 0;
		while (window->map[window->y][window->x])
		{
			cooperate_with_put_img_to_window(window);
			window->x++;
			window->h++;
		}
		window->y++;
		window->w++;
	}
}

void	xpm_to_img(t_window *index)
{
	int	x;
	int	y;

	index->img.wall = mlx_xpm_file_to_image(index->mlx, "./img/wall.xpm", &x,
			&y);
	index->img.hero = mlx_xpm_file_to_image(index->mlx, "./img/hero.xpm", &x,
			&y);
	index->img.background = mlx_xpm_file_to_image(index->mlx,
			"./img/background.xpm", &x, &y);
	index->img.collect = mlx_xpm_file_to_image(index->mlx,
			"./img/collect.xpm", &x, &y);
	index->img.closed_door = mlx_xpm_file_to_image(index->mlx,
			"./img/door_closed.xpm", &x, &y);
	index->img.open_door = mlx_xpm_file_to_image(index->mlx,
			"./img/door_open.xpm", &x, &y);
}
