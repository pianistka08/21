#ifndef SH_H
#define SH_H

# include "libft.h"

typedef enum {
	semicolon = 1,
	and = 2,
	oro = 3,
	pip = 4,
	cmd = 5,
}				t_type_token;

typedef struct 			s_flag
{
	int 				bs; /// back-slash
	int 				d_quot; /// " кроме $, '', '\'
	int 				u_quot; /// ' отменяет все спецсимволами
	int 				sep; /// что поместить в следующий токен
}						t_flag;

typedef struct			s_token
{
	char 				*data;
	int 				priority;
	struct s_token				*next;
	struct s_token				*prev;
}						t_token;

t_flag				*init_flag(void);
void 				reset_flag(t_flag *flag);
t_token 			*init_token(void);

#endif
  