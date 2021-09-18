/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twagner <twagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:22:12 by twagner           #+#    #+#             */
/*   Updated: 2021/09/18 17:00:54 by twagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_mobsclear(t_mob **lst)
{
	t_mob	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	lst = NULL;
}

t_mob	*ft_mobslast(t_mob *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_mobadd_back(t_mob **lst, t_mob *new)
{
	if (*lst)
		ft_mobslast(*lst)->next = new;
	else
		*lst = new;
}

t_mob	*ft_mobnew(int x, int y, char type)
{
	t_mob	*new;

	new = (t_mob *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->type = type;
	new->move = 0;
	new->next_img = 2;
	new->from_exit = 0;
	new->to_exit = -1;
	new->from_coll = 0;
	new->to_coll = -1;
	new->nb_move = 0;
	new->x = x;
	new->y = y;
	new->next_x = -1;
	new->next_y = -1;
	new->next = NULL;
	return (new);
}

int	ft_create_mobs(t_map *map, t_param *prm)
{
	int		col;
	int		row;
	t_mob	*new;

	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		while (++col < map->cols)
		{
			if (ft_strchr(MOBS, map->map[row][col]))
			{
				new = ft_mobnew(col, row, map->map[row][col]);
				if (!new)
					return (ERROR);
				ft_mobadd_back(&prm->mobs, new);
			}
		}
	}
	return (0);
}
