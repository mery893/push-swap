/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:40 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/01 17:16:10 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
#define MINISHELL1_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum hanle_error
{
	NO_EXISTING_FILE,
	ERROR_NUM_ARGS,
	TOO_MANY_ARGS_ERROR,
	ENV_NOT_FOUND,
	INVALID_ENV,
	ARGS_ERROR,
	TOKEN_NOT_RECOGNIZED,
	ERROR_INPUT,
	PATH_ERROR,
	EXIT_ARGS_ERROR,
	PWD_INVALID_ARGS,
	COMMAND_NOT_FOUND,
	COMMAND_EXECUTE_FAILED,
} t_handle_error;

#endif
