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
char *format_char(va_list, printing_format *);
char *format_str(va_list, printing_format *);
char *format_int(va_list, printing_format *);
char *format_uint(va_list, printing_format *);
char *format_bin(va_list, printing_format *);
char *format_hex(va_list, printing_format *);
char *format_oct(va_list, printing_format *);
char *format_Hex(va_list, printing_format *);
char *format_adress(va_list, printing_format *);
char *format_rts(va_list, printing_format *);
char *format_rot13(va_list, printing_format *);
char *format_S(va_list, printing_format *);

/*printf and its helpers*/
int _printf(const char *format, ...);
printing_format *parse_format(const char *);
int printer(char *, int);

/*parser to identify printing format*/
printing_format *parse_format(const char *);

/*printer identifier*/
char *(*get_formater(char id))(va_list, printing_format *);

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

