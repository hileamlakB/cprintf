#include "../printflib.h"

#include <stdlib.h>

edge **prepare_lexer(void)
{
	edge *fwpmi = NULL, *fwpi = NULL, *fwmi = NULL, *fwi = NULL;
	edge *fpmi = NULL, *fpi = NULL, *fmi = NULL, *fi = NULL;
	edge *wpmi = NULL, *wpi = NULL, *wmi = NULL, *wi = NULL;
	edge *pmi = NULL, *pi = NULL, *mi = NULL, *i = NULL, *word = NULL;
	edge **fsms = smalloc(sizeof(edge *) * 18);

	add_edge_fsm(11, &fwpmi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, ".", 4,
			4, "NUM", 5,
			5, "NUM", 5,
			5, "MOD", 6,
			6, "ID", 7);
	fsms[0] = fwpmi;
	add_edge_fsm(10, &fwpi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, ".", 4,
			4, "NUM", 5,
			5, "NUM", 5,
			5, "ID", 6);
	fsms[1] = fwpi;
	add_edge_fsm(8, &fwmi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, "MOD", 4,
			4, "ID", 5);
	fsms[2] = fwmi;
	add_edge_fsm(7, &fwi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, "ID", 4);
	fsms[3] = fwi;
	add_edge_fsm(9, &fpmi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, ".", 3,
			3, "NUM", 4,
			4, "NUM", 4,
			4, "MOD", 5,
			5, "ID", 6);
	fsms[4] = fpmi;
	add_edge_fsm(8, &fpi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, ".", 3,
			3, "NUM", 4,
			4, "NUM", 4,
			4, "ID", 5);
	fsms[5] = fpi;
	add_edge_fsm(6, &fmi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "MOD", 3,
			3, "ID", 4);
	fsms[6] = fmi;
	add_edge_fsm(5, &fi, 0, "%", 1,
			1, " ", 1,
			1, "FLAG", 2,
			2, " ", 2,
			2, "ID", 3);
	fsms[7] = fi;
	add_edge_fsm(9, &wpmi, 0, "%", 1,
			1, " ", 1,
			1, "NUM", 2,
			2, "NUM", 2,
			2, ".", 3,
			3, "NUM", 4,
			4, "NUM", 4,
			4, "MOD", 5,
			5, "ID", 6);
	fsms[8] = wpmi;
	add_edge_fsm(8, &wpi, 0, "%", 1,
			1, " ", 1,
			1, "NUM", 2,
			2, "NUM", 2,
			2, ".", 3,
			3, "NUM", 4,
			4, "NUM", 4,
			4, "ID", 5);
	fsms[9] = wpi;
	add_edge_fsm(6, &wmi, 0, "%", 1,
			1, " ", 1,
			1, "NUM", 2,
			2, "NUM", 2,
			2, "MOD", 3,
			3, "ID", 4);
	fsms[10] = wmi;
	add_edge_fsm(5, &wi, 0, "%", 1,
			1, " ", 1,
			2, "NUM", 3,
			3, "NUM", 3,
			3, "ID", 4);
	fsms[11] = wi;
	add_edge_fsm(7, &pmi, 0, "%", 1,
			1, " ", 1,
			1, ".", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, "MOD", 4,
			4, "ID", 5);
	fsms[12] = pmi;
	add_edge_fsm(6, &pi, 0, "%", 1,
			1, " ", 1,
			1, ".", 2,
			2, "NUM", 3,
			3, "NUM", 3,
			3, "ID", 4);
	fsms[13] = pi;
	add_edge_fsm(5, &mi, 0, "%", 1,
			1, " ", 1,
			1, "MOD", 2,
			2, "ID", 3);
	fsms[14] = mi;
	add_edge_fsm(3, &i, 0, "%", 1,
			1, " ", 1,
			1, "ID", 2);
	fsms[15] = i;
	add_edge_fsm(2, &word, 0, "NOT_%", 1,
			1, "NOT_%", 1);
	fsms[16] = word;
	fsms[17] = NULL;
	return (fsms);
}

