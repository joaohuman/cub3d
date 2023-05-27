/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:56:02 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/16 17:56:29 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*aux_free;

	aux = *lst;
	aux_free = aux;
	while (aux)
	{
		aux = aux->next;
		ft_lstdelone(aux_free, del);
		aux_free = aux;
	}
	*lst = NULL;
}
