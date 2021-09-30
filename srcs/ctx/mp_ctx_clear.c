/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:07:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 00:58:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "micro_paint.h"
#include "type/t_ctx.h"

void	mp_ctx_clear(void)
{
	t_ctx *const	ctx = mp_ctx_get();

	if (ctx->stream)
		fclose(ctx->stream);
	free(ctx->zone);
	memset(ctx, 0, sizeof(t_ctx));
}
