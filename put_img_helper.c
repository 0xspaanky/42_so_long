/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:33:36 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/03 01:04:28 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.background,
		window->h * 100, window->w * 100);
	mlx_put_image_to_window(window->mlx, window->win, window->img.wall,
		window->h * 100, window->w * 100);
}

void	put_collect(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.background,
		window->h * 100, window->w * 100);
	mlx_put_image_to_window(window->mlx, window->win, window->img.collect,
		window->h * 100, window->w * 100);
}

void	put_hero(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.background,
		window->h * 100, window->w * 100);
	mlx_put_image_to_window(window->mlx, window->win, window->img.hero,
		window->h * 100, window->w * 100);
}

void	put_exit(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.background,
		window->h * 100, window->w * 100);
	mlx_put_image_to_window(window->mlx, window->win, window->img.closed_door,
		window->h * 100, window->w * 100);
}

void	put_enemy(t_window *window)
{
	mlx_put_image_to_window(window->mlx, window->win, window->img.background,
		window->h * 100, window->w * 100);
	mlx_put_image_to_window(window->mlx, window->win, window->img.enemy,
		window->h * 100, window->w * 100);
}
