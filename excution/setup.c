/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:13:01 by hbettal           #+#    #+#             */
/*   Updated: 2024/06/06 12:53:32 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_no_cmd(char *cmd, char *msg)
{
	write(2, "minishell: ", 11);
	write(2, cmd, ft_strlen(cmd));
	write(2, msg, ft_strlen(msg));
}

char	*path_check(char *command, t_list *data, int end[])
{
	int		i;
	char	*cmnd;
	char	*path;
	char	**paths;

	if (!command[0])
		(write(2, "minishell:  : command not found\n", 32), exit(127));
	if (!access(command, F_OK) && access(command, X_OK) != -1)
		(print_no_cmd(command, ": in a directory\n"), exit(126));
	i = -1;
	paths = ft_split(where_path(data), ":");
	if (!paths)
		(print_no_cmd(command, ": command not found\n"), exit(127));
	cmnd = ft_strjoin("/", command);
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], cmnd);
		if (access(path, F_OK) != -1)
			return (path);
		free(path);
	}
	(fds_closer(end));
	(print_no_cmd(command, ": command not found\n"), exit(127));
}

void	more_commands(t_pex *pex, t_list **data, t_minishell *mini)
{
	int		status;
	pid_t	id;

	id = 0;
	if (mini->list_size > 1)
	{
		pex->input = pex->end[0];
		while (pex->i + 2 < mini->list_size)
		{
			if (pipe(pex->end) == -1)
				(write(2, "pipe failed\n", 12), exit(1));
			middle_commands(pex, data, mini);
			close(pex->end[1]);
			close(pex->input);
			pex->input = pex->end[0];
			pex->i++;
		}
		id = last_cmd(pex, data, mini);
	}
	fds_closer(pex->end);
	waitpid(id, &status, 0);
	while (wait(NULL) != -1)
		;
	mini->exit_status = (status >> 8) & 0xFF;
}

void	single_command(t_minishell *mini, t_list **data)
{
	t_pex	pex;
	int		sv_stdout;
	int		sv_stdin;

	(1) && (sv_stdout = dup(1), sv_stdin = dup(0), pex.i = 0);
	mini->exit_status = 0;
	if (mini->list_size == 1)
	{
		check_fd(mini, &pex, 0);
		if (build_check(mini, data, &pex))
		{
			(dup2(sv_stdout, 1), close(sv_stdout));
			(dup2(sv_stdin, 0), close(sv_stdin));
			return ;
		}
	}
	(dup2(sv_stdout, 1), close(sv_stdout), dup2(sv_stdin, 0), close(sv_stdin));
	pex.lines = mini->list_size;
	if (pipe(pex.end) == -1)
		(write(2, "Error\n", 6), exit(1));
	(first_cmd(data, &pex, mini), close(pex.end[1]));
	more_commands(&pex, data, mini);
	close_fds(mini);
	close(pex.end[0]);
}
