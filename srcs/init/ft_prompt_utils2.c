#include "minishell.h"

void	prompt_cat(char *prompt, const char *element, unsigned int *i)
{
	unsigned int	j;

	if (!prompt || !element)
		return ;
	j = 0;
	while (element[j])
		prompt[(*i)++] = element[j++];
}
