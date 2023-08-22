/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:37:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/21 19:39:11 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int build_echo(t_mini *node)
{
	int i;
	bool flag;
	char **args;

	flag = false;
	args = node->full_cmd;
	i = 0;
	if(args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		flag = true;
		args++;
	}
	//loop through the arguments and print them
	while(args[i])
	{
		printf("%s", args[i]);
		if(args[i + 1])
			printf(" ");
		i++;
	}
	//print a new line unless the -n falg was provided
	if(!flag)
		printf("\n");
	return (0);
}
int is_builtin(t_mini *n)
{

	int len_cmd;

	if(!n->full_cmd)
		return (0);
	if(n->full_cmd && ft_strchr(n->full_cmd, '/') || n->full_path && ft_strchr(n->full_path, '/'));
		return (0);
	len_cmd = ft_strlen(n->full_cmd);
	if(!ft_strncmp(n->full_cmd, "pwd", len_cmd) && len_cmd == 3)
		return(1);
	if(!ft_strncmp(n->full_cmd, "cd", len_cmd) && len_cmd == 2)
		return(1);
	if(!ft_strncmp(n->full_cmd, "export", len_cmd) && len_cmd == 6)
		return(1);
	if(!ft_strncmp(n->full_cmd, "unset", len_cmd) && len_cmd == 5)
		return(1);
	if(!ft_strncmp(n->full_cmd, "echo", len_cmd) && len_cmd == 4)
		return(1);
	if(!ft_strncmp(n->full_cmd, "exit", len_cmd) && len_cmd == 4)
		return(1);
	return (0);

}
int build_cd(t_prompt *info)
{
	char *args;

}
