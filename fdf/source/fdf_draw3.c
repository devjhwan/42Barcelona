/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:17:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/06 17:17:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_map.h"
#include "fdf_color.h"

void	get_min_max(t_map *map, double *min, double *max)
{
	int	n;

	n = 2;
	*min = map->m_copy[2];
	*max = map->m_copy[2];
	while (n < map->len)
	{
		if (map->m_copy[n] < *min)
			*min = map->m_copy[n];
		if (map->m_copy[n] > *max)
			*max = map->m_copy[n];
		n += 3;
	}
}

unsigned int	*select_color(t_map *map, int n1, int n2)
{
	double			min;
	double			max;
	unsigned int	color[2];

	if (map->color_set == BASIC_COLOR)
		return (gradient_between_point(map->color, n1, n2, color));
	get_min_max(map, &min, &max);
	if (map->color_set == BLACK_RED)
		return (gradient_by_zaxis((double []){min, max}, \
				(int []){map->m_copy[n1 + 2], map->m_copy[n2 + 2]}, \
				(unsigned int []){BLACK, RED}, color));
	else if (map->color_set == DEEPBLUE_RED)
		return (gradient_by_zaxis((double []){min, max}, \
				(int []){map->m_copy[n1 + 2], map->m_copy[n2 + 2]}, \
				(unsigned int []){DEEPBLUE, RED}, color));
	else if (map->color_set == BLACK_DEEPBLUE)
		return (gradient_by_zaxis((double []){min, max}, \
				(int []){map->m_copy[n1 + 2], map->m_copy[n2 + 2]}, \
				(unsigned int []){BLACK, DEEPBLUE}, color));
	else
		return (gradient_by_world((double []){min, max}, \
				(int []){map->m_copy[n1 + 2], map->m_copy[n2 + 2]}, \
				(unsigned int []){DEEPBLUE, RED, GREEN, WHITE}, color));
}
