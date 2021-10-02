/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_zone_fill_rect_empty.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:55:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/02 23:20:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "type/t_ctx.h"
#include "type/t_rect.h"
#include "enum/e_ret.h"

static bool	is_valid(t_rect rect, int zone_width, int zone_height)
{
	return (rect.width > 0
		&& rect.height > 0
		&& rect.x >= 0
		&& rect.y >= 0
		&& (int)(rect.x + rect.width) <= zone_width
		&& (int)(rect.y + rect.height) <= zone_height);
}

static bool	is_border(int width, int height, int x, int y)
{
	return (!x || x == width - 1 || !y || y == height - 1);
}

int	mp_ctx_zone_fill_rect_empty(t_rect rect)
{
	t_ctx *const	ctx = mp_ctx_get();
	int const		corner_x = (int)rect.x;
	int const		corner_y = (int)rect.y;
	int				x;
	int				y;

	if (!is_valid(rect, ctx->zone_width, ctx->zone_height))
		return (PARSE_ERR);
	x = 0;
	while (x < (int)rect.width)
	{
		y = 0;
		while (y < (int)rect.height)
		{
			if (is_border((int)rect.width, (int)rect.height, x, y))
				ctx->zone[corner_x + x + (corner_y + y) * ctx->zone_width]
					= rect.c;
			++y;
		}
		++x;
	}
	return (SUCCESS);
}
