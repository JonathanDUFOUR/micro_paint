/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_skip_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:27:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 23:29:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

char	*mp_skip_float(char const *str)
{
	while (mp_isdigit(*str))
		++str;
	if (*str == '.')
		while (mp_isdigit(*++str))
			continue ;
	return ((char *)str);
}
