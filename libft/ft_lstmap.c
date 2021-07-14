/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruthann <pruth@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:19:25 by pruthann          #+#    #+#             */
/*   Updated: 2020/11/15 17:23:11 by pruthann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_push_back(t_list **begin_list, void *data)
{
	t_list *new;
	t_list *temp;

	new = ft_lstnew(data);
	if (new == 0)
		return (0);
	temp = *begin_list;
	if (*begin_list)
	{
		while ((*begin_list)->next)
			*begin_list = (*begin_list)->next;
		(*begin_list)->next = new;
		*begin_list = temp;
	}
	else
		*begin_list = new;
	return (1);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*newlst;
	int	flag;

	if (!lst)
		return (0);
	temp_lst = lst;
	while (lst != 0)
	{

		flag = ft_push_back(&newlst, f(lst->content));
		if (flag == 0)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		lst = lst->next;
	}
	lst = temp_lst;
	return (newlst);
}
