/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_and_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:33:10 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/20 21:43:54 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_x(char **str)
{
    int i;
    int counter;

    counter = 0;
    i = 0;
    //check_new_line(str);
    while(str[0][i])
    {
        if(str[0][i] != '\0')
            counter++;
        i++;
    }
    return counter;
}

int get_y(char **str)
{
    int i;
    int counter;

    counter = 0;
    i = 0;
    //check_new_line(str);
    while(str[i])
    {
        if(str[i][0] == '1')
            counter++;
        i++;
    }
    return counter;
}

void get_x_and_y(char **str, int x, int y)
{
    x = get_x(str);
    y = get_y(str);
}