/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:07:12 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/03 17:19:16 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_window	index;

	index.count_moves = 0;
	if (argc == 2)
	{
		get_map(argv[1], 0, &index);
		index.w = 100 * get_x(index.map);
		index.h = 100 * get_y(index.map);
		index.mlx = mlx_init();
		index.win = mlx_new_window(index.mlx, index.w, index.h, "so_long");
		xpm_to_img(&index);
		put_img_to_window(&index);
		player_pos(&index);
		check_map(&index);
		check_map_ff(&index);
		exit_move(index);
		key_hook(0, &index);
		mlx_key_hook(index.win, key_hook, &index);
		mlx_loop(index.mlx);
	}
	else
		printf("Try with just 2 args");
	exit(0);
}
