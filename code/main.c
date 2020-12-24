
#include <stdio.h>
#include "analyse.h"
#include "syntax.h"
#include "sementique.h"



int main(int argc,char *argv[]) {
	
  
  opn_file("test");
  printList();
  printf("**************************FIN D'ANALYSE LEXICALE ***************************************\n ");
 PROGRAM();
 if(syntax==0){
 	printf("*************compilation syntax succeed***************************** !!!\n");
 }
 else printf("********************** Compilation syntax error !!!************************************\n ");
 head=head_sem ;
 TAB_IDFS=(struct T_TAB_IDF *)malloc(sizeof(struct T_TAB_IDF)*NbrIDFS);

table_id();
affich();


}
