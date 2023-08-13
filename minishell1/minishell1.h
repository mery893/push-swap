/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:40 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/13 15:54:29 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
#define MINISHELL1_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_prompt{
	char *cmd;
	char **envp;
	int pid;
}t_prompt;

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
