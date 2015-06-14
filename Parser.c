#include "AssBin.h"
#include <stdio.h>
#include "binary.h"

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
   {int len = strlen(instruction);
      instruction[len] = ch;
      instruction[len+1] = '\0';

      if (ch == '\n'){
      	if(pos(instruction, '#', 1) > 0)
   	  		substring(instruction, instruction, 0, pos(instruction, '#', 1));
        
		analiseInstruction(instruction);

        strcpy(instruction, "");
      }
   }
   analiseInstruction(instruction);

   system("pause");
}
