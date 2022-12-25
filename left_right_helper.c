/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:22:22 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 14:41:40 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void left_helper_0(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->plyr_pos.x--;
}

void left_helper_1(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->map[win->plyr_pos.y ][win->plyr_pos.x + 1] = '0';
    win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P'; 
    win->count_moves++;
    ft_printf("Move number : %d\n", win->count_moves);
}

void right_helper_0(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->plyr_pos.x++;
}

void right_helper_1(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->map[win->plyr_pos.y][win->plyr_pos.x - 1] = '0';
    win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P';
    win->count_moves++;
    ft_printf("Move number : %d\n", win->count_moves);
}
