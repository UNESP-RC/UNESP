#include "constsOP_Fun.h"
#include "constsReg.h"
#include "useful.h"
#include "binary.h"
#include "file.h"
#include <stdio.h>

int controlLabel = -1;
typedef struct label{
	char binary[7];
    char title[10];
} label;
label gLabel[32];

void getRegisterByType(char* result, char* instruction, int posReg){
  //Find register
  int minLen = pos(instruction, '$', posReg);
  int maxLen = posReg == 3 ? strlen(instruction) : pos(instruction, ',', posReg) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
}

int getControlLabel(char* prLabel, int isDefinition){
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

void ADD(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("ADD"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("ADD"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void ADDI(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = ""; //Tamanho precisa ser grande neste caso, pois quando passamos para a função decimalToBinary
                         //a função "itoa" lá dentro faz o complemento de dois, estourando o tamanho de uma string "pequena"

  strcat(binary, getOPCode("ADDI"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Find number
  minLen = pos(instruction, ',', 2) + 1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void ADDIU(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = ""; //Tamanho precisa ser grande neste caso, pois quando passamos para a função decimalToBinary
                         //a função "itoa" lá dentro faz o complemento de dois, estourando o tamanho de uma string "pequena"

  strcat(binary, getOPCode("ADDIU"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Find number
  minLen = pos(instruction, ',', 2) + 1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void SUB(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("SUB"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("SUB"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void ADDU(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("ADDU"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("ADDU"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void SUBU(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("SUBU"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("SUBU"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void SLT(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("SLT"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("SLT"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void SLTI(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = ""; //Tamanho precisa ser grande neste caso, pois quando passamos para a função decimalToBinary
                         //a função "itoa" lá dentro faz o complemento de dois, estourando o tamanho de uma string "pequena"

  strcat(binary, getOPCode("SLTI"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Find number
  minLen = pos(instruction, ',', 2) + 1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void BEQ(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[20] = "";

  strcat(binary, getOPCode("BEQ"));

  //Register rs
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Get label
  minLen = pos(instruction, ',', 2)+1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));

  stringComplete(16, gLabel[getControlLabel(result, 0)].binary, result);

  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void BNE(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[20] = "";

  strcat(binary, getOPCode("BNE"));

  //Register rs
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Get label
  minLen = pos(instruction, ',', 2)+1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));

  stringComplete(16, gLabel[getControlLabel(result, 0)].binary, result);

  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void AND(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("AND"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("AND"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void ANDI(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = ""; //Tamanho precisa ser grande neste caso, pois quando passamos para a função decimalToBinary
                         //a função "itoa" lá dentro faz o complemento de dois, estourando o tamanho de uma string "pequena"

  strcat(binary, getOPCode("ANDI"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Find number
  minLen = pos(instruction, ',', 2) + 1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void OR(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("OR"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  //Register rd
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("OR"));

  printf("%s\n", binary);
  writeToFile(binary);
}

void ORI(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = ""; //Tamanho precisa ser grande neste caso, pois quando passamos para a função decimalToBinary
                         //a função "itoa" lá dentro faz o complemento de dois, estourando o tamanho de uma string "pequena"

  strcat(binary, getOPCode("ORI"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Find number
  minLen = pos(instruction, ',', 2) + 1;
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, result);

  printf("%s\n", binary);
  writeToFile(binary);
}

void J(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[27] = "";

  strcat(binary, getOPCode("J"));

  minLen = pos(instruction, ' ', 1);
  maxLen = strlen(instruction) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));

  stringComplete(26, gLabel[getControlLabel(result, 0)].binary, result);

  strcat(binary, result);
  printf("%s\n", binary);
  writeToFile(binary);
}

void LW(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = "";

  strcat(binary, getOPCode("LW"));

  //Register rs
  minLen = pos(instruction, '(', 1) + 1;
  maxLen = pos(instruction, ')', 1) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Constant
  minLen = pos(instruction, ',', 1) + 1;
  maxLen = pos(instruction, '(', 1) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, getRegister(result));

  printf("%s\n", binary);
  writeToFile(binary);
}

void SW(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[255] = "";

  strcat(binary, getOPCode("SW"));

  //Register rs
  minLen = pos(instruction, '(', 1) + 1;
  maxLen = pos(instruction, ')', 1) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 1);
  strcat(binary, getRegister(result));

  //Constant
  minLen = pos(instruction, ',', 1) + 1;
  maxLen = pos(instruction, '(', 1) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  decimalToBinary(result, result, 16);
  strcat(binary, getRegister(result));

  printf("%s\n", binary);
  writeToFile(binary);
}

void MULT(char* instruction){
  int minLen = 0;
  int maxLen = 0;
  char binary[33] = "";
  char result[10] = "";

  strcat(binary, getOPCode("MULT"));

  //Register rs
  getRegisterByType(result, instruction, 2);
  strcat(binary, getRegister(result));

  //Register rt
  getRegisterByType(result, instruction, 3);
  strcat(binary, getRegister(result));

  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("MULT"));

  printf("%s\n", binary);
  writeToFile(binary);
}



void analiseInstruction(char* instruction){
   int minLen = 0;
   int maxLen = 0;

   strcpy(instruction, trim(instruction));

   char result[10] = "";
   minLen = 0;
   maxLen = pos(instruction, ' ', 1);
   substring(result, instruction, minLen, maxLen); //Get function from instruction
   strcpy(result, trim(result));

   if(strcmpi(result, "ADD") == 0)
     ADD(instruction);
   else if(strcmpi(result, "ADDU") == 0)
     ADDU(instruction);
   else if(strcmpi(result, "SUB") == 0)
     SUB(instruction);
   else if(strcmpi(result, "SUBU") == 0)
     SUBU(instruction);
   else if(strcmpi(result, "ADDI") == 0)
     ADDI(instruction);
   else if(strcmpi(result, "ADDIU") == 0)
     ADDIU(instruction);
   else if(strcmpi(result, "MULT") == 0)
     MULT(instruction);
   else if(strcmpi(result, "MULTU") == 0)
     printf("\n*MULTU*\n"); // MULTU(instruction);
   else if(strcmpi(result, "DIV") == 0)
     printf("\n*DIV*\n"); // DIV(instruction);
   else if(strcmpi(result, "DIVU") == 0)
     printf("\n*DIVU*\n"); // DIVU(instruction);
   else if(strcmpi(result, "LW") == 0)
     LW(instruction);
   else if(strcmpi(result, "LH") == 0)
     printf("\n*LH*\n"); // LH(instruction);
   else if(strcmpi(result, "LHU") == 0)
     printf("\n*LHU*\n"); // LHU(instruction);
   else if(strcmpi(result, "LB") == 0)
     printf("\n*LB*\n"); // LB(instruction);
   else if(strcmpi(result, "LBU") == 0)
     printf("\n*LBU*\n"); // LBU(instruction);
   else if(strcmpi(result, "SW") == 0)
     SW(instruction);
   else if(strcmpi(result, "SH") == 0)
     printf("\n*SH*\n"); // SH(instruction);
   else if(strcmpi(result, "SB") == 0)
     printf("\n*SB*\n"); // SB(instruction);
   else if(strcmpi(result, "LUI") == 0)
     printf("\n*LUI*\n"); // LUI(instruction);
   else if(strcmpi(result, "MFHI") == 0)
     printf("\n*MFHI*\n"); // MFHI(instruction);
   else if(strcmpi(result, "MFLO") == 0)
     printf("\n*MFLO*\n"); // MFLO(instruction);
   else if(strcmpi(result, "AND") == 0)
     AND(instruction);
   else if(strcmpi(result, "ANDI") == 0)
     ANDI(instruction);
   else if(strcmpi(result, "OR") == 0)
     OR(instruction);
   if(strcmpi(result, "ORI") == 0)
     ORI(instruction);
   else if(strcmpi(result, "XOR") == 0)
     printf("\n*XOR*\n"); // XOR(instruction);
   if(strcmpi(result, "NOR") == 0)
     printf("\n*NOR*\n"); // NOR(instruction);
   else if(strcmpi(result, "SLT") == 0)
     SLT(instruction);
   else if(strcmpi(result, "SLTI") == 0)
     SLTI(instruction);
   else if(strcmpi(result, "SLL") == 0)
     printf("\n*SLL*\n"); // SLL(instruction);
   else if(strcmpi(result, "SRL") == 0)
     printf("\n*SRL*\n"); // SRL(instruction);
   else if(strcmpi(result, "SRA") == 0)
     printf("\n*SRA*\n"); // SRA(instruction);
   else if(strcmpi(result, "SLLV") == 0)
     printf("\n*SLLV*\n"); // SLLV(instruction);
   else if(strcmpi(result, "SRLV") == 0)
     printf("\n*SRLV*\n"); // SRLV(instruction);
   else if(strcmpi(result, "SRAV") == 0)
     printf("\n*SRAV*\n"); // SRAV(instruction);
   else if(strcmpi(result, "BEQ") == 0)
     BEQ(instruction);
   else if(strcmpi(result, "BNE") == 0)
     BNE(instruction);
   else if(strcmpi(result, "J") == 0)
     J(instruction);
   else if(strcmpi(result, "JR") == 0)
     printf("\n*JR*\n"); // JR(instruction);
   else if(strcmpi(result, "JAL") == 0)
     printf("\n*JAL*\n"); // JAL(instruction);
   else if(pos(instruction, ':', 1) > 0){
	  char label[10] = "";
	  substring(label, instruction, 0, pos(instruction, ':', 1));
      printf("%s\n", gLabel[getControlLabel(label, 1)].binary); //Controle de label
      writeToFile(gLabel[getControlLabel(label, 1)].binary);
   }
}
