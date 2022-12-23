/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:35:22 by smounafi          #+#    #+#             */
/*   Updated: 2022/12/13 23:43:43 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (0);
	if (start >= my_len(s))
		return (alloc_me(1, 1));
	if (len > my_len(s))
		len = my_len(s);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
