/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:52:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 16:28:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_heredoc_input(t_pack *pack)
{
	char	*tmp;
	size_t	endstream_len;

	endstream_len = ft_strlen(pack->endstream);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		tmp = get_next_line(0);
		if (ft_strncmp(tmp, pack->endstream, endstream_len) == 0 && \
			ft_strlen(tmp) == endstream_len + 1)
		{
			free(tmp);
			break ;
		}
		write(pack->fd1, tmp, ft_strlen(tmp));
		free(tmp);
	}
	close(pack->fd1);
	pack->fd1 = open(".heredoc_tmp", O_RDONLY, 0644);
	if (pack->fd1 < -1)
		errexit(pack, 127);
}

static void	parse_heredoc(t_pack *pack, int argc, char **argv)
{
	pack->here_doc = 1;
	pack->endstream = argv[2];
	pack->file1 = "here_doc";
	pack->file2 = argv[argc - 1];
	pack->fd1 = open(".heredoc_tmp", O_WRONLY | O_CREAT, 0644);
	if (pack->fd1 < -1)
		errexit(pack, 127);
	pack->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	get_heredoc_input(pack);
}

static void	parse_file_input(t_pack *pack, int argc, char **argv)
{
	pack->here_doc = 0;
	pack->endstream = NULL;
	pack->file1 = argv[1];
	pack->file2 = argv[argc - 1];
	pack->fd1 = open(argv[1], O_RDONLY);
	unlink(argv[argc - 1]);
	pack->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT, 0644);
}

static t_pack	*init_pack(void)
{
	t_pack	*pack;

	pack = (t_pack *)ft_calloc(1, sizeof(t_pack));
	if (pack == NULL)
		exit(1);
	pack->fd1 = -1;
	pack->fd2 = -1;
	return (pack);
}

t_pack	*parse_input(int argc, char **argv, char **enpv)
{
	t_pack	*pack;

	pack = init_pack();
	if (ft_strcmp(argv[1], "here_doc") == 0)
		parse_heredoc(pack, argc, argv);
	else
		parse_file_input(pack, argc, argv);
	return (parse_input2(pack, argc, argv, enpv));
}
