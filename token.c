#include "sh.h"

t_token 			*init_token(void)
{
	t_token		*new;

	if(!(new = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	new->data = NULL;
	new->priority = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}