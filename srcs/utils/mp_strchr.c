/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:54:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 02:12:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*mp_strchr(char const *str, char const c)
{
	while (*str && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
