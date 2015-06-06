#include "constsOP_Fun.h"
#include "constsReg.h"

void ADD(char* instruction){
  printf("\n*ADD*\n");
  
  int minLen = 0;
  int maxLen = 0;  
  char binary[33] = "";
  char result[10] = "";
  
  strcat(binary, getOPCode("ADD"));
  
  //Register rs
  minLen = pos(instruction, '$', 2);
  maxLen = pos(instruction, ',', 2) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  strcat(binary, getRegister(result));
  
  //Register rt
  minLen = pos(instruction, '$', 3);
  maxLen = pos(instruction, ',', 3) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  strcat(binary, getRegister(result));
  
  //Register rd
  minLen = pos(instruction, '$', 1);
  maxLen = pos(instruction, ',', 1) - minLen;
  substring(result, instruction, minLen, maxLen);
  strcpy(result, trim(result));
  strcat(binary, getRegister(result));
  
  strcat(binary, "00000"); //Shamt
  strcat(binary, getFunction("ADD"));
  
  printf("Binario: %s\n", binary);
}

void analiseInstruction(char* instruction)
{
   int minLen = 0;
   int maxLen = 0;

   char binary[32] = "";
   char fun[6] = "";

   char result[10] = "";  
   minLen = 0;
   maxLen = pos(instruction, ' ', 1);
   substring(result, instruction, minLen, maxLen); //Get function from instruction
   strcpy(result, trim(result));
   printf("Function: [%s]\n", result);
   
   if(strcmpi(result, "ADD") == 0)
     ADD(instruction);
   else if(strcmpi(result, "ADDU") == 0)
     printf("\n*ADDU*\n"); // ADDU(instruction);   
   if(strcmpi(result, "SUB") == 0)
     printf("\n*SUB*\n"); // SUB(instruction);
   else if(strcmpi(result, "SUBU") == 0)
     printf("\n*SUBU*\n"); // SUBU(instruction);
   if(strcmpi(result, "ADDI") == 0)
     printf("\n*ADDI*\n"); // ADDI(instruction);
   else if(strcmpi(result, "ADDIU") == 0)
     printf("\n*ADDIU*\n"); // ADDIU(instruction);
   if(strcmpi(result, "MULT") == 0)
     printf("\n*MULT*\n"); // MULT(instruction);
   else if(strcmpi(result, "MULTU") == 0)
     printf("\n*MULTU*\n"); // MULTU(instruction);
   if(strcmpi(result, "DIV") == 0)
     printf("\n*DIV*\n"); // DIV(instruction);
   else if(strcmpi(result, "DIVU") == 0)
     printf("\n*DIVU*\n"); // DIVU(instruction);
   if(strcmpi(result, "LW") == 0)
     printf("\n*LW*\n"); // LW(instruction);
   else if(strcmpi(result, "LH") == 0)
     printf("\n*LH*\n"); // LH(instruction);   
   if(strcmpi(result, "LHU") == 0)
     printf("\n*LHU*\n"); // LHU(instruction);
   else if(strcmpi(result, "LB") == 0)
     printf("\n*LB*\n"); // LB(instruction);
   if(strcmpi(result, "LBU") == 0)
     printf("\n*LBU*\n"); // LBU(instruction);
   else if(strcmpi(result, "SW") == 0)
     printf("\n*SW*\n"); // SW(instruction);
   if(strcmpi(result, "SH") == 0)
     printf("\n*SH*\n"); // SH(instruction);
   else if(strcmpi(result, "SB") == 0)
     printf("\n*SB*\n"); // SB(instruction);
   if(strcmpi(result, "LUI") == 0)
     printf("\n*LUI*\n"); // LUI(instruction);
   else if(strcmpi(result, "MFHI") == 0)
     printf("\n*MFHI*\n"); // MFHI(instruction);
   if(strcmpi(result, "MFLO") == 0)
     printf("\n*MFLO*\n"); // MFLO(instruction);
   else if(strcmpi(result, "AND") == 0)
     printf("\n*AND*\n"); // AND(instruction);   
   if(strcmpi(result, "ANDI") == 0)
     printf("\n*ANDI*\n"); // ANDI(instruction);
   else if(strcmpi(result, "OR") == 0)
     printf("\n*OR*\n"); // OR(instruction);
   if(strcmpi(result, "ORI") == 0)
     printf("\n*ORI*\n"); // ORI(instruction);
   else if(strcmpi(result, "XOR") == 0)
     printf("\n*XOR*\n"); // XOR(instruction);
   if(strcmpi(result, "NOR") == 0)
     printf("\n*NOR*\n"); // NOR(instruction);
   else if(strcmpi(result, "SLT") == 0)
     printf("\n*SLT*\n"); // SLT(instruction);
   if(strcmpi(result, "SLTI") == 0)
     printf("\n*SLTI*\n"); // SLTI(instruction);
   else if(strcmpi(result, "SLL") == 0)
     printf("\n*SLL*\n"); // SLL(instruction);
   if(strcmpi(result, "SRL") == 0)
     printf("\n*SRL*\n"); // SRL(instruction);
   else if(strcmpi(result, "SRA") == 0)
     printf("\n*SRA*\n"); // SRA(instruction);   
   if(strcmpi(result, "SLLV") == 0)
     printf("\n*SLLV*\n"); // SLLV(instruction);
   else if(strcmpi(result, "SRLV") == 0)
     printf("\n*SRLV*\n"); // SRLV(instruction);
   if(strcmpi(result, "SRAV") == 0)
     printf("\n*SRAV*\n"); // SRAV(instruction);
   else if(strcmpi(result, "BEQ") == 0)
     printf("\n*BEQ*\n"); // BEQ(instruction);
   if(strcmpi(result, "BNE") == 0)
     printf("\n*BNE*\n"); // BNE(instruction);
   else if(strcmpi(result, "J") == 0)
     printf("\n*J*\n"); // J(instruction);
   if(strcmpi(result, "JR") == 0)
     printf("\n*JR*\n"); // JR(instruction);
   else if(strcmpi(result, "JAL") == 0)
     printf("\n*JAL*\n"); // JAL(instruction);
}
