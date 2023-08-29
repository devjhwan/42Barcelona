/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:52:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/29 16:49:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_path_set(t_pack *pack, char **envp)
{
	int		i;

	if (envp != NULL && envp[0] != NULL)
	{
		i = 0;
		while (ft_strncmp(envp[i], "PATH", 4) != 0)
			i++;
		pack->path_set = ft_split(envp[i], ":");
	}
	else
		pack->path_set = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:\
							/sbin:/usr/local/go/bin:/usr/local/munki:\
							/opt/anaconda3/condabin", ":");
	if (pack->path_set == NULL)
		errexit(pack, 137);
}

static char	**parse_special_command(char *arg)
{
	char	**ret;
	char	*tmp;
	size_t	i;

	ret = (char **)malloc(sizeof(char *) * 3);
	if (ret == NULL)
		return (NULL);
	i = (size_t)(ft_strchr(arg, ' ') - arg);
	ret[0] = ft_substr(arg, 0, i);
	tmp = ft_strtrim(&arg[i + 1], " \"");
	ret[1] = ft_strtrim(&arg[i + 1], " \'");
	if (ret[0] == NULL || ret[1] == NULL || tmp == NULL)
		return (free(ret), free(ret[0]), free(tmp), free(ret[1]), NULL);
	if (ft_strlen(tmp) < ft_strlen(ret[1]))
	{
		free(ret[1]);
		ret[1] = tmp;
	}
	else
		free(tmp);
	ret[2] = NULL;
	return (ret);
}

static void	parse_command(t_pack *pack, int argc, char **argv)
{
	char	**cmdarg;
	t_list	*newcmd;
	int		i;

	i = 2;
	if (pack->here_doc == 1)
		i = 3;
	while (i < argc - 1)
	{
		if (ft_strchr(argv[i], '\'') == NULL && \
			ft_strchr(argv[i], '\"') == NULL)
			cmdarg = ft_split(argv[i], " ");
		else
			cmdarg = parse_special_command(argv[i]);
		newcmd = ft_lstnew(cmdarg);
		if (newcmd == NULL || cmdarg == NULL)
		{
			free(newcmd);
			clear_content(cmdarg);
			errexit(pack, 137);
		}
		ft_lstadd_back(&pack->cmd, newcmd);
		i++;
	}
}

t_pack	*parse_input2(t_pack *pack, int argc, char **argv, char **envp)
{
	parse_command(pack, argc, argv);
	parse_path_set(pack, envp);
	return (pack);
}
