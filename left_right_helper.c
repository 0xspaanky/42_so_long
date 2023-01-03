/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:22:22 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/02 19:08:21 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_helper_0(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.background,
		win->plyr_pos.x * 100, win->plyr_pos.y * 100);
	win->plyr_pos.x--;
}

void	left_helper_1(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x
		* 100, win->plyr_pos.y * 100);
	win->map[win->plyr_pos.y][win->plyr_pos.x + 1] = '0';
	win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P';
	win->move_nbr = ft_itoa(win->count_moves);
	win->moves_text = join_both("Move nbr  ", win->move_nbr);
	mlx_put_image_to_window(win->mlx, win->win, win->img.wall, 100, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->img.wall, 0, 0);
	mlx_string_put(win->mlx, win->win, 5, 10, 0xFFFFFF, win->moves_text);
	win->count_moves++;
}

void	right_helper_0(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.background,
		win->plyr_pos.x * 100, win->plyr_pos.y * 100);
	win->plyr_pos.x++;
}

void	right_helper_1(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x
		* 100, win->plyr_pos.y * 100);
	win->map[win->plyr_pos.y][win->plyr_pos.x - 1] = '0';
	win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P';
	win->move_nbr = ft_itoa(win->count_moves);
	win->moves_text = join_both("Move nbr  ", win->move_nbr);
	mlx_put_image_to_window(win->mlx, win->win, win->img.wall, 100, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->img.wall, 0, 0);
	mlx_string_put(win->mlx, win->win, 5, 10, 0xFFFFFF, win->moves_text);
	win->count_moves++;
}
