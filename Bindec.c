#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <math.h>

char n[] = "111111111";


// Essa função ela tranforma um núbero binário normal em decimal sem verificação de sinal

int BinDec (char number [])
{  int aux,i,dec,aux2; 
   aux = strlen(number);
   i = 0 ;
   dec = 0;

   while(aux!= 0)
      {  
       if (aux!= 1) 
       {         
          if(number[i] == '1')
            dec = dec + pow (2,aux-1); 
       }else{   
            if(number[i]== '1') 
               dec = dec+1;
            }        
               
         i++;
         aux--; 
      }
  return dec;       
}

// Essa função ela tranforma um núbero binário normal em decimal em complemento de dois 
 
void BinDec2 (char bin [])
{  int aux,i,dec,aux2; 
   aux = strlen(bin);
   i = 0 ;
   dec = 0;
   if(bin[0] == '0') // Analisa o bit mais siginificativo 
   {   
       while(aux!= 0)
         {  
           if (aux!= 1) 
           {         
             if(bin[i] == '1')
               dec = dec + pow (2,aux-2); 
           }else{   
               if(bin[i]== '1') 
                 dec = dec+1;
                 
           }        
                               
         i++;
         aux--; 
           }
          
   }
   
   if (bin[0] == '1') // Analisa o bit mais siginificativo 
    {  dec = -1 ;
       while(aux!= 0)
         {  
           if (aux!= 1) 
           {         
             if(bin[i] == '0')
               dec = dec - (pow (2,aux-2)); 
           }else{   
               if(bin[i]== '0') 
                 dec = dec - 1;
           }        
               
         i++;
         aux--; 
           }
                              
      }
     printf("%d" , dec) ;      
      
}
  
int main (void)
{
    BinDec2(n);
    
        
    system("pause");
    return 0;
        }
