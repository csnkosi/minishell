/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnkosi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:48:57 by cnkosi            #+#    #+#             */
/*   Updated: 2017/09/29 02:55:23 by cnkosi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*chdir_home(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "HOME", 4) == 0)
		{
			return (&environ[i][5]);
			break ;
		}
		i++;
	}
	return (NULL);
}

char	*chdir_prev(void)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "OLDPWD", 6) == 0)
		{
			return (&environ[i][7]);
			break ;
		}
		i++;
	}
	return (NULL);
}

void	update_pwd(char *old_pwd, char *cur_pwd)
{
	t_vars	v;
	char	*tmp_old;
	char	*tmp_cur;

	tmp_old = (char*)malloc(sizeof(tmp_old) * (ft_strlen(old_pwd) + 8));
	tmp_cur = (char*)malloc(sizeof(tmp_cur) * (ft_strlen(cur_pwd) + 5));
	tmp_old = ft_strcpy(tmp_old, "OLDPWD=");
	tmp_old = ft_strjoin(tmp_old, old_pwd);
	ft_setenv(tmp_old, &v);
	free(tmp_old);
	tmp_cur = ft_strcpy(tmp_cur, "PWD=");
	tmp_cur = ft_strjoin(tmp_cur, cur_pwd);
	ft_setenv(tmp_cur, &v);
	free(tmp_cur);
}

void	change_dir(char *path, char *old_wd, t_vars *v)
{
	char	buff[1000];

	v->token = ft_strsplit(path, ' ');
	if (ft_strcmp(v->token[0], "cd") == 0)
	{
		if (chdir(v->token[1]) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(v->token[1]);
		}
		else
			update_pwd(old_wd, getcwd(buff, sizeof(buff)));
		free(v->token[0]);
		free(v->token[1]);
	}
	else
		ft_putendl("cd failed");
}

void	ft_redirect(char *path, char *old_wd, t_vars *v)
{
	v->s = ft_strnew(1);
	while (ft_isspace(path[v->len - 1]))
		v->len--;
	if (ft_strcmp(path, "cd -") == 0)
	{
		chdir(chdir_prev());
		update_pwd(old_wd, getcwd(v->buff, sizeof(v->buff)));
	}
	else if (ft_strncmp(path, "cd ~", 4) == 0)
	{
		v->s = ft_strcpy(v->s, "cd ");
		v->s = ft_strjoin(v->s, &path[5]);
		chdir(chdir_home());
		change_dir(v->s, old_wd, v);
		update_pwd(old_wd, getcwd(v->buff, sizeof(v->buff)));
		free(v->s);
	}
	else if (ft_strncmp(path, "cd", 2) == 0 &&
			(v->len == 2 || ft_wrd_cnt(path) == 1))
	{
		chdir(chdir_home());
		update_pwd(old_wd, getcwd(v->buff, sizeof(v->buff)));
	}
	else
		change_dir(path, old_wd, v);
}
