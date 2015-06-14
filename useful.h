#include<stdlib.h>
#include<ctype.h>

//Função para retornar posição de caracter na string
int pos(char* string, char search, int occurrence){
   if (occurrence < 1)
     return -1;
     
   int _occurrence = 0;  
     
   int i=0;
   for(i=0; i<strlen(string); i++)
   {
     if(string[i] == search){
       _occurrence++;
       
       if(occurrence == _occurrence)
         return i;
     }
   }
   
   return -1;
}

//Função para encontrar parte da string
void substring(char* result, char* string, int start, int length){
   int i;
   
   int max = length+start;
   if (max > strlen(string))
     max = strlen(string);
   
   for(i=start; i<max; i++)
      result[i-start] = string[i];
   
   result[max-start] = '\0';
}

//Função para retirar caracteres em branco na string
char* trim (char *s)
{
    int i;

    while (isspace (*s)) s++;   // skip left side white spaces
    for (i = strlen(s)-1; (isspace(s[i]) && i>0); i--) ;   // skip right side white spaces
    s[i+1] = '\0';
    
    return s;
}

