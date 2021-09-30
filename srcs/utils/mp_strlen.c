/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:58:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 20:59:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	mp_strlen(char const *str)
{
	register char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}
