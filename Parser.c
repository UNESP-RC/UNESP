#include "AssBin.h"
#include "BinAss.h"
#include <stdio.h>

void analise(char*);
int getControlLabel(char*, int);

int main(){
   char ch;
   char instruction[100] = "";
   char readFile[100] = "";
   char writeFile[100] = "";
   FILE *arq;
   
   int op = -1;
   printf("1- Converter Assembly para Binario\n");
   printf("2- Converter Binario para Assembly\n");
   scanf("%d", &op);
   
   if(op == 1){
   		strcpy(readFile, "AssBin.txt");
   		strcpy(writeFile, "BinAss.txt");
   }
   else if(op == 2){
   	    strcpy(readFile, "BinAss.txt");
   	    strcpy(writeFile, "AssBin.txt");
   }
   system("cls");   
   
   arq = fopen(readFile, "r");
   openFile(writeFile);

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
      	if(pos(instruction, '#', 1) > 0)
   	  		substring(instruction, instruction, 0, pos(instruction, '#', 1)); //Ignorar comentários
        
        if(op == 1)
			analiseInstruction(instruction);
		else if(op == 2)
			analiseBinary(instruction);

        strcpy(instruction, "");
      }
   }
   
   if(op == 1)
		analiseInstruction(instruction);
	else if(op == 2)
		analiseBinary(instruction);

   system("pause");
}
