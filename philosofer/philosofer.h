/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:48:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/09/24 20:48:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFER_H
# define PHILOSOFER_H

# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647

int	phi_isdigit(const char c);
int	phi_atoi(const char *str, int *num);

void	negative_number(void);
void	bad_input_format(void);
void	number_out_of_max_range(void);

#endif
