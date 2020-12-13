#include "sh.h"

/*t_tree				*grow_tree(t_token *token)
{
	t_tree 			*root;
	t_tree 			*cur;
	t_tree 			*p;
	t_token 		*t;

	t = get_last_token(token);
	cur = init_tree();
	root = cur;
	p = init_tree();
	cur->data = t->data;
	if (t->type == ext)
		set_child(cur, p, ext);
	if (t->type == cmd)
	return (root);
}*/

int 				find_first_priority(t_token *t)
{
	t_token			*cur;

	cur = t;
	while (cur)
	{
		if (t->priority == 1)
			return (1);
		cur = cur->prev
	}
	return (0);
}

char 				*find_data(t_token *t)
{
	if (find_first_priority(t))
		return (t->data);
	if (second_priority(t))
		return (t->data)
}

t_tree				*get_root(t_token *t, t_tree *root)
{
	root->data = find_data(t);
	return (root);
}

t_tree				*priority(t_tree *root, t_token *token)
{
	t_token 		*cur;

	cur = get_last_token(token);
	root = get_root(cur, root);
	return (root);
}

t_tree				*get_tree(t_token *token)
{
	t_tree 			*tree;

	tree = init_tree();
	//tree = grow_tree(token);
	tree = priority(tree, token);
}
