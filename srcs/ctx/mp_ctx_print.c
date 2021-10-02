/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:40:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/02 13:11:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"

void	mp_ctx_print(void)
{
	t_ctx *const	ctx = mp_ctx_get();

	printf("ctx->stream: %p\n", ctx->stream);
	printf("ctx->zone_width: %d\n", ctx->zone_width);
	printf("ctx->zone_height: %d\n", ctx->zone_height);
	printf("ctx->background_char: %c\n", ctx->background_char);
	printf("ctx->zone: %s\n", ctx->zone);
}
