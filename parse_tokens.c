#include "sh.h"

int 				semantica(t_flag *flag, char *line, int i, int j)
{
	if (flag->d_quot % 2 != 0)
		return (1);
	if (flag->u_quot % 2 != 0)
		return (1);
	if (line[i - 1] && line[i - 1] == 92)
		return (1);
	if (j == 0)
		return (2);
	return (0);
}

void 				update_flag(t_flag *flag, char s)
{
	if (s == 34)
		flag->d_quot += 1;
	if (s == 39)
		flag->u_quot += 1;
	if (s == 92)
		flag->bs += 1;
}

char 				*get_data(char *line, int *n, t_flag *flag)
{
	char 			res[1000];
	int 			j;
	char			*ret;
	int 			i;

	j = 0;
	i = *n;
	while (line[i] != '|' && line[i] != ';' && line[i] != '&' && line[i] != '\0')
	 {
		update_flag(flag, line[i]);
		if (line[i] == 34)
			flag->d_quot += 1;
		if (line[i] == 39)
			flag->u_quot += 1;
		if (line[i] == 92)
			flag->bs += 1;
		res[j++] = line[i++];
		}
	if (line[i] == '|' || line[i] == ';' || line[i] == '&' || line[i] == '\0')
	{
		res[j] = line[i];
		if (semantica(flag, line, i, j) == 1)
		{
			i++;
			j++;
		}
		if (semantica(flag, line, i, j) == 0)
		{
			res[j] = '\0';
			ret = ft_strtrim(ft_strdup(res));
			*n = i;
			return (ret);
		}
		if (semantica(flag, line, i, j) == 2)
		{
			if (line[i] == ';')
			{
				res[++j] = '\0';
				ret = ft_strtrim(ft_strdup(res));
				*n = i + 1;
				return (ret);
			}
			if (line[i] == '|')
			{
				if (line[i + 1] == '|')
				{
					res[++j] = line[++i];
					res[++j] = '\0';
					*n = i + 1;
					ret = ft_strtrim(ft_strdup(res));
					return (ret);
				}
				else
				{
					res[++j] = '\0';
					*n = i + 1;
					ret = ft_strtrim(ft_strdup(res));
					return (ret);
				}
			}
			if (line[i] == '&')
			{
				if (line[i + 1] == '&')
				{
					res[++j] = line[++i];
					res[++j] = '\0';
					*n = i + 1;
					ret = ft_strtrim(ft_strdup(res));
					return (ret);
				}
				else
				{
					res[++j] = '\0';
					*n = i + 1;
					ret = ft_strtrim(ft_strdup(res));
					return (ret);
				}
			}
		}
	}
	*n = i;
	return (NULL);
}

int 			main(void)
{
	t_token		*token;
	char 		*line;
	int 		car;
	t_flag		*flag;
	int 		l;

	line = NULL;
	car = 0;
	get_next_line(0, &line);
	l = ft_strlen(line);
	token = init_token();
	flag = init_flag();
	token->data = get_data(line, &car, flag);
	while (car < l)
	{
		token->next = init_token();
		token->next->prev = token;
		token = token->next;
		token->data = get_data(line, &car, flag);

	}
	ft_putendl(line);
	return (0);
}
