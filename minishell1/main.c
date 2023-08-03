/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:51 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/02 18:37:35 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char **ft_extend_matrix(char **matrix, char *new_string)
{
	int num_rows;
	int i;
	int j;
	char **new_matrix;

	i = 0;
	while(matrix[num_rows])
		num_rows++;
	new_matrix = (char**)malloc(sizeof(char*) * (num_rows + 1));
	while(i++ < num_rows){
		new_matrix[i] = (char*)malloc(matrix[i] + 1);
		if(!new_matrix[i]){
			while(j++ < i)
				free(new_matrix[j]);
			free(new_matrix);
		}
		ft_strcpy(new_matrix[i], matrix[i]);	
	}
}
char **set_or_update(char *var, char *value, char **envp, int n)
{
	char *new_entry;
	int i;

	i = 0;
	if(n < 0)
		n = ft_strlen(var);
	new_entry = (char *)malloc(n + ft_strlen(value) + 1);
	if(!new_entry)
		return (NULL);
	ft_strncpy(new_entry, var, n);
	new_entry[n] = '=';
	ft_strcpy(new_entry + n + 1, value);
	//if an existing variable entry with the same name of as the new entry is found in the envp array
	while(envp[i])
	{
		if(!ft_strcmp(envp[i], var, n) && envp[i][n] == '='){
			free(envp[i]);
			envp[i] = new_entry;
			return (envp);
		}
		i++;
	}
	envp = ft_extend_matrix(envp, new_entry);
	free(new_entry);
	return (envp);
}

t_prompt set_env(t_prompt prompt, char *str, char **av)
{
	str = getcwd(NULL, 0); //current  working directory
	prompt.envp = set_or_update_env("PWD", str, prompt.envp,3);
	free(str);

}

int main(int ac, char **av, char **env)
{
	if(ac != 2)
	{
		handle_error(ARGS_ERROR, 1, NULL);
		exit(EXIT_FAILURE);
	}
	set_env();
}
