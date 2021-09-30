/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_line_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:35:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 22:36:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	mp_line_len(char const *str)
{
	register char const	*ptr = str;

	while (*ptr && *ptr != '\n')
		++ptr;
	return (ptr - str);
}
