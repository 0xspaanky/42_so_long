/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:52:36 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/27 04:37:35 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*ptr_dest;
	char	*ptr_src;

	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (ptr_dest > ptr_src)
	{
		while (n--)
		{
			ptr_dest[n] = ptr_src[n];
		}
	}
	else
		ptr_dest = ft_memcpy(dest, src, n);
	return (dest);
}
