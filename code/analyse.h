#include <stdio.h>
#include <stdlib.h>

char * word ;


char Car_Cour;
FILE *file;

enum TOKENS{
  PROGRAM_TOKEN,CONST_TOKEN,VAR_TOKEN,BEGIN_TOKEN,END_TOKEN,IF_TOKEN,THEN_TOKEN,WHILE_TOKEN,
  DO_TOKEN,READ_TOKEN,WRITE_TOKEN,PV_TOKEN,PT_TOKEN,PLUS_TOKEN,MOINS_TOKEN,MULT_TOKEN,
  DIV_TOKEN,VIR_TOKEN,AFF_TOKEN,EG_TOKEN,INF_TOKEN,INFEG_TOKEN,SUP_TOKEN,SUPEG_TOKEN,DIFF_TOKEN,
  PO_TOKEN,PF_TOKEN,FIN_TOKEN,ID_TOKEN,NUM_TOKEN,ERREUR_TOKEN,NULL_TOKEN,GUIMO_TOKEN,GUIMF_TOKEN
};

 struct code{
 
enum TOKENS token ;
 

}; 




 
 struct store{

struct code * data ; 
struct store  * next ;


};

struct store * head ;
struct code* TOK_A;


void opn_file(char *filename);
void read_car();
void analyse();

char * trans(enum TOKENS* token);

void printList() ;
void  Stockage();