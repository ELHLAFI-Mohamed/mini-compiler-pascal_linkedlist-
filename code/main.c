
#include <stdio.h>
#include "analyse.h"
#include "syntax.h"



int main(int argc,char *argv[]) {
	
  
  opn_file("test");
  printList();
  printf("**************************FIN D'ANALYSE LEXICALE ***************************************\n ");
 PROGRAM();
 if(syntax==0){
 	printf("*************compilation succeed***************************** !!!\n");
 }
 else printf("**********************syntax error !!!************************************ ");

}
