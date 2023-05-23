#include "shell.h"
/**
 * ms - program used to return the memory
 * @t: used to store the text
 * @w: used to store char
 * @by: used to store byte
 * Return: success
 */
char *ms(char *w, char t, unsigned int by)
{
	unsigned int n;

	for (n = 0; n < by; n++)
		w[n] = t;
	return (w);
}
/**
 * mysdup - prigram used to make copy of the text
 * @t: used to store the text
 * Return: success
 */
char *mysdup(char *t)
{
	char *s;
	size_t l, n;

	l = myslen(t);
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
	{
		return (NULL);
	}
	for (n = 0; n <= l; n++)
		s[n] = t[n];
	return (s);
}
/**
 * sighand - program used to handel a signal
 * @s: used to store the signal
 */
void sighand(int s)
{
	if (s == SIGINT)
	{
		write(1, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
/**
 * myscmpp - program used to compare path
 * @environ: used to get the enviroment
 * @p: used to store the path
 * Return: suceess
 */
int myscmpp(const char *p, const char *environ)
{
	int n;

	for (n = 0; environ[n] != '='; n++)
	{
		if (p[n] != environ[n])
			return (1);
	}
	return (0);
}
/**
 * mygetline - program used to get line of input
 * Return: success
 */
char *mygetline(void)
{
	int n = 0;
	char *bu = NULL;
	size_t t = 0;
	ssize_t y = 0;

	y = getline(&bu, &t, stdin);
	if (y == -1)
	{
		free(bu);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (bu[y - 1] == '\n' || bu[y - 1] == '\t')
		bu[y - 1] = '\0';
	for (n = 0; bu[n]; n++)
	{
		if (bu[n] == '#' && bu[n - 1] == ' ')
		{
			bu[n] = '\0';
			break;
		}
	}
	return (bu);
}

