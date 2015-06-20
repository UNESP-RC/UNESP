#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 

//Função que completa o numero binario com 0 a esquerda 
void stringComplete(int tam, char* string, char* result)
{
	int cont=0;
    cont = tam - (strlen(string) - 1);

    char aux[cont];
    strcpy(aux, "");
    
    while(cont > 1) // iniciando a string2 com 0 
    {
        strcat(aux, "0");
        cont--;                  
    }
    
    strcat(aux, string); 
    strcpy(result, aux);
}

// Função conversora: decimal para binário 
void decimalToBinary(char* number, char* result, int tam)
{  
    int decimal, total, potenc;
    decimal = atoi(number);
    
    itoa(decimal, result, 2); 
    
    if (strlen(result) > tam)
    	substring(result, result, strlen(result) - tam, tam);
    else
    	stringComplete(tam, result, result);    
}

void undoTwoComplement(char* number){
    if(number[0] == '1'){
         int i=0, j=0;
        
         int firstOne=0;
         int firstZero=0;
        
         for(i=0; i < strlen(number); i++){
             if(number[i] == '0')
               number[i] = '1';
             else if(number[i] == '1')
               number[i] = '0';
         }
        
         for(i=0; i < strlen(number) && !firstOne; i++){
             if(number[i] == '1'){
                 firstOne = 1;
            
                 for(j=i; j < strlen(number) && !firstZero; j++){
                     if(number[i] == '0'){
                         firstZero = 1;
                    
                         number[i] = '1';
                         number[i-1] = '0';
                     }           
                 }
             }
         }
    }
}

 // Função conversora: binário para decimal     
void binaryToDecimal(char* number, char* result)
{  
   int aux, i, decimal, aux2, negative=0; 
   
   if(number[0] == '1') negative = 1;
   
   undoTwoComplement(number);
   aux = strlen(number);
   i = 0;
   decimal = 0;

   while(aux!= 0)
   {  
       if (aux!= 1) 
       {         
          if(number[i] == '1')
            decimal += pow(2, aux - 1); 
       }else{   
            if(number[i]== '1') 
               decimal = decimal + 1;
        }        
               
        i++;
        aux--; 
   }
   
   if(negative)
     decimal = (decimal+1) * -1;
      
   itoa(decimal, result, 10);   
}
