/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:38:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 01:06:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "type/t_int.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	mp_ctx_zone_fill(void)
{
	t_ctx *const	ctx = mp_ctx_get();

	(void)ctx;
	return (SUCCESS);
}
