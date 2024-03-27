#include <stdlib.h>
#include <termios.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (i[s] != '\0')
		i++;
	return (i);
}

// char	*ft_exportdup(char *s)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 3));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (j[s] != '\0')
// 	{
// 		i[str] = j[s];
// 		if (j[s] == '=')
// 			str[++i] = '"';
// 		if (j[s + 1] == '\0')
// 			str[++i] = '"';
// 		i++;
// 		j++;
// 	}		
// 	i[str] = '\0';
// 	return (str);
// }

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	char *str = ft_exportdup("toprak=toprakbalci");
	printf("%s\n",str);
	write(2, "minikshell$: ", 14);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
} 