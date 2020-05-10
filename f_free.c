/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arz <arz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 03:12:07 by arz               #+#    #+#             */
/*   Updated: 2020/05/06 03:12:07 by arz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		free_lst(t_list *lst)
{
	t_list	*lsk;

	while (lst)
	{
		lsk = lst;
		lst = lst->next;
		free(lsk->content);
		free(lsk);
	}
	return (0);
}