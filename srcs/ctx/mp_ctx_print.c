/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_ctx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:40:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/27 22:44:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_ctx.h"

void	mp_ctx_print(void)
{
	t_ctx *const	ctx = mp_ctx_get();

	printf("ctx->stream: %p\n", ctx->stream);
	printf("ctx->draw_zone_width: %d\n", ctx->draw_zone_width);
	printf("ctx->draw_zone_height: %d\n", ctx->draw_zone_height);
	printf("ctx->background_char: %c\n", ctx->background_char);
	printf("ctx->draw_zone:\n%s\n", ctx->draw_zone);
}
