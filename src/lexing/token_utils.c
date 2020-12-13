#include "../printflib.h"


void update_token(printing_format *node, char *var, char *value, int col, int mod_len)
{
	char *values = smalloc(3);

	values[2] = '\0';
	values[1] = '\0';
	values[0] = value[0];

	if (!_strcmp(var,  "MOD"))
	{
		if (mod_len == 2)
			values[1] = value[1];
		node->mod = _strdup(values);
	}
	else if (!_strcmp(var,  "FLAG"))
		node->flag = value[0];
	else if (!_strcmp(var,  "WIDTH"))
		node->width = node->width * 10 + (int)value[0] - 48;
	else if (!_strcmp(var, "PRECISION"))
	{
		if (value[0] >= 48 && value[0] <= 57)
			node->precision = node->precision * 10 + (int)value[0] - 48;
	}
	else if (!_strcmp(var,  "REPLACED"))
		node->replaced = (int)value[0] - 48;
	else if (!_strcmp(var,  "ID"))
		node->id = value[0];
	node->word.col = col;
	_strcat(node->word.tok, values);
	free(values);
}
