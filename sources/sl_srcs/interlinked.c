#include "so_long.h"

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
	if (ft_strcmp(answer, pass) == 1 && ft_strlen(answer) == ft_strlen(pass))
	{
		printf("You can now start game with 'interlinked' as argument.\n");
		free(answer);
	}
	else
	{
		printf("Have it your way.");
		free(answer);
		exit(EXIT_FAILURE);
	}
}

void	loading_screen(void)
{
    char spinner[] = { '|', '/', '-', '\\' };
    int i;

    for (i = 0; i < 50; i++) {
        printf("\rLoading %c attend jte DDOS en 22 le sang 😂😂", spinner[i % 4]);
        fflush(stdout);
        usleep(100000);  // Sleep for 100 milliseconds (adjust as needed)
    }

    printf("\nLoading complete!\n");
}


int	start(int ac, char **av)
{
	if (!av[1] || ft_strcmp(av[1], "interlinked") == 0 || ft_strlen(av[1]) != 11)
	{
		ask("What's it like to hold the hand of someone you love?", "interlinked\n");
		ask("Do they teach you how to feel finger to finger?", "interlinked\n");
		ask("Do you long for having your heart interlinked?", "interlinked\n");
		ask("Do you dream about being interlinked?", "interlinked\n");
		ask("Have they left a place for you where you can dream?", "interlinked\n");
		ask("What's it like to hold your child in your arms?", "interlinked\n");
		ask("What's it like to play with your dog?", "interlinked\n");
		ask("Do you feel that there's a part of you that's missing?", "interlinked\n");
		ask("Do you like to connect to things?", "interlinked\n");
		ask("What happens when that linkage is broken?", "interlinked\n");
		ask("Have they let you feel heartbreak?", "interlinked\n");
		ask_n("Why don't you say that three times?", "interlinked\n", 3);
		ask_s("Are you ready ? [yes / no]", "yes\n");
	}
	(void)ac;
	printf("Here we go.\n");
	usleep(1000000);
	system("ifconfig | grep -oP 'inet \\K[\\d.]+' | sed -n '2p'");
	usleep(1000000);
	printf("mdr ta grosse adresse ip lol");
	usleep(1000000);
	loading_screen();
	usleep(1000000);
	return (1);
}
