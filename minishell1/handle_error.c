/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:23:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/02 14:59:20 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

void handle_error(t_handle_error type_error, int error_status, void *args)
{
	int copy;

	copy = dup(STDOUT_FILENO);
	if(type_error == NO_EXISTING_FILE);
		ft_no_existing_file();
	if(type_error == ENV_NOT_FOUND)
		ft_env_not_found();
	if(type_error == ARGS_ERROR)
		ft_args_error();
	if(type_error == TOKEN_NOT_RECOGNIZED)
		ft_token_not_recognized();
	if(type_error == ERROR_INPUT)
		ft_error_parser();
	if(type_error == EXIT_ARGS_ERROR)
		ft_exit_args_error();
	if(type_error == COMMAND_EXECUTE_FAILED)
		ft_cmd_failed();
	if(type_error == PATH_ERROR
		|| ERROR_NUM_ARGS
		|| TOO_MANY_ARGS_ERROR
		|| INVALID_ENV
		|| COMMAND_NOT_FOUND
		|| PWD_INVALID_ARGS)
		ft_put_error();
	dup2(copy, STDERR_FILENO);
}
