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

/*int 				find_first_priority(t_token *t)
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
}*/

t_token 			*third_priority(t_token *t)
{
	while (t)
	{
		if (ft_strcmp(t->data, PIPE) == 0)
		{
			if (t->next->prev)
				t->next->prev = NULL;
			return (t);
		}
		t = t->prev;
	}
	return (NULL);
}

t_token 			*second_priority(t_token *t)
{
	while (t)
	{
		if (ft_strcmp(t->data, OR) == 0 || ft_strcmp(t->data, AND) == 0)
		{
			if (t->next->prev)
				t->next->prev = NULL;
			return (t);
		}
		t = t->prev;
	}
	return (NULL);
}

t_token 			*first_priority(t_token *t)
{
	while (t)
	{
		if (ft_strcmp(t->data, SC) == 0) {
			if (t->next->prev)
				t->next->prev = NULL;
			return (t);
		}
		t = t->prev;
	}
	return (NULL);
}

t_token 			*find_priority(t_token *t)
{
	t_token			*cur;
	t_token 		*res;

	cur = t;
	if (cur->priority == -1)
		return (NULL);
	res = first_priority(cur);
	if (res != NULL)
	{
		res->priority = -1;
		return (res);
	}
	res = second_priority(cur);
	if (res != NULL)
	{
		res->priority = -1;
		return (res);
	}
	res = third_priority(cur);
	if (res != NULL)
	{
		res->priority = -1;
		return (res);
	}
	if (res == NULL)
	{
		cur->priority = -1;
		return (cur);
	}
}

t_token 			*find_alive(t_token *t)
{
	t_token 		*res;

	res = get_last_token(t);
	while (res)
	{
		if (res->priority != -1)
			return (res);

	}
	return (NULL);
}

t_tree				*get_tree(t_token *t)
{
	t_tree 			*root;
	t_token 		*data;
	t_tree 			*cur;
	t_tree 			*cur_r;

	cur_r = NULL;
	data = get_last_token(t);
	root = init_tree();
	cur = root;
	while (data->priority != -1)
	{
		cur->token = find_priority(data);
		if (data->priority != -1)
		{
			cur->right = init_tree();
			cur->right->parent = cur;
			cur = cur->right;
		}
	}
	while (cur != root)
	{
		if (cur->parent)
			data = cur->parent->token->prev;
		cur->parent->left = init_tree();
		cur_r = cur->parent->left;
		cur_r->parent = cur->parent;
		while (data->priority != -1)
		{
			cur_r->token = find_priority(data);
			if (data->priority != -1)
			{
				cur_r->left = init_tree();
				cur_r->left->parent = cur_r;
				cur_r = cur_r->left;
			}
		}
		cur = cur->parent;
	}
	return (root);
}