/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:54:34 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/27 04:38:06 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	c_casted;
	int		i;

	i = ft_strlen(s);
	p = (char *)s;
	c_casted = (char )c;
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == c_casted)
			return (p + i);
		i--;
	}
	return (NULL);
}
