#include "minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	free node address (used for env linked list)
*/
void	free_nodes(t_variable **list)
{
	t_variable	*next_node;

	if (list)
	{
		while (*list)
		{
			next_node = (*list)->next;
			free(*list);
			*list = next_node;
		}
	}
}

/*
	free node address and node content (name and value)
	(used for current linked list)
*/
void	free_nodes_contents(t_variable **list)
{
	t_variable	*tmp;

	while (*list)
	{
		if ((*list)->name)
			free((*list)->name);
		if ((*list)->value)
			free((*list)->value);
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

/*
	insert a node in the correct alphabetical order
*/
void	insert_new_node(t_variable **export, t_variable *new)
{
	t_variable	*prev;
	t_variable	*current;

	prev = NULL;
	current = *export;
	while (current)
	{
		if (ft_strcmp(current->name, new->name) >= 0)
		{
			if (prev)
				prev->next = new;
			else
				(*export) = new;
			new->next = current;
			return ;
		}
		prev = current;
		current = current->next;
	}
	if (!current)
		prev->next = new;
}

t_variable	*get_last_node(t_variable *list)
{
	t_variable	*last;

	if (!list)
		return (NULL);
	last = list;
	while (list)
	{
		last = list;
		list = list->next;
	}
	return (last);
}

void	add_node_back(t_variable **list, t_variable *new)
{
	t_variable	*last;

	if (*list && new)
	{
		last = get_last_node(*list);
		last->next = new;
	}
	else
		*list = new;
}
