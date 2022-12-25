/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:56:57 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/25 14:30:22 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "Get_next_line/get_next_line.h"
#include "Libft/libft.h"
#include "Printf/ft_printf.h"
#include <fcntl.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5
// # endif

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct pec
{
    int nb_pl;
    int nb_col;
    int nb_exit;
} t_pec;

typedef struct image 
{
    void *background;
    void *collect;
    void *hero;
    void *wall;
    void *closed_door;
    void *open_door;
    void *exit;
} t_image;

typedef struct player
{
    int x;
    int y;
} t_player;

typedef struct door
{
    int door_pos_x;
    int door_pos_y;
} t_door;

typedef struct window
{
    void *mlx;
    void *win;
    char **map;
    char **save;
    int h;
    int w;
    int x;
    int y;
    int count_moves;
    t_pec pec;
    t_image img;
    t_player plyr_pos;
    t_door door;
} t_window;

typedef struct s_colors
{
    char new;
    char old;
}   t_colors;

//char	*ft_substr(char const *s, unsigned int start, size_t len);
//size_t	ft_strlen(const char *s);
void    get_map(char *arg, int fd, t_window *window);
char	*get_next_line(int fd);
int	ft_printf(const char *str, ...);
void    put_img_to_window(t_window *game);
void    xpm_to_img(t_window *index);
char    **ft_split(char *s, char c);
void    errors(int i);
int	find(char *str, char *to_find);
int get_x(char **str);
int get_y(char **str);
void    check_map(t_window *window);
char	*get_next_line(int fd);
//void    get_x_and_y(char **str, int x, int y);
char	*join_both(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	*alloc_me(size_t count, size_t size);
void check_map_name(char *name);
void check_rectangular(t_window *window);
void check_y_wall(t_window *window);
void check_y_wall(t_window *window);
void count_pec(t_window *window);
void check_pl_ex_col(t_window *window);
void check_map(t_window *window);
void check_map_ff(t_window *window);
void player_pos(t_window *window);
void exit_move(t_window window);
int key_hook(int keycode, t_window *win);
void render_door(t_window *win);
void up_helper_0(t_window *win);
void up_helper_1(t_window *win);
void down_helper_0(t_window *win);
void down_helper_1(t_window *win);
void left_helper_0(t_window *win);
void left_helper_1(t_window *win);
void right_helper_0(t_window *win);
void right_helper_1(t_window *win);
void congrats(t_window *win);
// void flood_fill(t_window *window, int x, int y, char new, char old);
void put_img_to_window(t_window *game);
void xpm_to_img(t_window *index);

#endif