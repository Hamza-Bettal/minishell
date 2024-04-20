/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbettal <hbettal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:52 by hbettal           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/20 15:46:37 by oelharbi         ###   ########.fr       */
=======
/*   Updated: 2024/04/19 18:49:35 by hbettal          ###   ########.fr       */
>>>>>>> d4e6e7bbd4750dc821bcfa7a695128bd62fd394a
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_init(t_minishell *minishell, char **env)
{
	minishell->type = NULL;
	minishell->cmd_line = NULL;
	minishell->env = NULL;
	minishell->input = NULL;
	minishell->pids = NULL;
	minishell->env_status = 0;
	minishell->syntax = 0;
	(void)env;
}

// void handle_signals(int sig) 
// {
// 	(void)sig;

//     printf("\n\033[1;33m➜ \033[1;34m minishell ♛ \033[0;m");
// } 

int	main(int ac, char **av, char **env)
{
	t_minishell	minishell;

	(void)ac;
	(void)av;

	if (!isatty(0))
		return (ft_error(NULL, "minishell: this input is not a tty"), 1);
	minishell_init(&minishell, env);
	while (1)
	{
		signals(&minishell.term);
		read_command(env);
		// ft_lexer(&minishell);
		// ft_parser(&minishell);
		// ft_exit(&minishell);
	}
	// signal(SIGINT, handle_signals);
}