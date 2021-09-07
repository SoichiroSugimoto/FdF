#include "../includes/fdf.h"

void	init_lst(t_coord *lst)
{
	lst->z = 0;
	lst->color = 0;
	lst->next = NULL;
}

void	ft_lstadd_back(t_coord **lst, t_coord *new)
{
	while (*lst)
		lst = &((*lst)->next);
	*lst = new;
}

char	*ft_strdup_till(const char *s1, char c)
{
	char	*p;
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (s1[cnt] && s1[cnt] != c)
		cnt++;
	p = (char *)malloc(sizeof(char) * (cnt + 1));
	malloc_error(p);
	while (i < cnt)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
