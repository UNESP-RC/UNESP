#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include "useful.h"

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
    int decimal, total, potenc, negative = 0;
    decimal = atoi(number);
    
    if(decimal < 0)
		negative = 1;
    
    itoa(decimal, result, 2); 
    
    if (negative)
    	substring(result, result, strlen(result) - tam, strlen(result));
    else
    	stringComplete(tam, result, result);    
}

 // Função conversora: binário para decimal     
void binaryToDecimal(char* number, char* result)
{  
   int aux, i, decimal, aux2; 
   
   aux = strlen(number);
   i = 0;
   decimal = 0;

   while(aux!= 0)
   {  
       if (aux!= 1) 
       {         
          if(number[i] == '1')
            decimal += pow (2,aux-1); 
       }else{   
            if(number[i]== '1') 
               decimal = decimal+1;
            }        
               
        i++;
        aux--; 
   }
      
   itoa(decimal, result, 10);   
}

//Função binario ---> complemento de dois 
void doTwoComplement(char* number, char* result)
{    
    int cont, bin, carry;
    cont = strlen(number);
    carry = 0;
    while(cont >= 0)
    {
     	if(number[cont] == '1')
        {
        	result[cont] = '0';
        }
        else if(number[cont] == '0')
        {
        	result[cont] = '1';
        }

     	cont--;
    }

    cont = strlen(number) - 1;
    do
    {
     	if(result[cont] == '0')
        {
        	result[cont] = '1';
        	carry = 0;
        }else if(result[cont] == '1')
        {
        	result[cont] = '0';
            carry = 1;
            cont--;
        }

    }while(carry != 0);

 }
