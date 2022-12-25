/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:49:30 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/24 18:25:32 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_x_wall(t_window *window)
{
    int i;
    int j;
    
    i = 0;
    while(window->map[0][i])
    {
        if(window->map[0][i] != '1')
        {
            errors(1);
        }
        i++;
    }
    i = 0;
    j = get_y(window->map) - 1;
    while(window->map[j][i])
    {
        if(window->map[j][i] != '1')
        {
            errors(1);
        }
        i++;
    }
}

void check_y_wall(t_window *window)
{
    int i;
    int j;
    
    i = 0;
    while (i < get_y(window->map))
    {
        if(window->map[i][0] != '1')
        {
            errors(1);
        }
        i++;
    }
    i = 0;
    j = get_x(window->map) - 1;
    
    while(i < get_y(window->map))
    {
        if(window->map[i][j] != '1')
        {
            errors(1);
        }
        i++;
    }
}

void count_pec(t_window *window)
{
    int x;
    int y;
    
    y = -1;
    window->pec.nb_pl = 0;
    window->pec.nb_exit = 0;
    window->pec.nb_col = 0;
    while(window->map[++y])
    {
        x = 0;
        while(window->map[y][x])
        {
            if(window->map[y][x] == 'P')
                window->pec.nb_pl++;
            else if(window->map[y][x] == 'E')
                window->pec.nb_exit++;
            else if(window->map[y][x] == 'C')
                window->pec.nb_col++;
            else if(window->map[y][x] != '0' && window->map[y][x] != '1')
                errors(7);
            x++;
        }
    }
}

void check_pl_ex_col(t_window *window)
{
    count_pec(window);
    if(window->pec.nb_col == 0)
    {
        ft_printf("\033[1;31m🛑At least there should be a collectible\n");
        exit(0);
    }
    else if (window->pec.nb_exit != 1)
    {
        ft_printf("\033[1;31m🛑There should be one and only one exit\n");
        exit(0);
    }
    else if (window->pec.nb_pl != 1)
    {
        ft_printf("\033[1;31m🛑There should be one and only one player\n");
        exit(0);
    }
}

void check_map(t_window *window)
{
    check_rectangular(window);
    check_x_wall(window);
    check_y_wall(window);
    check_pl_ex_col(window);
}