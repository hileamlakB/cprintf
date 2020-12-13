#ifndef MEM_UTIL
#define MEM_UTIL

#include <stdlib.h>

/*mem_util_1*/
char **sarrdup(char **);
void freedp(char **);
int arlen(char **);
void trims(char **, char *);


/*mem_util_2*/
void *smalloc(unsigned int);
void *srealloc(void *, unsigned int);

/*string_utils_1*/
int _strlen(char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);
char *_strcpy(char *, char *);

/*string_utils_2*/
int findd(char *, char *);
int fnrep(char **, char *, char *);
int _strcmpd(char *, char *);
int _strcmps(char *, char *);
char *_strtok(char *, char *, int);



#endif /*MEM_UTIL*/
