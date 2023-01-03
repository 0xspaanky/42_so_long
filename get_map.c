/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:46:00 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/03 17:12:01 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_line(char *str)
{
	int	y;

	y = 0;
	if (!*str)
		errors(8);
	if (str[0] == '\n' || str[my_len(str) - 1] == '\n')
		errors(6);
	while (str[y])
	{
		if (str[y] == '\n' && str[y + 1] == '\n')
			errors(6);
		y++;
	}
}

void	check_map_name(char *name)
{
	int	i;

	i = 0;
	i = my_len(name);
	if (name[i - 1] != 'r' || name[i - 2] != 'e' || name[i - 3] != 'b'
		|| name[i - 4] != '.')
		errors(3);
}

void	check_rectangular(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_y(window->map))
	{
		x = 0;
		while (window->map[y][x])
			x++;
		if (x != get_x(window->map))
			errors(4);
		y++;
	}
}

void	get_map(char *arg, int fd, t_window *window)
{
	char	*map_line;
	char	*str;

	check_map_name(arg);
	str = alloc_me(1, 1);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		errors(9);
	map_line = get_next_line(fd);
	while (map_line)
	{
		str = join_strings(str, map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	check_new_line(str);
	window->map = ft_split(str, '\n');
	window->save = ft_split(str, '\n');
	free(str);
}
