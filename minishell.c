/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:09:09 by cnkosi            #+#    #+#             */
/*   Updated: 2017/09/29 03:12:32 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*new_line(char *tmp, t_vars *v)
{
	v->i = 0;
	v->j = 0;
	if (ft_strncmp(tmp, "echo", 4) == 0)
		return (tmp);
	v->s = ft_strnew(ft_strlen(tmp));
	while (tmp[v->i])
	{
		if (ft_isspace(tmp[v->i]))
		{
			while (ft_isspace(tmp[v->i]))
				v->i++;
			v->s[v->j++] = ' ';
		}
		v->s[v->j++] = tmp[v->i];
		v->i++;
	}
	free(tmp);
	v->s[v->j] = '\0';
	if (v->s)
		return (v->s);
	return (NULL);
}

char	*read_line(void)
{
	char	buff;
	char	*tmp;
	char	*line;
	char	*tmp1;

	line = ft_strnew(1);
	tmp1 = ft_strnew(1);
	while (read(STDIN_FILENO, &buff, 1))
	{
		if (buff == '\n')
			break ;
		ft_strncpy(tmp1, &buff, 1);
		tmp = ft_strjoin(line, tmp1);
		free(line);
		line = tmp;
	}
	free(tmp1);
	if (line)
		return (line);
	return (NULL);
}

int		sh_exec_path(char *line, t_vars *v)
{
	if (ft_strncmp(line, "/bin/", 5) == 0)
		ft_execve(&line[4], "/bin/", v);
	else if (ft_strncmp(line, "/usr/local/sbin/", 16) == 0)
		ft_execve(&line[15], "/usr/local/sbin/", v);
	else if (ft_strncmp(line, "/usr/local/bin/", 15) == 0)
		ft_execve(&line[14], "/usr/local/bin/", v);
	else if (ft_strncmp(line, "/usr/sbin/", 10) == 0)
		ft_execve(&line[9], "/usr/sbin/", v);
	else if (ft_strncmp(line, "/usr/bin/", 9) == 0)
		ft_execve(&line[8], "/usr/bin/", v);
	else if (ft_strncmp(line, "/sbin/", 6) == 0)
		ft_execve(&line[5], "/sbin/", v);
	else if (ft_strncmp(line, "/usr/games/", 11) == 0)
		ft_execve(&line[10], "/usr/games/", v);
	else if (ft_strncmp(line, "/usr/local/games/", 17) == 0)
		ft_execve(&line[16], "/usr/local/games/", v);
	else
		ft_execve1(line, v);
	return (1);
}

void	sh_execute(char *line, t_vars *v)
{
	v->i = 0;
	if (ft_isspace(line[v->i]))
		while (ft_isspace(line[v->i]))
			v->i++;
	v->len = ft_strlen(line);
	if (ft_isspace(line[v->len - 1]))
		while (ft_isspace(line[v->len - 1]))
			v->len++;
	if (ft_strncmp(line, "echo", 4) == 0)
		ft_echo(&line[5], v);
	else if (ft_strcmp(line, "cd ~") == 0)
		chdir(chdir_home());
	else if (ft_strncmp(line, "cd", 2) == 0)
		ft_chdir(line, v);
	else if (ft_strncmp(line, "env", 3) == 0)
		ft_env();
	else if (ft_strncmp(line, "setenv", 6) == 0)
		ft_setenv(&line[7], v);
	else if (ft_strncmp(line, "unsetenv", 8) == 0)
		ft_unsetenv(&line[9], v);
	else
		sh_exec_path(line, v);
}

void	shell_loop(void)
{
	char	*line;
	char	*tmp;
	t_vars	v;

	while (1)
	{
		ft_putstr("%> ");
		tmp = read_line();
		line = new_line(ft_strtrim(tmp), &v);
		free(tmp);
		if (line)
		{
			if (ft_strcmp(line, "exit") == 0)
				break ;
			else if (!ft_isempty(line))
				sh_execute(line, &v);
			free(line);
		}
	}
	free(line);
}
