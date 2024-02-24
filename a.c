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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i[s] != '\0')
	{
		i[str] = i[s];
		i++;
	}
	i[str] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


static char	**ft_deallocate(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(str[j++]);
	free(str);
	return (NULL);
}

static int	pass_char(char const *s, char c, int i)
{
	int	a;

	a = 0;
	if (i)
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
	}
	else
	{
		while (s[a] != '\0' && s[a] != c)
			a++;
	}
	return (a);
}

static int	word_counter(char const *s, char c)
{
	int	word_number;
	int	i;

	i = 0;
	word_number = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		word_number++;
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (word_number);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word_number;
	int		i;

	i = 0;
	word_number = word_counter(s, c);
	str = (char **)malloc(sizeof(char *) * (word_number + 1));
	while (i < word_number)
	{
		s = s + pass_char(s, c, 1);
		str[i] = ft_substr(s, 0, pass_char(s, c, 0));
		if (!str)
			return (ft_deallocate(str, word_number));
		s = s + pass_char(s, c, 0);
		i++;
	}
	str[i] = NULL;
	return (str);
}


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
		while (s[i][j] != '\0' && s[i][j] == ' ')
		{
			j++;
		}
		while (s[i][j])
		{
			while (s[i][j] != '\0' && s[i][j] != ' ')
				j++;
			word_number++;
			while (s[i][j] != '\0' && s[i][j] == ' ')
				j++;
		}
		i++;
	}
	return (word_number);
}

int	dp_nl(char **s)
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
		while (s[i][j] != '\0' && s[i][j] == '\n')
		{
			j++;
		}
		while (s[i][j])
		{
			while (s[i][j] != '\0' && s[i][j] != '\n')
				j++;
			word_number++;
			while (s[i][j] != '\0' && s[i][j] == '\n')
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

	char **str = ft_split("toprak= balci", '=');
	printf("%d\n",dp_nl(str));
} 