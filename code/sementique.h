
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct store * head_sem ;

enum TSYM{TPROG,TCONST,TVAR}	TSYM;

 struct T_TAB_IDF{

char NOM[20];

enum TSYM TIDF;

int value;

}	;
struct T_TAB_IDF* TAB_IDFS;

void table_id();
void store_prog();
void store_const();
void store_var();
void affich();
void regle1();
void check();
void regle2();
void regle3();
void regle4();
void regle5();
