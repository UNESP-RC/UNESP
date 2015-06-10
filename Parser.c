#include "AssBin.h"
#include <stdio.h>
#include "binary.h"

int controlLabel = -1;
typedef struct label{
	char binary[7];
    char title[10];
} label;
label gLabel[32];

void analise(char* instruction);
int getControlLabel(char*);

int main(){
   char ch;
   char instruction[100] = "";
   FILE *arq;
   arq = fopen("AssBin.txt", "r");

   if(arq == NULL){
     printf("Erro, nao foi possivel abrir o arquivo\n");
	 system("pause");
	 exit(0);
   }

   while( (ch=fgetc(arq))!= EOF )
   {
      int len = strlen(instruction);
      instruction[len] = ch;
      instruction[len+1] = '\0';

      if (ch == '\n'){
        analise(instruction);

        strcpy(instruction, "");
      }
   }
   analise(instruction);

   system("pause");
}

void analise(char* instruction){
	analiseInstruction(instruction);
	if(pos(instruction, ':', 1) > 0){
	  char label[10] = "";
	  substring(label, instruction, 0, pos(instruction, ':', 1));
      printf("%s\n", gLabel[getControlLabel(label)].binary); //Controle de label
    }
}

int getControlLabel(char* prLabel){
	int i=0;
	for(i=0; i <= controlLabel; i++)
		if(strcmpi(gLabel[i].title, prLabel) == 0)
		  return i;
	
	controlLabel++;
	char stCtrlLabel[7] = "";
	itoa(controlLabel, stCtrlLabel, 10);
	decimalToBinary(stCtrlLabel, stCtrlLabel, 6);
	 
	strcpy(gLabel[controlLabel].binary, stCtrlLabel);
	strcpy(gLabel[controlLabel].title, prLabel);
	
    return controlLabel;
}
