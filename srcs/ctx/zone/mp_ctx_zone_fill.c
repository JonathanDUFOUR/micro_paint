/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:38:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/04 03:21:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "zone_fill_lookup.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	mp_ctx_zone_fill(void)
{
	t_ctx *const	ctx = mp_ctx_get();
	t_rect			rect;
	int				ret;
	int				i;

	ret = fscanf(ctx->stream, "%c %f %f %f %f %c\n", &rect.type,
			&rect.x, &rect.y, &rect.width, &rect.height, &rect.c);
	while (ret != EOF)
	{
		i = 0;
		while (g_fill[i].f && rect.type != g_fill[i].type)
			++i;
		if (g_fill[i].f)
		{
			ret = g_fill[i].f(rect);
			if (ret != SUCCESS)
				return (ret);
		}
		ret = fscanf(ctx->stream, "%c %f %f %f %f %c\n", &rect.type,
				&rect.x, &rect.y, &rect.width, &rect.height, &rect.c);
	}
	return (SUCCESS);
}
