/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:40 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/19 18:29:50 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
#define MINISHELL1_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_prompt{
	char *cmds;
	char **envp;
	int pid;
}t_prompt;

typedef struct s_list
{
	void *content;
	t_list struct *next;
}t_list;

typedef struct s_mini
{
	char	**full_cmd; //array  of strings representing the full command and its arguments
	char	*full_path;

}			t_mini;
typedef enum e_handle_error
{
	COMMAND_NOT_FOUND,
	SYNTAX_ERRORS,
	REDIRECTION_ERRORS,
	PERMISSION_ERRORS,
	MEMORY_ALL_ERRORS,
	ENV_VAR_ERRORS,
	FILE_NOT_FOUND,
	BUILT_IN_COMMAND_ERRORS,
	INPUT_ERRORS,
	PIPE_RED_ERRORS,
	INVALID_ARG_ERRORS
} t_handle_error;

#endif
