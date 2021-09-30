/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_file_content_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:12:56 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/30 21:45:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "micro_paint.h"

char	*mp_file_content_get(FILE *stream)
{
	char	*output;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	size_t	frd;

	output = NULL;
	frd = fread(buff, sizeof(char), BUFF_SIZE, stream);
	while (frd)
	{
		buff[frd] = 0;
		tmp = output;
		output = mp_strjoin(output, buff);
		mp_memdel(&tmp);
		if (!output)
		{
			fclose(stream);
			return (NULL);
		}
		frd = fread(buff, sizeof(char), BUFF_SIZE, stream);
	}
	return (output);
}
