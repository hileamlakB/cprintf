#ifndef PARSER
#define PARSER

#include <stdarg.h>
#include "../printflib.h"

typedef struct edge{
	int current_state;
	char *label;
	int next_state;
	struct edge *next;
}edge;

typedef struct token{
	char *type;
	char *tok;
	int col;
}token;

/**
*struct printing_format - a struct for formating info 
*@flag: the flag used (+, -, '\0') (the flags used in printf)
*@width: the space taken during printing
*@mod: modifier (l, h)
*@precision: how many points after . in case of numbers
*@zero_fill: --
*@replaced: the length of the string that will be replaced after substitution
*@validity: is this format a complete format
*@id: format identifier (d, i, x, ...)
*@printer: a function to handle the printing
*/
typedef struct printing_format
{
	char flag;
	int width;
	char *mod;
	char id;
	int precision;
	bool zero_fill;
	int replaced;
	bool validity;
	token word;
	char *(*printer)(va_list, struct printing_format *);
} printing_format;

edge *add_edge_fsm(unsigned int, edge**, ...);
void free_fsm(edge *);
void print_fsm(edge *);
printing_format *fsm_sim(int, char *, edge *, int, int, printing_format *, char *);

/*printf_lexer*/
edge **prepare_lexer(void);


/*topken_utils*/
void update_token(printing_format *, char *, char *, int, int);

/*type check*/
char *is_id(char *);
char *is_flag(char *);
int is_mod(char *);
char *is_num(char *);
#endif /*PARSER*/
