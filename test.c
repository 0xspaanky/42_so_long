/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:13:06 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/23 02:12:52 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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
                window->plyr_pos.x = x + 1;
                window->plyr_pos.y = y + 1;
            }
            x++;
        }
        y++;
    }
}

// int main(int argc, char **argv)
// {
//     t_window index;
//     int fd;
//     fd = 0;
    
//     int x;
//     int y = 0;
//     if (argc == 2)
//     {
//         index.map = get_map(argv[1], fd);
//         index.w = 100 * get_x(index.map);
//         index.h = 100 * get_y(index.map);
//         index.mlx = mlx_init();
//         index.win = mlx_new_window(index.mlx, index.w, index.h, "so_long");
//         player_pos(&index);
//         check_map_ff(&index);
//         while(index.map[y])
//         {
//             x = 0;
//             while(index.map[y][x])
//             {
//                 printf("%c", index.map[y][x]);
//                 x++;
//             }
//             printf("\n");
//             y++;
//         }
//     }
//     else printf("just 2 args");
//     return (0);
// }



// show map content 

// while(index.map[y])
//         {
//             x = 0;
//             while(index.map[y][x])
//             {
//                 printf("%c", index.map[y][x]);
//                 x++;
//             }
//             printf("\n");
//             y++;
//         }





//gcc -fsanitize=address test.c get_map.c get_x_and_y.c get_next_line_utils.c ft_split.c get_next_line.c  check_map.c errors.c ft_substr.c