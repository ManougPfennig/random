#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (!(str))
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

void	ask_n(char *str, char *pass, int n)
{
	char	*answer;

	printf("%s\n", str);
	while (n)
	{
		answer = calloc(999, sizeof(char));
		read(1, answer, 100);
		answer = to_lower(answer);
		if (ft_strcmp(answer, pass) == 0)
		{
			printf("You are way off baseline.");
			free(answer);
			exit(EXIT_FAILURE);
		}
		else
			free(answer);
		n--;
	}
}

void	ask(char *str, char *pass)
{
	char	*answer;

	printf("%s\n", str);
	answer = calloc(999, sizeof(char));
	read(0, answer, 100);
	answer = to_lower(answer);
	if (ft_strcmp(answer, pass) == 0)
	{
		printf("You are way off baseline.");
		free(answer);
		exit(EXIT_FAILURE);
	}
	else
		free(answer);
}

void	ask_s(char *str, char *pass)
{
	char	*answer;

	printf("%s\n", str);
	answer = calloc(999, sizeof(char));
	read(0, answer, 100);
	answer = to_lower(answer);
	if (ft_strcmp(answer, pass) == 1 && ft_strlen(answer) == ft_strlen(pass) + 1)
	{
		printf("You can now start game with 'interlinked' as argument.\n");
		usleep(5000000);
		free(answer);
	}
	else
	{
		printf("Have it your way.");
		free(answer);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	if (!av[1] || ft_strcmp(av[1], "interlinked") == 0 || ft_strlen(av[1]) != 11)
	{
		ask("What's it like to hold the hand of someone you love?", "interlinked");
		ask("Do they teach you how to feel finger to finger?", "interlinked");
		ask("Do you long for having your heart interlinked?", "interlinked");
		ask("Do you dream about being interlinked?", "interlinked");
		ask("Have they left a place for you where you can dream?", "interlinked");
		ask("What's it like to hold your child in your arms?", "interlinked");
		ask("What's it like to play with your dog?", "interlinked");
		ask("Do you feel that there's a part of you that's missing?", "interlinked");
		ask("Do you like to connect to things?", "interlinked");
		ask("What happens when that linkage is broken?", "interlinked");
		ask("Have they let you feel heartbreak?", "interlinked");
		ask_n("Why don't you say that three times?", "interlinked\n", 3);
		ask_s("Are you ready ? [yes / no]", "yes");
	}
	printf("Here we go.");
	return (0);
}
