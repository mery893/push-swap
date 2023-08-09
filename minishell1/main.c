/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:51 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/09 17:20:28 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

char **ft_extend_matrix(char **matrix, char *new_string)
{
	int size;
	int i;
	char **extended_matrix; //variable to store the extende matrix

	size = 0;
	i = 0;
	extended_matrix = NULL;
	while(matrix[size])
		size++;
	extended_matrix = (char **)malloc((size + 2) * sizeof(char *));
	if (!extended_matrix)
        return NULL;
    // Copy existing strings from matrix to extended_matrix using a while loop
    int i = 0;
    while (i < size)
	{
        extended_matrix[i] = ft_strdup(matrix[i]);
		if (!extended_matrix[i]) {
            // Failed to allocate memory for the string, free the extended_matrix and return NULL
            while (i-- > 0)
                free(extended_matrix[i]);
            free(extended_matrix);
            return NULL;
        }
        i++;
    }
    // Copy the new_string into the last element of the extended_matrix
    extended_matrix[size] = ft_strdup(new_string);
    if (!extended_matrix[size])
	{
        // Failed to allocate memory for the string, free the extended_matrix and return NULL
        while (i-- > 0)
            free(extended_matrix[i]);
        free(extended_matrix);
        return NULL;
    }
    // Set the next element after the new_string to NULL
    extended_matrix[size + 1] = NULL;
    // Free the old matrix and return the extended_matrix
    free(matrix);
    return extended_matrix;
}

char *get_env();
//set the PWD environment variable with the value of str.
//The resulting environment variable array is stored back in prompt.envp.
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
		if(!ft_strcmp(envp[i], var, n) && envp[i][n] == '=')
		{
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
	prompt.envp = set_or_update_env("PWD", str, prompt.envp,3); //set the pwd environment
	free(str);
	str =
}

int main(int ac, char **av, char **env)
{
	if(ac != 2)
	{
		handle_error(ARGS_ERROR, 1, NULL);
		exit(EXIT_FAILURE);
	}
	set_env();
	handles_error();
}
