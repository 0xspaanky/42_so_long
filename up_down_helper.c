/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_d_l_r_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:51:53 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 14:15:57 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void up_helper_0(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->plyr_pos.y--;
}

void up_helper_1(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P';
    win->map[win->plyr_pos.y + 1][win->plyr_pos.x] = '0';
    win->count_moves++;
    ft_printf("Move number : %d\n", win->count_moves);
}

void down_helper_0(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->plyr_pos.y++;
}

void down_helper_1(t_window *win)
{
    mlx_put_image_to_window(win->mlx, win->win, win->img.hero, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
    win->map[win->plyr_pos.y - 1][win->plyr_pos.x] = '0';
    win->map[win->plyr_pos.y][win->plyr_pos.x] = 'P';
    win->count_moves++;
    ft_printf("Move number : %d\n", win->count_moves);
}

void congrats(t_window *win)
{
    ft_printf("\033[1;32mCongratulations, u finished the game!");
    mlx_destroy_window(win->mlx,win->win);
    exit(0);
}