#include "shell.h"
/**
 * main -a program used to run the shell
 * @av: used to store the argument
 * @ac: argument counter
 * Return: Success or failure
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	int ex = 0;
	char *buf = NULL, *fpa = NULL, *pa = NULL, *t = NULL, **in;

	signal(SIGINT, sighand);
	pa = mygenv("PATH");
	if (pa == NULL)
		return (1);
	while (1)
	{
		in = NULL;
		if (isatty(STDIN_FILENO))
			pro();
		buf = mygetline();
		if (*buf != '\0')
		{
			in = parli(buf);
			if (in == NULL)
			{
				perror("parsing line error");
				free(buf);
				continue;
			}
			fpa = f_pa(in, pa, t);
			if (mymain(in, buf, ex) != 0)
				continue;
			ex = exe(in, buf, fpa, av[0]);
		}
		else
			free(buf);
	}
	return (0);
}

/**
 * mymain - a program used to compare the commands
 * @exv: used to store the exit command
 * @i: used to store the command
 * @bu: used to store the line recieved
 * Return: success
 */
int mymain(char **i, char *bu, int exv)
{
	int n;

	if (mysncmp(i[0], "cd", myslen(i[0])) == 0)
	{
		mycdf(i);
		for (n = 0; i[n]; n++)
			free(i[n]);
		free(i);
		free(bu);
		return (1);
	}
	else if (mysncmp(i[0], "env", myslen(i[0])) == 0)
	{
		mypenv();
		for (n = 0; i[n]; n++)
			free(i[n]);
		free(i);
		free(bu);
		return (1);
	}
	else if (mysncmp(i[0], "exit", myslen(i[0])) == 0)
	{
		for (n = 0; i[n]; n++)
			free(i[n]);
		free(i);
		free(bu);
		exit(exv);
	}
	else
		return (0);
}
/**
 * mycdf - program used to change the directory
 * @in: argument when the directory is entered
 * Return: successs
 */
int mycdf(char **in)
{
	if (in[1] == NULL)
	{
		if (chdir(mygenv("HOME")) != 0)
			perror("hsh");
	}
	else if (chdir(in[1]) != 0)
		perror("hsh");
	return (1);
}
/**
 * f_pa - program used to find the path
 * @t: used to accept string
 * @pa: used to store the path
 * @i: used to store the command
 * Return: success
 */
char *f_pa(char **i, char *pa, char *t)
{
	static char p[256];
	int pc = 0, pf = 0, n = 0, l = 0;
	char *coc = NULL, *fpb = NULL, *to = NULL;
	struct stat y;

	t = NULL;
	t = mysdup(pa);
	pc = pa_me(t);
	to = strtok(t, ":=");
	while (to != NULL)
	{
		coc = conca(p, i, to);
		if (stat(coc, &y) == 0)
		{
			fpb = coc;
			pf = 1;
			break;
		}
		if (n < pc - 2)
		{
			l =  myslen(to);
			if (to[l + 1] == ':')
			{
				if (stat(i[0], &y) == 0)
				{
					fpb = i[0];
					pf = 1;
					break;
				}
			}
		}
		n++;
		to = strtok(NULL, ":");
	}
	if (pf == 0)
		fpb = i[0];
	free(t);
	return (fpb);
}
/**
 * parli - used to parse the line to arguments
 * @bf: used to store the line
 * Return: success
 */
char **parli(char *bf)
{
	char **in = NULL, *to = NULL;
	int text = 0, n = 0;

	text = ns(bf);
	if (!text)
		return (NULL);
	in = malloc((text + 1) * sizeof(char *));
	if (in == NULL)
	{
		perror("allocation error");
		exit(1);
	}
	to = strtok(bf, DELIM);
	while (to != NULL)
	{
		in[n] = mysdup(to);
		to = strtok(NULL, DELIM);
		n++;
	}
	in[n] = NULL;
	return (in);
}

