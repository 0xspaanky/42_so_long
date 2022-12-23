/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:29:38 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/23 02:57:06 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(t_window *window, int y, int x, t_colors color)
{
    if (x < 0 || x >= get_x(window->save) || y < 0 || y >= get_y(window->save) || window->save[y][x] == color.new) {
        return;
    }
    if (window->save[y][x] == '1' || window->save[y][x] == color.old)
        return ;
    window->save[y][x] = color.new;
    fill(window, y, x + 1, color);
    fill(window, y, x - 1, color);
    fill(window, y + 1, x, color);
    fill(window, y - 1, x, color);
}

void flood_fill(t_window *window, int y, int x, t_colors color)
{
    if (window->save[y][x] == color.new)
        return ;
    fill(window, y, x, color);
}

int check_col_ex(t_window *window, char c)
{
    int x;
    int y;
    int count;
    
    y = 0;
    count = 0;
    while(window->save[y])
    {
        x = 0;
        while(window->save[y][x])
        {
            if(window->save[y][x] == c)
                count++;
            x++;
        }
        y++;
    }
    return (count);
}

void player_pos(t_window *window)
{
    int x;
    int y;
    
    y = 0;
    while(y < get_y(window->map))
    {
        x = 0;
        while(x < get_x(window->map))
        {
            if(window->map[y][x] == 'P')
            {
                window->plyr_pos.x = x;
                window->plyr_pos.y = y;
            }
            x++;
        }
        y++;
    }
}

void check_map_ff(t_window *window)
{
    t_colors color;

    color.new = 'Q';
    color.old = 'E';
    flood_fill(window, window->plyr_pos.y, window->plyr_pos.x, color);
    if(check_col_ex(window, 'C'))
    {
        errors(5);
    }
    color.new = 'F';
    color.old = '1';
    flood_fill(window, window->plyr_pos.y, window->plyr_pos.x, color);
    if(check_col_ex(window, 'E'))
    { 
        errors(5);
    }
}
