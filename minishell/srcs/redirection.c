/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomoon <nomoon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:24:30 by paulohl           #+#    #+#             */
/*   Updated: 2021/02/16 19:51:35 by paulohl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <fcntl.h>

int	get_fd(char *redirection, char type)
{
	int		flags;
	int		fd;

	if (type == 'a')
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else if (type == '>')
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (type == '<')
		flags = O_RDONLY;
	else
		flags = 0;
	fd = open(redirection, flags, 0000644);
	if (fd == -1)
	{
		print_redirection_error(redirection);
		g_last_return = 1;
		return (0);
	}
	free(redirection);
	return (fd);
}

char	set_redirect_type(t_command *command, int *i)
{
	char	type;

	type = command->cmd[*i];
	if (command->cmd[*i + 1] == '>')
	{
		(*i)++;
		type = 'a';
	}
	if (type == '<')
		command->type_in = '<';
	else
		command->type_out = type;
	(*i)++;
	while (command->cmd[*i] == ' ')
		(*i)++;
	return (type);
}

bool	get_redirect(t_command *command, int *i)
{
	int		end_of_redirection;
	int		fd;
	char	type;
	char	*redirection;

	type = set_redirect_type(command, i);
	end_of_redirection = skip_redirect(command->cmd, *i);
	redirection = get_word(command, *i, end_of_redirection);
	if (!redirection)
		return (false);
	*i = end_of_redirection;
	fd = get_fd(redirection, type);
	if (!fd)
		return (false);
	set_redirect_fd(command, type, fd);
	return (true);
}

bool	handle_redirection(t_command *command, int *i, int *start)
{
	if (!get_redirect(command, i))
		return (false);
	while (command->cmd[*i] == ' ')
		(*i)++;
	(*i)--;
	*start = *i + 1;
	return (true);
}
