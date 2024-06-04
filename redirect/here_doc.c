/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:08:56 by hbettal           #+#    #+#             */
/*   Updated: 2024/06/04 12:01:59 by hbettal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	h_start(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

void	exp_set(t_minishell *mini, char **str, t_list *data)
{
	int		start;
	int		end;
	char	*exp_name;
	char	*exp_env;
	t_list	*tmp;

	start = h_start((*str));
	if (!start || expansion_error((*str)[start]))
		return ;
	if ((*str)[start] == '?')
		return (exit_number(mini, &(*str), start));
	end = ft_end((*str), start);
	exp_name = ft_substr((*str), start, end - start);
	if (!exp_name)
		ft_exit(mini, NULL, NULL, 12);
	tmp = var_finder(exp_name, &data);
	if (!tmp)
		return ((*str) = NULL, (void)0);
	exp_env = tmp->env;
	free(exp_name);
	(*str) = remove_str(str, var_value(exp_env), start, \
	end - start);
	if (!(*str))
		ft_exit(mini, NULL, NULL, 12);
}

int	ft_here_doc(t_minishell *mini, char *lim, t_list *data)
{
	char	*str;
	int		fd;

	unlink("/tmp/secret_f");
	fd = open("/tmp/ana_machi_heredoc", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (fd < 0)
		return (free(lim), 0);
	while (1)
	{
		str = readline("heredoc> ");
		if (!str || !ft_strncmp(str, lim, INT_MAX))
		{
			close(fd);
			fd = open("/tmp/ana_machi_heredoc", O_RDWR);
			return (free(lim), free(str), fd);
		}
		exp_set(mini, &str, data);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	return (0);
}
