#include "shell.h"
/**
 * mygenv - progrma useed to give the enviro
 * @p: usd to store the path
 * Return: success
 */
char *mygenv(const char *p)
{
	int n, y;

	for (n = 0; environ[n]; n++)
	{
		y = myscmpp(p, environ[n]);
		if (y == 0)
			return (environ[n]);
	}
	return (NULL);
}
/**
 * pa_me - to get the members of the path
 * @t: used to store the text
 * Return: success
 */
int pa_me(char *t)
{
	int text = 0, f = 1;
	int n;

	for (n = 0; t[n] != '\0'; n++)
	{
		if (t[n] != ':' && f == 1)
		{
			text += 1;
			f = 0;
		}
		if (t[n + 1] == ':')
			f = 1;
	}
	return (text);
}
/**
 * mypenv - program used toprint the env
 * Return: success
 */
void *mypenv(void)
{
	int n = 0;

	while (environ[n] != NULL)
	{
		printf("%s\n", environ[n]);
		n++;
	}
	return (0);
}
/**
 * exe - used to executing commands
 * @in: used to accept the input string
 * @av: used to acce[t the argument
 * @fpb: used to get the file path
 * @bu: used to get the buffer
 * Return: success
 */
int exe(char **in, char *bu, char *fpb, char *av)
{
	pid_t pid;
	int n, stat, e, exv = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		e = execve(fpb, in, environ);
		if (e == -1)
		{
			perror(av);
			for (n = 0; in[n]; n++)
				free(in[n]);
			free(in);
			free(bu);
			exit(127);
		}
	}
		wait(&stat);
		if (WIFEXITED(stat))
			exv = WEXITSTATUS(stat);
		for (n = 0; in[n]; n++)
			free(in[n]);
		free(in);
		free(bu);
		return (exv);
}
/**
 * conca - used to concatianate stings
 * @in: used to store the input
 * @to: program used to tokenize input
 * @t: used to store the string
 * Return: success
 */
char *conca(char *t, char **in, char *to)
{
	int l = 0;

	ms(t, 0, 256);
	l = myslen(to) + myslen(in[0]) + 2;
	myscat(t, to);
	myscat(t, "/");
	myscat(t, in[0]);
	t[l - 1] = '\0';
	return (t);
}
