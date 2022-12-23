/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:46:00 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/23 02:58:13 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void get_map(char *arg, int fd, t_window *window)
{
    char *map_line;
    char *str;

    check_map_name(arg);
    str = alloc_me(1,1);
    fd = open(arg, O_RDONLY);
    // if (fd < 0)
    //     return(0);
    map_line = get_next_line(fd);
    while(map_line)
    {
        str = join_both(str, map_line);
        free(map_line);
        map_line = get_next_line(fd);
    }
    check_new_line(str);
    window->map = ft_split(str, '\n');
    window->save = ft_split(str, '\n');
    free(str);
    free(map_line);
}