#ifndef _SHELL_H
#define _SHELL_H
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stddef.h>
#define DELIM " \n"
extern char **environ;
int mymain(char **i, char *bu, int exv);
int mycdf(char **in);
char *f_pa(char **i, char *pa, char *t);
char **parli(char *bf);
int pro(void);
int ns(char *t);
char *ms(char *w, char t, unsigned int by);
char *mysdup(char *t);
void sighand(int s);
int myscmpp(const char *p, const char *environ);
char *mygetline(void);
char *myscat(char *to, const char *from);
int mysncmp(const char *sf, const char *ss, size_t n);
int myslen(const char *t);
char *mysncat(char *to, const char *from, size_t i);
char *myscpy(char *to, const char *from);
char *mygenv(const char *p);
int pa_me(char *t);
void *mypenv(void);
int exe(char **in, char *bu, char *fpb, char *av);
char *conca(char *t, char **in, char *to);



#endif

