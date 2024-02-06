#include <stdlib.h>
#include <termios.h>
#include <stdio.h>

int	dp_wc(char **s)
{
	int	word_number;
	int	i;
	int	j;

	j = 0;
	i = 0;
	word_number = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j] != '\0' && s[i][j] == '=')
		{
			j++;
		}
		while (s[i][j])
		{
			while (s[i][j] != '\0' && s[i][j] != '=')
				j++;
			word_number++;
			while (s[i][j] != '\0' && s[i][j] == '=')
				j++;
		}
		i++;
	}
	return (word_number);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	int	i = dp_wc(env);
	printf("%d\n", i);
} 