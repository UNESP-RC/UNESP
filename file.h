#include<stdio.h>

//File é o nome do arquivo que deseja abrir, occurrence é onde deseja parar de ler o arquivo.(EOF significa o final do arquivo)
void readFromFile(char file[], char* occurrence){
    char ch;
    FILE *arq;
	arq = fopen(file, "r");
	if(arq == NULL)
	    printf("Erro, nao foi possivel abrir o arquivo\n");
	else
	    while( (ch=fgetc(arq))!= occurrence )
		putchar(ch);
}


