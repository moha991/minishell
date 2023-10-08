/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagniny <santi.mag777@student.42madrid    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:46:06 by smagniny          #+#    #+#             */
/*   Updated: 2023/10/08 19:45:15 by smagniny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/header.h"

int	heredoc(t_var *var)
{
	char			*str;
	int				cmd_index;
	int				hist_index;

	hist_index = 0;
	cmd_index = -1;
	var->heredoc = open("./tmp", O_RDWR | O_CREAT, 00600);
	if (var->heredoc <= 0)
	{
		ft_printf("%s: %s: %s", __FILE__, __func__, strerror(errno));
		return (1);
	}
	dup2(var->heredoc, 0);
	while (++cmd_index >= 0)
	{
		ft_printf("%d> ", cmd_index);
		str = readline(NULL);
		var->history[cmd_index] = ft_strdup(str);
		if (ft_strncmp(str, "clear", 5) == 0)
		{
			free(str);
			rl_clear_history();
			while (var->history[hist_index])
				var->history[hist_index++] = 0;
			cmd_index = 0;
			hist_index = 0;
			continue ;
		}
		if (ft_strncmp(str, "exit", 4) == 0)
		{
			free(str);
			break ;
		}
		add_history(str);
		ft_printf("prev_cmd; %s\n", var->history[cmd_index]);
	}
	str = get_next_line(var->heredoc);
	printf("heredoc; %s", str);
	close(var->heredoc);
	return (0);
}

int	main(void)
{
	t_var	var;
	heredoc(&var);
}
