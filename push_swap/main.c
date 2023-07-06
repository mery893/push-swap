/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:19:13 by mennaji           #+#    #+#             */
/*   Updated: 2023/07/06 18:24:18 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

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

int ft_check_num(char *num)
{
    int i;

    i = 0;
    if(num[0] == '-')
        i++;
    while(num[i])
    {
        if(!ft_isdigit(num[i]))
            return(0);
        i++;
    }
    return (1);
}

// int ft_checkDuplicate(char **args, int index)
// {
//     char *current;
//     int i;
//     int j;

//     current = args[index];
//     i = 0;
//     j = 0;
//     while(i < index){
//         j = 0;
//         while(args[i][j] && current[j]){
//             if(args[i][j] != current[j])
//                 break;
//             j++;
//         }
//         if(args[i][j] == '\0' && current[j])
//             return (1);
//         i++;
//     }
//     return (0);
// }

void ft_checkArgs(int argc, char **argv)
{
    int i;
    long ptr;
    char **args;

    i = 0;
    if(argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while(args[i])
    {
        ptr = ft_atoi(args[i]);
        if(!ft_check_num(args[i]))
            ft_error("Error\n");
        if(!ft_contains(ptr, args, i))
            ft_error("Error\n");
        // if(ft_checkDuplicate(args, i))
        //     ft_error("Error\n");
        if(ptr < -2147483648 || ptr > 2147483647)
            ft_error("Error\n");
        i++;
    }
    if(argc == 2)
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
	head = getTheMin(stack);
	while (head)
	{
		head->index = index++;
		head = getTheMin(stack);
	}
}

void ft_stackInit(t_list **stack, int argc, char **argv)
{
    t_list *new_node;
    char **args;
    int i;

    i = 0;
    args = NULL;
    if(argc == 2)
        args = ft_split(argv[i], ' ');
    else{
        i = 1;
        args = argv;
    }
    while(args[i])
    {
        new_node = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(stack, new_node);
        i++;
    }
    indexStack(stack);
    if(argc == 2)
        free(args);
}
int checkDuplicate(t_list *stack)
{
    int tmp;
    t_list *dup;

    while(stack && stack->next)
    {
        tmp = stack->value;
        dup = stack;
        while(dup->next)
        {
            dup = dup->next;
            if(dup->value == tmp)
                return (-1);
        }
        stack = stack->next;
    }
    return (1);

}

void sort_stack(t_list **stack_a, t_list **stack_b){
   if(ft_lstsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    t_list **stack_a;
    t_list **stack_b;

    if(argc < 2)
        return (-1);
    ft_checkArgs(argc, argv);
    stack_a = (t_list**)malloc(sizeof(t_list));
    stack_b = (t_list**)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    ft_stackInit(stack_a, argc, argv);
    if(checkDuplicate(*stack_a) == -1)
        ft_error("Error\n");
    if(is_sorted(stack_a))
    {
        free(stack_a);
        free(stack_b);
        return (0);
    }
    sort_stack(stack_a, stack_b);
    printList(*stack_a);
    free(stack_a);
    free(stack_b);
    return (0);
}
