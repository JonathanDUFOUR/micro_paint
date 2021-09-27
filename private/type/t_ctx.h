/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:54:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/27 22:44:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# include <stdio.h>

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	FILE	*stream;
	int		draw_zone_width;
	int		draw_zone_height;
	char	background_char;
	char	*draw_zone;
};

int		mp_ctx_init(char *filename);

void	mp_ctx_clear(void);
void	mp_ctx_print(void);	

t_ctx	*mp_ctx_get(void);

#endif
