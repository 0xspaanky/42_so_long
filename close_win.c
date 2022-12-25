/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:45:57 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 03:09:44 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win_esc(int keycode, t_window *window)
{
    if (keycode == 53)
    {
        mlx_destroy_window(window->mlx, window->win);
        exit(0);
    }
	return (0);
}

int	close_win_cross( t_window *window)
{
    mlx_destroy_window(window->mlx, window->win);
    exit(0);
	return (0);
}

void exit_move(t_window window)
{
    mlx_hook(window.win, 2, 0, close_win_esc, &window);
    mlx_hook(window.win, 17, 0, close_win_cross, &window);
}