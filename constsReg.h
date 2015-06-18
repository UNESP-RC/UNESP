#include <string.h>

//Registrador ZERO (Valor constante zero)
char $SZERO[] = "00000";

//Temporário do montador 
char $at[] = "00001";

//Valores de retorno de funções
char $v0[] = "00010"; 
char $v1[] = "00011"; 

//Argumentos de funções
char $a0[] = "00100";
char $a1[] = "00101";
char $a2[] = "00110";
char $a3[] = "00111";
char $a4[] = "01000";
char $a5[] = "01001";
char $a6[] = "01010";
char $a7[] = "01011";

//Registradores temporários
char $t0[] = "01000";
char $t1[] = "01001";
char $t2[] = "01010";
char $t3[] = "01011";
char $t4[] = "01100";
char $t5[] = "01101";
char $t6[] = "01110";
char $t7[] = "01111";

//Temporários salvos
char $s0[] = "10000";
char $s1[] = "10001";
char $s2[] = "10010";
char $s3[] = "10011";
char $s4[] = "10100";
char $s5[] = "10101";
char $s6[] = "10110";
char $s7[] = "10111";

//Registradores temporários
char $t8[] = "11000";
char $t9[] = "11001";

//Reservado kernel OS
char $k0[] = "11010";
char $k1[] = "11011";

//Ponteiro global
char $gp[] = "11100";

//Stack pointer
char $sp[] = "11101";

//Frame pointer
char $s8[] = "11110";

//Endereço retorno
char $ra[] = "11111";

//Função para retornar o endereço binário de cada registrador
char* getRegister(char* reg){
  if(strcmpi(reg, "$SZERO") == 0){
     return $SZERO;
  }
  else if(strcmpi(reg, "$at") == 0){
     return $at;
  }
  else if(strcmpi(reg, "$v0") == 0){
     return $v0;
  }
  else if(strcmpi(reg, "$v1") == 0){
     return $v1;               
  }
  else if(strcmpi(reg, "$a0") == 0){
     return $a0;               
  }
  else if(strcmpi(reg, "$a1") == 0){
     return $a1;               
  }
  else if(strcmpi(reg, "$a2") == 0){
     return $a2;
  }
  else if(strcmpi(reg, "$a3") == 0){
     return $a3;
  }
  else if(strcmpi(reg, "$a4") == 0){
     return $a4;
  }
  else if(strcmpi(reg, "$a5") == 0){
     return $a5;
  }
  else if(strcmpi(reg, "$a6") == 0){
     return $a6;
  }
  else if(strcmpi(reg, "$a7") == 0){
     return $a7;
  }
  else if(strcmpi(reg, "$t4") == 0){
     return $t4;
  }
  else if(strcmpi(reg, "$t5") == 0){
     return $t5;
  }
  else if(strcmpi(reg, "$t6") == 0){
     return $t6;
  }
  else if(strcmpi(reg, "$t7") == 0){
     return $t7;
  }
  else if(strcmpi(reg, "$s0") == 0){
     return $s0;
  }
  else if(strcmpi(reg, "$s1") == 0){
     return $s1;
  }
  else if(strcmpi(reg, "$s2") == 0){
     return $s2;
  }
  else if(strcmpi(reg, "$s3") == 0){
     return $s3;
  }
  else if(strcmpi(reg, "$s4") == 0){
     return $s4;
  }
  else if(strcmpi(reg, "$s5") == 0){
     return $s5;
  }
  else if(strcmpi(reg, "$s6") == 0){
     return $s6;
  }
  else if(strcmpi(reg, "$s7") == 0){
     return $s7;
  }
  else if(strcmpi(reg, "$t8") == 0){
     return $t8;
  }
  else if(strcmpi(reg, "$t9") == 0){
     return $t9;
  }
  else if(strcmpi(reg, "$k0") == 0){
     return $k0;
  }
  else if(strcmpi(reg, "$k1") == 0){
     return $k1;
  }
  else if(strcmpi(reg, "$gp") == 0){
     return $gp;
  }
  else if(strcmpi(reg, "$sp") == 0){
     return $sp;
  }
  else if(strcmpi(reg, "$s8") == 0){
     return $s8;
  }
  else if(strcmpi(reg, "$ra") == 0){
     return $ra;
  }
  
  return reg;
}
