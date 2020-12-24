#include "analyse.h"
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
#include "sementique.h"


NbrIDFS=0;





char * trans(enum TOKENS* token){

switch(*token){

case 0: return "PROGRAM_TOKEN";break;
case 1: return "CONST_TOKEN";break;
case 2: return "VAR_TOKEN";break;
case 3: return "BEGIN_TOKEN";break;
case 4: return "END_TOKEN";break;
case 5: return "IF_TOKEN";break;
case 6: return "THEN_TOKEN";break;
case 7: return "WHILE_TOKEN";break;
case 8: return "DO_TOKEN";break;
case 9: return "READ_TOKEN";break;
case 10: return "WRITE_TOKEN,";break;
case 11: return "PV_TOKEN";break;
case 12: return "PT_TOKEN";break;
case 13: return "PLUS_TOKEN";break;
case 14: return "MOINS_TOKEN";break;
case 15: return "PMULT_TOKEN";break;
case 16: return "DIV_TOKEN";break;
case 17: return "VIR_TOKEN";break;
case 18: return "AFF_TOKEN";break;
case 19: return "EG_TOKEN";break;
case 20: return "INF_TOKEN";break;
case 21: return "INFEG_TOKEN";break;
case 22: return "SUP_TOKEN";break;
case 23: return "SUPEG_TOKEN";break;
case 24: return "DIFF_TOKEN";break;
case 25: return "PO_TOKEN";break;
case 26: return "PF_TOKEN";break;
case 27: return "FIN_TOKEN";break;
case 28: return "ID_TOKEN";break;
case 29: return "NUM_TOKEN";break;
case 30: return "ERREUR_TOKEN";break;
case 31: return "NULL_TOKEN";break;

case 32: return "GUIMO_TOKEN";break;

case 33: return "GUIMF_TOKEN";break;
 default:
            return" err";
}
}
 


void  Stockage(){
	
	

struct store * new_elem =NULL;
new_elem=(struct store *)malloc(sizeof(struct store));



new_elem->data=TOK_A;
new_elem->next=NULL;

if(head==NULL){// if the linked list is empty 
	
TOK_A=(struct code*)malloc(sizeof(struct code));
head=new_elem; 

}
else{
	TOK_A=(struct code*)malloc(sizeof(struct code));

struct store    *last=head;
  
while(last->next!=NULL){


last=last->next;


}


 last->next=new_elem;
}



 return;


}










void analyse(){

	

	if((Car_Cour>='a'&& Car_Cour<='z' )|| (Car_Cour>='A'&& Car_Cour<='Z')){
		word=(char*)malloc(40);
		strncat(word,&Car_Cour,1);
	read_car();
while((Car_Cour>='a'&& Car_Cour<='z' )|| (Car_Cour>='A'&& Car_Cour<='Z') || (Car_Cour>='0' && Car_Cour<='9') ){
	strncat(word,&Car_Cour,1);
	read_car();

}

if(strcmp(word,"program")==0){

	TOK_A->token=PROGRAM_TOKEN;
	strcpy(TOK_A->nom,word);
	Stockage();


	//printf("%s -> PROGRAM_TOKEN\n",word);
}
 

else if(strcmp(word,"const")==0){

	TOK_A->token=CONST_TOKEN;
	strcpy(TOK_A->nom,word);
Stockage();


	//printf("%s -> CONST_TOKEN\n",word);
}
else if(strcmp(word,"var")==0){
     TOK_A->token=VAR_TOKEN;
     strcpy(TOK_A->nom,word);
	Stockage();

	//printf("%s -> VAR_TOKEN\n",word);
}
else if(strcmp(word,"Begin")==0){

	TOK_A->token=BEGIN_TOKEN;
	strcpy(TOK_A->nom,word);
	Stockage();
//	printf("%s -> BEGIN_TOKEN\n",word);

}
else if(strcmp(word,"end")==0){

	TOK_A->token=END_TOKEN;
	strcpy(TOK_A->nom,word);
	Stockage();


	//printf("%s -> END_TOKEN\n",word);
}
else if(strcmp(word,"if")==0){
		TOK_A->token=IF_TOKEN;
		strcpy(TOK_A->nom,word);
	Stockage();



	//printf("%s -> IF_TOKEN\n",word);
}
else if(strcmp(word,"then")==0){
   
     TOK_A->token=THEN_TOKEN;
     strcpy(TOK_A->nom,word);
	Stockage();


	//printf("%s -> THEN_TOKEN\n",word);
}
else if(strcmp(word,"while")==0){

	TOK_A->token=WHILE_TOKEN;
	strcpy(TOK_A->nom,word);
	Stockage();

	//printf("%s -> WHILE_TOKEN\n",word);
}
else if(strcmp(word,"do")==0){


	TOK_A->token=DO_TOKEN;
	strcpy(TOK_A->nom,word);
Stockage();
	//printf("%s -> DO_TOKEN\n",word);
}
else if(strcmp(word,"read")==0){

TOK_A->token=READ_TOKEN;
strcpy(TOK_A->nom,word);
Stockage();

	//printf("%s -> RED_TOKEN\n",word);
}
else if(strcmp(word,"write")==0){
       	TOK_A->token=WRITE_TOKEN;
       	strcpy(TOK_A->nom,word);
Stockage();


	//printf("%s -> WRITE_TOKEN\n",word);
}
else 
{
	TOK_A->token=ID_TOKEN;
	strcpy(TOK_A->nom,word);
	
	Stockage();
//printf("%s -> ID_TOKEN\n",word);

}


		free(word);
	

}


 if(Car_Cour==123){
 

read_car();
if(Car_Cour==42){
	
	int r=0 ;

while(r==0 && Car_Cour!=EOF){
	
	read_car();
	
	
	
	if(Car_Cour==42){
		
		read_car();
		if (Car_Cour==125)
		{
			r= 1;

		}

	}

}
if(r==1) {
         
        
         




	//printf(" {* *} ->COMMENT_TOKEN\n");
	 read_car();}

else {



TOK_A->token=ERREUR_TOKEN;
Stockage();




	//printf("ERROR_TOKEN\n");


}

}
else {

	TOK_A->token=GUIMO_TOKEN;
Stockage();







	//printf("%c ->GUIMO_TOKEN\n",Car_Cour );}
}
}
 
 if (Car_Cour==125)

 {
    

         TOK_A->token=GUIMF_TOKEN;
Stockage();






 	//printf("%c ->GUIMF_TOKEN\n",Car_Cour);
 }


   if((Car_Cour>='0' && Car_Cour<='9')){
   	int i=0;
  TOK_A->nom[i]=Car_Cour;
  i=1;
	read_car();
	while((Car_Cour>='0' && Car_Cour<='9')){
		
		TOK_A->nom[i]=Car_Cour;
		
		i++;
		read_car();
	}
	TOK_A->nom[i]='\0';
	if((Car_Cour>='a' && Car_Cour<='z') && (Car_Cour>='A' ||Car_Cour<='Z') ){
		

		
TOK_A->token=ERREUR_TOKEN;
		Stockage();




		//printf("%s -> ERREUR_TOKEN\n",number);
		
	}
	else {


		TOK_A->val=atoi(TOK_A->nom);
	TOK_A->token=NUM_TOKEN;
       Stockage();
     






		//printf("%s -> NUM_TOKEN\n",number);
	}
	

}
 if(Car_Cour==61){


	TOK_A->token=EG_TOKEN;
	strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();



	//printf("%c -> EGALE_TOKEN\n",Car_Cour);
}
if(Car_Cour==59){



	TOK_A->token=PV_TOKEN;
	strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();



	//printf("%c -> PV_TOKEN\n",Car_Cour);
}

if(Car_Cour==46){


		TOK_A->token=PT_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();

	//printf("%c -> PT_TOKEN\n",Car_Cour);

}
 if(Car_Cour==43){


	TOK_A->token=PLUS_TOKEN;
	strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();






	//printf("%c -> PLUS_TOKEN\n",Car_Cour);
}
if(Car_Cour==45){
	

		TOK_A->token=MOINS_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	
	//printf("%c -> MOINS_TOKEN\n",Car_Cour);
}
 if(Car_Cour==42){




		TOK_A->token=MULT_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	

	//printf("%c -> MULT_TOKEN\n",Car_Cour);
}
 if(Car_Cour==47){

 	

		TOK_A->token=DIV_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();

	//printf("%c -> DIV_TOKEN\n",Car_Cour);
}
 if(Car_Cour==44){

 	

		TOK_A->token=VIR_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	
	//printf("%c -> VIR_TOKEN\n",Car_Cour);

}

 if(Car_Cour==58){
	
	read_car();
	if(Car_Cour==61){
		Car_Cour=':=';

		TOK_A->token=AFF_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	
	//printf(":= -> AFF_TOKEN\n");
}
else
{
	

		TOK_A->token=ERREUR_TOKEN;
	Stockage();
	




     //printf("%c -> ERREUR_TOKEN\n",c);
}

}


 if(Car_Cour==60){

	read_car();
	if(Car_Cour==61){
     Car_Cour='<=';

		TOK_A->token=INFEG_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	



	//printf("<= -> INFEG_TOKEN\n");
}
else if(Car_Cour==62){
	
Car_Cour='<>';
		TOK_A->token=DIFF_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	

	//printf("<> -> DIFF_TOKEN\n");
}

else{
	

		TOK_A->token=INF_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	



	//printf("%c -> INF_TOKEN\n",c); 

	  }

}


 if(Car_Cour==62){
	
	read_car();
	if(Car_Cour==61){
		
Car_Cour='>=';
	TOK_A->token=SUPEG_TOKEN;
	strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	
	//printf(">= -> SUPEG_TOKEN\n");
}

else{ 
	

		TOK_A->token=SUP_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();




	//printf("%c -> SUP_TOKEN\n",c);  
	    }

}

if(Car_Cour==40){

	

		TOK_A->token=PO_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();


	//printf("%c -> PO_TOKEN\n",Car_Cour);

}
if(Car_Cour==41){

	

		TOK_A->token=PF_TOKEN;
		strncat(TOK_A->nom,&Car_Cour,1);
	Stockage();
	

	//printf("%c -> PF_TOKEN\n",Car_Cour);

}

 




}




void read_car(){

Car_Cour=fgetc(file);

}

void opn_file(char *filename){
	
 
	file=fopen(filename,"a+");
	read_car();
	while(Car_Cour!=EOF){
		TOK_A=(struct code*)malloc(sizeof(struct code));
		analyse();
		
		read_car();
		//printf("%s\n ",trans(&(head->data->token)));
		
		free(TOK_A);

		
	}

	 
//printf("%s\n ",trans(&(head->data->token)));
	

	
}

void printList() 

{ 
	struct store * printlis=head;


  while (printlis != NULL) 
  { 


    printf("%s ---->%s\n ",printlis->data->nom,trans(&(printlis->data->token))); 
    
     printlis = printlis->next; 
  } 
  head_sem =head;
}

