/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:06:48 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/15 16:09:35 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = 0;
	while ((*lst)->next)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
