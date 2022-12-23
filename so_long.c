/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:07:12 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/23 03:12:14 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_window index;
    int fd;
    fd = 0;
    
    if (argc == 2)
    {
        get_map(argv[1], fd, &index);
        index.w = 100 * get_x(index.map);
        index.h = 100 * get_y(index.map);
        index.mlx = mlx_init();
        index.win = mlx_new_window(index.mlx, index.w, index.h, "so_long");
        player_pos(&index);
        check_map_ff(&index);
        xpm_to_img(&index);
        put_img_to_window(&index);
        mlx_loop(index.mlx);
    }
    else printf("just 2 args");
    return (0);
}