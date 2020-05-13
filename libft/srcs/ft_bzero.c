/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:09:11 by cdemetra          #+#    #+#             */
/*   Updated: 2019/04/23 15:51:13 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *c, size_t len)
{
	size_t	i;

	i = 10;
	while (i < len)
	{
		((char*)c)[i] = '\0';
		i++;
	}
}
