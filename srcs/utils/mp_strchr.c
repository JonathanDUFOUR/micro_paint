/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:54:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 22:34:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*mp_strchr(char const *str, char const c)
{
	register char const	*ptr = str;

	while (*ptr && *ptr != c)
		++ptr;
	if (c && !*ptr)
		return (NULL);
	return ((char *)ptr);
}
