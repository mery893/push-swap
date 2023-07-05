/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/05 18:35:55 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_contains(int num, char **av, int i)
{
    while(av[i])
    {
        if(ft_atoi(av[i]) == num)
            return(1);
        i++;
    }
    return (0);
}

int ft_check_num(int *num)
{
    int i;

    i = 0;
    if(num[0] == '-')
        i++;
    while(num[i])
    {
        if(!ft_isdigit(num[i]))
            return(1);
        i++;
    }
    return (0);
}

int ft_checkArgs(int argc, char **argv)
{
    int i;
    long ptr;
    char *args;

    i = 0;
    if(args == 2)
        args = ft_split(argv[1], ' ');
    while(args[i])
    {
        ptr = ft_atoi(argv[i]);
        if(!ft_check_num(args[i]))
            write(1, "Error\n", 7);
        if(!ft_contains(ptr, argv, i))
            write(1, "Error\n", 7);
        if(ptr < -2147483648 || ptr > 2147483647)
            write(1, "Error\n", 7);
        i++;
    }
    if(args == 2)
        free(args);
}

t_list *getTheMin(t_list **stack)
{
    t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void  indexStack(t_list **stack)
{
    t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void ft_stackInit(t_list **stack, int argc, char **argv)
{
    t_list *new_node;
    char **args;
    int i;

    i = 0;
    if(argc == 2)
        *args = ft_split(argv[i], ' ');
    else{
        i = 1;
        argv = args;
    }
    while(args[i])
    {
        new_node = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(stack, new_node);
        i++;
    }
    indexStack(stack);
    if(args == 2)
        free(args);
}

void sort_stack(t_list **stack_a, t_list **stack_b){
    if(ft_lstsize(stack_a) <= 5)
        simple_sort();
    else
        radix_sort();
}
int main(int argc, char **argv)
{
    t_list **stack_a;
    t_list **stack_b;

    if(argc > 2)
        return (-1);
    ft_checkArgs(argc, argv);
    *stack_a = (t_list**)malloc(sizeof(t_list));
    *stack_b = (t_list**)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    ft_stackInit(stack_a, argc, argv);
}
