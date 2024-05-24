/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:41:37 by hbettal           #+#    #+#             */
/*   Updated: 2024/05/23 20:39:40 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**first_red(char **token) 
{
	int		fd;
	int		i;
	char	*commands;
	char	**cmds;
	
	i = 2;
	commands = NULL;
	while (token[i])
		commands = ft_strjoin(commands, token[i++]);
	cmds = ft_split(commands, " ");
	fd = open(token[1], O_RDONLY);
	if (dup2(fd, 0) == -1)
		exit(1);
	free_handler(token);
	if (ft_strchr(commands, '>'))
		return(last_red(commands));
	free(commands);
	return(cmds);
}

char	**last_red(char *line)
{
	int		fd;
	int		i;
	char	**token;
	char	**commands;
	
	i = 0;
	token = ft_split(line, ">");
	commands = ft_split(token[0], " ");
	while (commands[i])
		i++;
	fd = open(*ft_split(token[1], " "), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dup2(fd, 1) == -1)
		exit(1);
	free_handler(token);
	return (commands);
}