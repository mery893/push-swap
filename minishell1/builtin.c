/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:37:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/29 16:06:09 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int build_cd(t_prompt *info);
int build_exit(t_prompt *info);
int build_export(t_prompt *info);
int build_unset(t_prompt *info);
int build_echo(t_mini *node);
int builtin_command(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int is_builtin(t_mini *n);

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

int builtin_command(t_prompt *prompt, t_list *cmd, int *is_exit, int n)
{
	char **parsed_cmd; //(the parsed command tokens)
	int status;

	n = 0;
	while(cmd)
	{
		parsed_cmd = ((t_mini *)cmd->content)->full_cmd;
		if(parsed_cmd)
			n = ft_strlen(*parsed_cmd);
		if(parsed_cmd && !ft_strncmp(*parsed_cmd, "exit", n) && n == 4)
			status = build_exit(prompt);
		else if (!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "cd", n) && n == 2)
			status = build_cd(prompt);
		else if((!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "export", n) && n == 2))
			status = build_export((prompt);
		else if( (!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "unset", n) && n == 2))
			status = build_unset(prompt);
		else{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			execute_cmd(); //responsible for executing a command in a shell pipeline
		}
		cmd = cmd->next;
	}
	return (status);
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
	char *current_path;
	char *new_path;

	args = ((t_mini *)info->cmds->content)->full_cmd[1]; //get the second argument
	if(args == NULL){
		args = get_env("HOME", info->envp, 4);
		if(args == NULL)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
	}
	current_path = getcwd(NULL, 0);
	if(!current_path){
		perror("cd");
		return(1);
	}
	if(chdir(args) == -1)
	{
		if(args[0] == '\0')
			return (1);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(args, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	info->envp = set_or_update("OLDPWD", current_path, info->envp, 6);
	new_path = getcwd(NULL, 0);
	if(!new_path)
	{
		perror("cd");
		return (1);
	}
	info->envp =  set_or_update("PWD", new_path, info->envp, 3);
	free(new_path);
	return (0);
}
