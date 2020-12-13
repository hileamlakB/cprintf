#ifndef PRINTF
#define PRINTF

#define BIT_SIZE 8
#define true 1
#define false 0
typedef unsigned int bool;
/*
 *   a local buffer which will be used
 *   to store data until a syscall is made to write it
 *   in the std out
 */
#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "lexing/lexer.h"
#include "utils/utils.h"


/* printing */
int printer(char *, int);

/* parsing */

/*printer functions*/
char *_putchar(va_list, printing_format *);
char *_putstr(va_list, printing_format *);
char *_putint(va_list, printing_format *);
char *_putuint(va_list, printing_format *);
char *_putbin(va_list, printing_format *);
char *_puthex(va_list, printing_format *);
char *_putoct(va_list, printing_format *);
char *_putHex(va_list, printing_format *);
char *_putadress(va_list, printing_format *);
char *_putrts(va_list, printing_format *);
char *_putrot13(va_list, printing_format *);
char *_putS(va_list, printing_format *);

/*printf and its helpers*/
int _printf(const char *format, ...);
printing_format *parse_format(const char *);
int buf_push(char *, int *, char *);
int *print(const char *, va_list, int *, char *);

/*validity checker*/
bool is_valid_id(char);
int checkflag(printing_format *, char);
int checkwidth(printing_format *, const char *);
int checkprecision(printing_format *, const char *);
int checkmod(printing_format *, const char *);

/*parser to identify printing format*/
printing_format *parse_format(const char *);

/*printer identifier*/
char *(*get_printer(char id))(va_list, printing_format *);

/*num_utils*/
int _pow(unsigned int, int);
int _numLen(unsigned int);
int max(int, int);
char *to_hex(int);

/*string utils*/
void rev_string(char *);
void _toStr(unsigned long int, char *);
char *_strcpy(char *, char *);
char *rot13(char *);

#endif /*PINTF*/

