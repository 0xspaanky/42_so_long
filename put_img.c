/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:13:23 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/23 03:10:27 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void put_img_to_window(t_window *game)
{ 
    game->x = 0;
    game->y = 0;
    game->h = 0;
    game->w = 0;
    while(game->y < get_y(game->map))
    {
        game->x = 0;
        game->h = 0;
        while (game->map[game->y][game->x])
        {
            if(game->map[game->y][game->x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img.background, game->h*100, game->w*100);
            if(game->map[game->y][game->x] == '1')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->img.background, game->h*100, game->w*100);
                mlx_put_image_to_window(game->mlx, game->win, game->img.wall, game->h*100, game->w*100);
            }
            else if(game->map[game->y][game->x] == 'C')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->img.background, game->h*100, game->w*100);
                mlx_put_image_to_window(game->mlx, game->win, game->img.collect, game->h*100, game->w*100);
            }
            else if(game->map[game->y][game->x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->win, game->img.background, game->h*100, game->w*100);
                mlx_put_image_to_window(game->mlx, game->win, game->img.hero, game->h*100, game->w*100);
            }
            else if(game->map[game->y][game->x] == 'E')
                {
                    mlx_put_image_to_window(game->mlx, game->win, game->img.background, game->h*100, game->w*100);
                    mlx_put_image_to_window(game->mlx, game->win, game->img.door, game->h*100, game->w*100);
                }
            game->x++;
            game->h++;
        }
        game->y++;
        game->w++;
    }
}

void xpm_to_img(t_window *index)
{
    int x;
    int y;
    index->img.wall = mlx_xpm_file_to_image(index->mlx, "./img/wall.xpm", &x, &y);
    index->img.hero = mlx_xpm_file_to_image(index->mlx, "./img/hero.xpm", &x, &y);
    index->img.background = mlx_xpm_file_to_image(index->mlx, "./img/background.xpm", &x, &y);
    index->img.collect = mlx_xpm_file_to_image(index->mlx, "./img/collect.xpm", &x, &y);
    index->img.door = mlx_xpm_file_to_image(index->mlx, "./img/door_closed.xpm", &x, &y);
}