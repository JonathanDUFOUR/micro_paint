/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:51:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/27 22:40:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	mp_ctx_init(char *filename)
{
	t_ctx *const	ctx = mp_ctx_get();
	int				ret;

	ctx->stream = fopen(filename, "r");
	if (!ctx->stream)
		return (FOPEN_ERR);
	ret = fscanf(ctx->stream,
			"%d %d %c\n",
			&ctx->draw_zone_width,
			&ctx->draw_zone_height,
			&ctx->background_char);
	if (ret != 3
		|| ctx->draw_zone_width < 1
		|| ctx->draw_zone_width > 300
		|| ctx->draw_zone_height < 1
		|| ctx->draw_zone_height > 300)
		return (PARSE_ERR);
	return (SUCCESS);
}
