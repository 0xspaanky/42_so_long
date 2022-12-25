/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_d_l_r_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:06:50 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 14:45:50 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_window *win)
{
    render_door(win);
    if(win->map[win->plyr_pos.y - 1][win->plyr_pos.x] == 'E' && win->pec.nb_col == 0)
        {
            win->count_moves++;
            ft_printf("Move number : %d\n", win->count_moves); 
            congrats(win);
        }
    else if(win->map[win->plyr_pos.y - 1][win->plyr_pos.x] != '1')
    {
        if(win->map[win->plyr_pos.y - 1][win->plyr_pos.x] == '0')
        {
            up_helper_0(win);
            up_helper_1(win);
        }
        else if(win->map[win->plyr_pos.y - 1][win->plyr_pos.x] == 'C')
        {
            up_helper_0(win);
            mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
            up_helper_1(win);
            win->pec.nb_col--;
        }
    }
}

void move_down(t_window *win)
{
    render_door(win);
    if(win->map[win->plyr_pos.y + 1][win->plyr_pos.x] == 'E' && win->pec.nb_col == 0)
    {
        win->count_moves++;
        ft_printf("Move number : %d\n", win->count_moves); 
        congrats(win);
    }
    else if(win->map[win->plyr_pos.y + 1][win->plyr_pos.x] != '1')
    {
        if(win->map[win->plyr_pos.y + 1][win->plyr_pos.x] == '0')
        {
            down_helper_0(win);
            down_helper_1(win);
        }
    else if(win->map[win->plyr_pos.y + 1][win->plyr_pos.x] == 'C')
        {
            down_helper_0(win);
            mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
            down_helper_1(win);
            win->pec.nb_col--;
        }
    }
}

void move_right(t_window *win)
{
    render_door(win);
    if(win->map[win->plyr_pos.y][win->plyr_pos.x + 1] == 'E' && win->pec.nb_col == 0)
    {
        win->count_moves++;
        ft_printf("Move number : %d\n", win->count_moves); 
        congrats(win);
    }
    else if(win->map[win->plyr_pos.y][win->plyr_pos.x + 1] != '1')
    {
        if(win->map[win->plyr_pos.y][win->plyr_pos.x + 1] == '0')
        {
            right_helper_0(win);
            right_helper_1(win);
        }
        else if(win->map[win->plyr_pos.y][win->plyr_pos.x + 1] == 'C')
        {
            right_helper_0(win);
            mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
            right_helper_1(win); 
            win->pec.nb_col--;
        }
    }
}

void move_left(t_window *win)
{
    render_door(win);
    if(win->map[win->plyr_pos.y][win->plyr_pos.x - 1] == 'E' && win->pec.nb_col == 0)   
    {
        win->count_moves++;
        ft_printf("Move number : %d\n", win->count_moves); 
        congrats(win);
    }
    else if(win->map[win->plyr_pos.y][win->plyr_pos.x - 1] != '1')
    {
        if(win->map[win->plyr_pos.y][win->plyr_pos.x - 1] == '0')
        {
            left_helper_0(win);
            left_helper_1(win);
        }
        else if(win->map[win->plyr_pos.y][win->plyr_pos.x - 1] == 'C')
        {
            left_helper_0(win);
            mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->plyr_pos.x * 100, win->plyr_pos.y * 100);
            left_helper_1(win); 
            win->pec.nb_col--;
        }
    }
}

int key_hook(int keycode, t_window *win)
{
    if(keycode == 126 || keycode == 13)
        move_up(win);
    else if(keycode == 125 || keycode == 1)
        move_down(win);
    else if(keycode == 124 || keycode == 2)
        move_right(win);
    else if(keycode == 123 || keycode == 0)
        move_left(win);
    return (0);
}