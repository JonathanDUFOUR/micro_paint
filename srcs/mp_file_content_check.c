/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_file_content_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:34:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/01 00:28:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "micro_paint.h"
#include "line_check_actions_array.h"
#include "enum/e_ret.h"

static int	first_line_check(char *ptr)
{
	int	i;

	i = 0;
	while (g_action_first_line[i].check_fct && g_action_first_line[i].skip_fct)
	{
		if (!g_action_first_line[i].check_fct(*ptr))
			return (LINE_FORMAT_ERR);
		ptr = g_action_first_line[i].skip_fct(ptr);
		++i;
	}
	if (!*ptr || (*(ptr + 1) && *(ptr + 1) != '\n'))
		return (LINE_FORMAT_ERR);
	return (SUCCESS);
}

static int	other_line_check(char const *ptr)
{
	int	i;

	if (!mp_strchr("Rr", *ptr))
		return (LINE_FORMAT_ERR);
	++ptr;
	i = 0;
	while (g_action_other_line[i].check_fct && g_action_other_line[i].skip_fct)
	{
		if (!g_action_other_line[i].check_fct(*ptr))
			return (LINE_FORMAT_ERR);
		ptr = g_action_other_line[i].skip_fct(ptr);
		++i;
	}
	if (!*ptr || (*(ptr + 1) && *(ptr + 1) != '\n'))
		return (LINE_FORMAT_ERR);
	return (SUCCESS);
}

int	mp_file_content_check(char const *filename)
{
	FILE	*stream;
	char	*content;
	char	*ptr;
	int		ret;

	stream = fopen(filename, "r");
	if (!stream)
		return (FOPEN_ERR);
	content = mp_file_content_get(stream);
	fclose(stream);
	if (!content)
		return (MP_FILE_CONTENT_GET_ERR);
	ptr = content;
	ret = SUCCESS;
	while (*ptr && ret == SUCCESS)
	{
		if (ptr == content)
			ret = first_line_check(ptr);
		else
			ret = other_line_check(ptr);
		ptr += mp_line_len(ptr);
		ptr += !!*ptr;
	}
	mp_memdel(&content);
	return (ret);
}
