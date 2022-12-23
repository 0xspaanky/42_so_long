/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:39:43 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/29 15:25:48 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && len == 0)
		return (0);
	if (!*needle)
		return ((char *)haystack);
	if (!len && !*needle)
		return ((char *)haystack);
	if (haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && len >= ft_strlen(needle))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}
