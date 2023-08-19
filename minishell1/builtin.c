/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:37:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/19 18:57:09 by mennaji          ###   ########.fr       */
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

int build_cd(t_prompt *info)
{
	char **args;
	char *value;

	if(args == NULL)
	{
		value = get_env("HOME", info->envp, 4);
		if(chdir(value) == - 1)
			return (-1);
		free(value);

	}
}
