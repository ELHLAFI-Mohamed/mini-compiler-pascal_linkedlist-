#include "analyse.h"
#include "syntax.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sementique.h"
int i=0;

int Y =0;
void table_id(){
	


	
 switch(head->data->token){
 	
 	case PROGRAM_TOKEN : Symbole_Suiv();store_prog();break;
 	case CONST_TOKEN : Symbole_Suiv();store_const();break;
 	case VAR_TOKEN : Symbole_Suiv();store_var();break ;
 	default : ; break;

                          }

                }

void store_prog(){

	while((head->data->token!=CONST_TOKEN)&&(head->data->token!=VAR_TOKEN)&&(head->data->token!=BEGIN_TOKEN)){
		if(head->data->token==ID_TOKEN){

			strcpy((TAB_IDFS+i)->NOM,head->data->nom);

			(TAB_IDFS+i)->TIDF=TPROG;
			i++;
			
		}
		Symbole_Suiv();

	}

	table_id();

}
void store_const(){

	while((head->data->token!=PROGRAM_TOKEN)&&(head->data->token!=VAR_TOKEN)&&(head->data->token!=BEGIN_TOKEN)){
		if(head->data->token==ID_TOKEN){
               
			strcpy((TAB_IDFS+i)->NOM,head->data->nom);

			(TAB_IDFS+i)->TIDF=TCONST;
			Symbole_Suiv();
			if(head->data->token==EG_TOKEN){
				Symbole_Suiv();
			(TAB_IDFS+i)->value=head->data->val;
		}
			i++;
		}
		Symbole_Suiv();

	}

	table_id();

}
void store_var(){

	while((head->data->token!=CONST_TOKEN)&&(head->data->token!=PROGRAM_TOKEN)&&(head->data->token!=BEGIN_TOKEN)){
		if(head->data->token==ID_TOKEN){
             regle2();
			strcpy((TAB_IDFS+i)->NOM,head->data->nom);

			(TAB_IDFS+i)->TIDF=TVAR;
			i++;
		}
		Symbole_Suiv();

	}

	table_id();

}

void affich(){
	
	regle1();
	regle3();
	regle4();
	regle5();
	if(Y==0){
		printf("************************************Compilation sementique succeed***********************************\n");
	}
	else printf("****************************************Compilation sementique erreur**************************************\n");
	
}
void regle1(){
	head=head_sem ;
	while(head->data->token!=BEGIN_TOKEN){
		if(head->data->token==ID_TOKEN){
			check();
		}
		Symbole_Suiv();
	}
}
void check(){
	int r=0; 
	for (int i = 0; i <NbrIDFS ; ++i)
	{
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0){
			r=1;
					}
	}
	if(r==0){
		printf("%s ---->Erreur declaration hors CONST and VAR  \n",head->data->nom);
		Y=1;
	}

}



void regle2(){
	int r=0;
	for (int i = 0; i <NbrIDFS ; ++i)
	{
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0){
			r=1;
					}
	}
	if(r==1){
		printf("%s------>erreur variable deja declarer\n ",head->data->nom);
		Y=1;
	}
}

void regle3(){
	head=head_sem ;
	while(head->data->token!=BEGIN_TOKEN) Symbole_Suiv();

	while(head->data->token!=PT_TOKEN){
		if(head->data->token==ID_TOKEN){

         
int r=0; 
	for (int i = 0; i <NbrIDFS ; ++i)
	{
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0){
			r=1;
					}
	}
	if(r==0){
		printf("%s ---->Erreur Variable non declarer  \n",head->data->nom);
		Y=1;
	}


		}
		Symbole_Suiv();

	}

}

void regle4(){

head=head_sem ;
	while(head->data->token!=BEGIN_TOKEN) Symbole_Suiv();
	while(head->data->token!=PT_TOKEN){

if(head->data->token==ID_TOKEN){
	for (int i = 0; i <NbrIDFS ; ++i)
	{
			if((TAB_IDFS+i)->TIDF==1){
				Symbole_Suiv();

				if(head->data->token==EG_TOKEN){
					Symbole_Suiv();

					if(head->data->val!=(TAB_IDFS+i)->value){
					
					printf("%s------>Erreur : Une constante ne peut changer de valeur dans le programme\n",head->data->nom);
					Y=1;
				}





				}
				


				
			}









					






	}



}
if(head->data->token==READ_TOKEN){
Symbole_Suiv();
Symbole_Suiv();
if(head->data->token==ID_TOKEN){
for (int i = 0; i <NbrIDFS ; ++i)
	{
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0){

			if((TAB_IDFS+i)->TIDF==1) {printf("%s ----------> constante	ne	peut changer	de	valeur a partire de READ\n",head->data->nom);
			Y=1;
				}	}
	}




}



}
Symbole_Suiv();


}
}

void regle5(){
	head=head_sem ;
	while(head->data->token!=BEGIN_TOKEN) Symbole_Suiv();
	while(head->data->token!=PT_TOKEN){
		if(head->data->token==ID_TOKEN){

for (int i = 0; i <NbrIDFS ; ++i)
	{
		if(strcmp(head->data->nom,(TAB_IDFS+i)->NOM)==0){


			if((TAB_IDFS+i)->TIDF==0) {printf("%s ----------> nom	de	programme	non	autorisé\n",head->data->nom);
			Y=1;}
					}
	}




}
Symbole_Suiv();


	}
}