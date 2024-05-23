/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_k.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:35:58 by hbettal           #+#    #+#             */
/*   Updated: 2024/05/23 22:29:38 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fds_closer(int end[])
{
	close(end[0]);
	close(end[1]);
}

void	free_handler(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
		free(str[i]);
	free (str);
}

// int	count_words(char *str, char c)
// {
// 	int	i;
// 	int	trigger;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(const char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;

// 	if (!s)
// 		return (NULL);
// 	split = malloc((count_words(s, c) + 1) * sizeof(char *));
// 	if (!split)
// 		(write(2, "Error\n", 6), exit(1));
// 	i = -1;
// 	j = 0;
// 	index = -1;
// 	while (++i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			split[j++] = word_dup(s, index, i);
// 			index = -1;
// 		}
// 	}
// 	split[j] = 0;
// 	return (split);
// }
