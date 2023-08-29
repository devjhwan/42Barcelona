/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:32:36 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pack	*pack;
	int		exit_code;

	if (argc < 5)
	{
		ft_printf("./pipex file1 cmd1 cmd2 ... cmdn file2\n");
		return (1);
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0 && \
			ft_strlen(argv[1]) == 8 && \
			argc < 6)
	{
		ft_printf("./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2\n");
		return (1);
	}
	else
	{
		pack = parse_input(argc, argv, envp);
		pipe_execution(pack, envp);
		exit_code = pack->exit_code;
		free_pack(pack);
	}
	return (exit_code);
}
