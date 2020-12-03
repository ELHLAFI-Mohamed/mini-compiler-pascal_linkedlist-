#include "analyse.h"
#include <stdio.h>
#include <stdlib.h>
#include "syntax.h"
#include <string.h>



void Symbole_Suiv(){

head=head->next ;

}



void Erreur(enum ERREURS erreur){
  printf("%s\n ",trans(&(head->data->token))); 
	switch(erreur){


case 0: printf("ERREUR----->PROGRAM\n");break;
case 1: printf("ERREUR----->CONST_ERREUR\n");break;
case 2: printf("ERREUR----->VAR_ERREUR\n");break;
case 3: printf("ERREUR----->BEGIN_ERREUR\n");break;
case 4: printf("ERREUR----->END_ERREUR\n");break;
case 5: printf("ERREUR----->IF_ERREUR\n");break;
case 6: printf("ERREUR----->THEN_ERREUR\n");break;
case 7: printf("ERREUR----->WHILE_ERREUR\n");break;
case 8: printf("ERREUR----->DO_ERREUR\n");break;
case 9: printf("ERREUR----->READ_ERREUR\n");break;
case 10: printf("ERREUR----->WRITE_ERREUR\n");break;
case 11: printf("ERREUR----->PV_ERREUR\n");break; 
case 12: printf("ERREUR----->PT_ERREUR\n");break;
case 13: printf("ERREUR----->PLUS_ERREUR\n");break;
case 14: printf("ERREUR----->MOINS_ERREUR\n");break;
case 15: printf("ERREUR----->MULT_ERREUR\n");break;
case 16: printf("ERREUR----->DIV_ERREUR\n");break;
case 17: printf("ERREUR----->VIR_ERREUR\n");break;
case 18: printf("ERREUR----->AFF_ERREUR\n,");break;
case 19: printf("ERREUR----->PO_ERREUR\n");break;
case 20: printf("ERREUR----->PF_ERREUR\n");break;
case 21: printf("ERREUR----->ID_ERREUR\n");break;
case 22: printf("ERREUR----->NUM_ERREUR\n");break;
case 23: printf("ERREUR----->CONST_VAR_BEGIN_ERR\n");break;
case 24: printf("ERREUR----->INST_ERR\n");break;
case 25: printf("ERREUR----->COND_ERR\n");break;
case 26: printf("ERREUR----->EG_ERREUR\n");break;


}
}


void Test_Symbole(enum TOKENS stoken,enum ERREURS erreur) {

	

  if((head->data->token==stoken)) {
    
  	
    Symbole_Suiv();
    
  }

  else {
  	
  	syntax=1;
    Erreur(erreur);
  }
}


void PROGRAM() {
  Test_Symbole(PROGRAM_TOKEN,PROGRAM_ERREUR);
  Test_Symbole(ID_TOKEN,ID_ERREUR);
  Test_Symbole(PV_TOKEN,PV_ERREUR);
  BLOCK();
  Test_Symbole(PT_TOKEN,PT_ERREUR);
}


void BLOCK() {
  CONSTS();
  VARS();
  INSTS();
}

void CONSTS() {
	
  switch (head->data->token) {

    case CONST_TOKEN : Symbole_Suiv();
   
                       Test_Symbole(ID_TOKEN,ID_ERREUR);
                       Test_Symbole(EG_TOKEN,EG_ERREUR);
                       Test_Symbole(NUM_TOKEN,NUM_ERREUR);
                       Test_Symbole(PV_TOKEN,PV_ERREUR);
                      
                       while( head->data->token== ID_TOKEN) {

                           
                         
                         Test_Symbole(ID_TOKEN,ID_ERREUR);
                         Test_Symbole(EG_TOKEN,EG_ERREUR);
                         Test_Symbole(NUM_TOKEN,NUM_ERREUR);
                         Test_Symbole(PV_TOKEN,PV_ERREUR);
                             
            
                        

                       } ; break ;
    case VAR_TOKEN : ;  break ;
    case BEGIN_TOKEN :  ;break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ;
  
     break ;
  }
}


 void VARS() {
  switch (head->data->token) {
    case VAR_TOKEN : Symbole_Suiv();

                     Test_Symbole(ID_TOKEN,ID_ERREUR);
                     
                     while(head->data->token== VIR_TOKEN) {
                     	
                        Symbole_Suiv();
                        Test_Symbole(ID_TOKEN,ID_ERREUR);
                     }
                     Test_Symbole(PV_TOKEN,PV_ERREUR);
                  ; break ;
    case BEGIN_TOKEN : break ;
    default          : Erreur(CONST_VAR_BEGIN_ERR) ;
     break ;
  }
}


void INSTS() {
	
  Test_Symbole(BEGIN_TOKEN,BEGIN_ERREUR);
  INST();
  
  while(head->data->token == PV_TOKEN ) {
    Symbole_Suiv();
    INST();
  }
  
  Test_Symbole(END_TOKEN,END_ERREUR);
}
void INST() {
	
  switch (head->data->token) {
    case BEGIN_TOKEN : INSTS() ; break ;
    case ID_TOKEN    : AFFEC() ; break ;
    case IF_TOKEN    : SI()    ; break ;
    case WHILE_TOKEN : TANTQUE();break ;
    case WRITE_TOKEN : ECRIRE(); break ;
    case READ_TOKEN  : LIRE()  ; break ;
    case END_TOKEN:    ;break;
    default          : Erreur(INST_ERR) ; break ;
}
}

void AFFEC() {
	
  Test_Symbole(ID_TOKEN,ID_ERREUR);
  Test_Symbole(AFF_TOKEN,AFF_ERREUR);
  
  EXPR();
  
}

void EXPR() {
	
  TERM();

  while(head->data->token== PLUS_TOKEN || head->data->token== MOINS_TOKEN) {
  
    Symbole_Suiv();
    TERM();
  }
}

void TERM() {
	
  FACT();
  
  while(head->data->token== MULT_TOKEN || head->data->token == DIV_TOKEN) {
    Symbole_Suiv();
    FACT();
  }
}
void FACT() {
	
  switch(head->data->token) {
  	
    case ID_TOKEN :Symbole_Suiv(); break ;
    case PO_TOKEN : EXPR(); Test_Symbole(PF_TOKEN,PF_ERREUR);
                           
     break ;
     default: ;break;
  }
}

void SI() {
	
  Test_Symbole(IF_TOKEN,IF_ERREUR);
  COND();
  Test_Symbole(THEN_TOKEN,THEN_ERREUR);
  INST();
}

void COND() {
	
  EXPR();
 
  
  switch(head->data->token) {
    case EG_TOKEN: Symbole_Suiv();EXPR();Symbole_Suiv();;break;
    case DIFF_TOKEN: Symbole_Suiv();EXPR();Symbole_Suiv();;break;
    case INF_TOKEN:EXPR();Symbole_Suiv()  ;break;
    case SUP_TOKEN: EXPR();Symbole_Suiv() ;break;
    case INFEG_TOKEN:Symbole_Suiv();EXPR();Symbole_Suiv();;break;
    case SUPEG_TOKEN:Symbole_Suiv();EXPR();Symbole_Suiv();;break;
    default: Erreur(COND_ERR) ; break ;
  }
  EXPR();
}

void TANTQUE() {
	
  Test_Symbole(WHILE_TOKEN,WHILE_ERREUR);
  COND();
  Test_Symbole(DO_TOKEN,DO_ERREUR);
  if(head->data->token==BEGIN_TOKEN){
    INSTS();
  }
  else INST();
  

}

 
 void ECRIRE() {
 	
  Test_Symbole(WRITE_TOKEN,WRITE_ERREUR);
  Test_Symbole(PO_TOKEN,PO_ERREUR);
  EXPR();
  
  while(head->data->token== VIR_TOKEN) {
    Symbole_Suiv();
    EXPR();
  }
  
  Test_Symbole(PF_TOKEN,PF_ERREUR);
  
}



void LIRE() {
	
  Test_Symbole(READ_TOKEN,READ_ERREUR);
  Test_Symbole(PO_TOKEN,PO_ERREUR);
  Test_Symbole(ID_TOKEN,ID_ERREUR);
  
  while(head->data->token== VIR_TOKEN) {
    Symbole_Suiv();
    Test_Symbole(ID_TOKEN,ID_ERREUR);
  }
  
  Test_Symbole(PF_TOKEN,PF_ERREUR);
  
}




