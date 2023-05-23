#include "shell.h"
/**
 * pro - program used to enter to the shell command
 * Return: success
 */
int pro(void)
{
	ssize_t t = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		t = write(1, "$", 2);
		if (t == -1)
			return (1);
	}
	return (0);
}
/**
 * ns - used to get the number of the string
 * @t: used to store the text
 * Return: success
 */
int ns(char *t)
{
	int te = 0, f = 1, n;

	for (n = 0; t[n]; n++)
	{
		if (t[n] != ' ' && f == 1)
		{
			te += 1;
			f = 0;
		}
		if (t[n + 1] == ' ')
			f = 1;
	}
	return (te);
}

