/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_skip_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:22:57 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 23:24:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

char	*mp_skip_integer(char const *str)
{
	while (mp_isdigit(*str))
		++str;
	return ((char *)str);
}
