/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/03 22:18:12 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct pec
{
	int			nb_pl;
	int			nb_col;
	int			nb_exit;
}				t_pec;

typedef struct image
{
	void		*background;
	void		*collect;
	void		*hero;
	void		*enemy;
	void		*wall;
	void		*closed_door;
	void		*open_door;
	void		*exit;
}				t_image;

typedef struct player
{
	int			x;
	int			y;
}				t_player;

typedef struct door
{
	int			door_pos_x;
	int			door_pos_y;
}				t_door;

typedef struct collect
{
	int			col_pos_x;
	int			col_pos_y;
}				t_collect;

typedef struct window
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**save;
	int			h;
	int			w;
	int			x;
	int			y;
	int			count_moves;
	char		*move_nbr;
	t_collect	collect;
	t_pec		pec;
	t_image		img;
	t_player	plyr_pos;
	t_door		door;
}				t_window;

typedef struct s_colors
{
	char		new;
	char		old;
}				t_colors;

void			get_map(char *arg, int fd, t_window *window);
char			*get_next_line(int fd);
int				ft_printf(const char *str, ...);
void			put_img_to_window(t_window *game);
void			xpm_to_img(t_window *index);
char			**ft_split(char *s, char c);
void			errors(int i);
int				get_x(char **str);
int				get_y(char **str);
void			check_map(t_window *window);
char			*get_next_line(int fd);
char			*join_strings(char *s1, char *s2);
char			*join_both(char *s1, char *s2);
void			*alloc_me(size_t count, size_t size);
void			check_rectangular(t_window *window);
void			check_map(t_window *window);
void			check_map_ff(t_window *window);
void			player_pos(t_window *window);
void			exit_move(t_window window);
int				key_hook(int keycode, t_window *win);
void			render_door(t_window *win);
void			up_helper_0(t_window *win);
void			up_helper_1(t_window *win);
void			down_helper_0(t_window *win);
void			down_helper_1(t_window *win);
void			left_helper_0(t_window *win);
void			left_helper_1(t_window *win);
void			right_helper_0(t_window *win);
void			right_helper_1(t_window *win);
void			put_wall(t_window *window);
void			put_collect(t_window *window);
void			put_hero(t_window *window);
void			put_exit(t_window *window);
void			put_enemy(t_window *window);
void			congrats(t_window *win);

#endif