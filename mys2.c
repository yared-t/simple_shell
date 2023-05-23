#include "shell.h"
/**
 * myscat - used sum up two strings
 * @from: used to store the stirng
 * @to: used to accept the commig
 * Return: success
 */
char *myscat(char *to, const char *from)
{
	const char *ft;
	char *tot;

	tot = to;
	ft = from;
	while (*tot != '\0')
		tot++;
	while (*ft != '\0')
		*tot++ = *ft++;
	*tot = '\0';
	return (to);
}
/**
 * mysncmp - program used to compare stinrgs
 * @sf: the first string
 * @ss: string second
 * @n: number of characters to be compared
 * Return: success
 */
int mysncmp(const char *sf, const char *ss, size_t n)
{
	size_t t;

	for (t = 0; sf[t] && ss[t] && t < n; t++)
	{
		if (sf[t] > ss[t])
			return (sf[t] - ss[t]);
		else if (sf[t] < ss[t])
			return (sf[t] - ss[t]);
	}
	if (t == n)
		return (0);
	else
		return (-15);
}
/**
 * myslen - progrma used to cont the string
 * @t: used to store the text to be counted
 * Return: sucees
 */
int myslen(const char *t)
{
	int l = 0;

	if (!t)
		return (l);
	for (l = 0; t[l]; l++)
		;
	return (l);
}
/**
 * mysncat - program used to concat n strings
 * @to: used to store the new
 * @from: used to store the source
 * @i: used to store the numbere
 * Return: success
 */
char *mysncat(char *to, const char *from, size_t i)
{
	size_t t, tol = myslen(to);

	for (t = 0; t < i && from[t] != '\0'; t++)
		to[tol + t] = from[t];
	to[tol + t] = '\0';
	return (to);
}
/**
 * myscpy - program used to copy
 * @from: used to store the source
 * @to: used to store string
 * Return: success
 */
char *myscpy(char *to, const char *from)
{
	size_t n;

	for (n = 0; from[n] != '\0'; n++)
		to[n] = from[n];
	to[n] = '\0';
	return (to);
}

