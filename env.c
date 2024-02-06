#include "minishell.h"

void	envprint(t_lexer *lst)
{
	int	i = 0;
	while (lst->s_env.cmd[i])
	{
		printf("%s\n", lst->s_env.cmd[i]);
		i++;
	}
}

void	ft_env(t_lexer *lst, char **env)
{
	int	i;

	i = 0;
	lst->s_env.cmd = malloc(sizeof(char *) * dp_nl(env));
	while (env[i])
	{
		lst->s_env.cmd[i] = ft_strdup(env[i]);
		i++;
	}
	envprint(lst);
}