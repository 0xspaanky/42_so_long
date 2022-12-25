/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:11:50 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 14:51:15 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void door_pos(t_window *window)
{
    int x;
    int y;
    
    y = 0;
    while(y < get_y(window->map))
    {
        x = 0;
        while(x < get_x(window->map))
        {
            if(window->map[y][x] == 'E')
            {
                window->door.door_pos_x = x;
                window->door.door_pos_y = y;
            }
            x++;
        }
        y++;
    }
}

void render_door(t_window *win)
{
    door_pos(win);
    //player_pos(win);
    if(win->pec.nb_col == 0)
    {
        mlx_put_image_to_window(win->mlx, win->win, win->img.background, win->door.door_pos_x * 100, win->door.door_pos_y * 100);
        mlx_put_image_to_window(win->mlx, win->win, win->img.open_door, win->door.door_pos_x * 100, win->door.door_pos_y * 100);
    }
}