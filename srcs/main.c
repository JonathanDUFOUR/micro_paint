/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:34:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/27 22:40:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	main(int ac, char **av)
{
	int	ret;

	if (ac != 2)
		return (!!mp_err_msg(AC_ERR));
	ret = mp_ctx_init(av[1]);
	if (ret == SUCCESS)
		mp_ctx_print();
	mp_ctx_clear();
	if (ret != SUCCESS)
		return (!!mp_err_msg(ret));
	return (SUCCESS);
}
