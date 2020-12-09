#include "sh.h"

void 				reset_flag(t_flag *flag)
{
	flag->d_quot = 0;
	flag->u_quot = 0;
	flag->sep = 0;
	flag->bs = 0;
}

t_flag				*init_flag(void)
{
	t_flag			*new;

	new = (t_flag *)malloc(sizeof(t_flag));
	new->d_quot = 0;
	new->u_quot = 0;
	new->sep = 0;
	new->bs = 0;
	return (new);
}