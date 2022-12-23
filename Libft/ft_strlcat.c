/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:34:17 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/29 15:25:25 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d;
	size_t	s;

	i = 0;
	if (!dst && dstsize == 0)
		return (0);
	d = ft_strlen(dst);
	s = ft_strlen(src);
	j = d;
	if (!dst && !src)
		return (s);
	if (dstsize <= d)
		return (s + dstsize);
	while (src[i] && j < dstsize - 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (d + s);
}
