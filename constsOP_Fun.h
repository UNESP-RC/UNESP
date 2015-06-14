#include <string.h>

//Campo OP Code para Funções tipo R
char R_OP[] = "000000";
char MFC0_OP[] = "010110"; //Excessão para os tipo R

//Campo funct para Funções tipo R
char SLL_FUN[] = "000000";
char MFC0_FUN[] = "000000"; 
char SRL_FUN[] = "000010";
char JMP_FUN[] = "001000";
char MFHI_FUN[] = "001010";
char MFLO_FUN[] = "010010";
char MULT_FUN[] = "011000";
char MULTU_FUN[] = "011001";
char DIV_FUN[] = "011010";
char DIVU_FUN[] = "011011";
char ADD_FUN[] = "100000";
char ADDU_FUN[] = "100001";
char SUB_FUN[] = "100010";
char SUBU_FUN[] = "100011";
char AND_FUN[] = "100100";
char OR_FUN[] = "100101";
char NOR_FUN[] = "100111";
char SLT_FUN[] = "101010";
char SLTU_FUN[] = "101011";

//Campo OP Code para Funções tipo I
char BEQ_OP[] = "000100";
char BNE_OP[] = "000101";
char ADDI_OP[] = "001000";
char ADDIU_OP[] = "001001";
char SLTI_OP[] = "001010";
char SLTIU_OP[] = "001011";
char ANDI_OP[] = "001100";
char ORI_OP[] = "001101";
char LUI_OP[] = "001111";
char LW_OP[] = "100011";
char LBU_OP[] = "100100";
char LHU_OP[] = "100101";
char SB_OP[] = "101000";
char SH_OP[] = "101001";
char SW_OP[] = "101011";

//Campo OP Code para Funções tipo J
char J_OP[] = "000010";
char JAL_OP[] = "000011";

//Função para retornar o código binário de cada função
char* getFunction(char* OPCode){
  if(strcmpi(OPCode, "SLL") == 0){
     return SLL_FUN;               
  }
  else if(strcmpi(OPCode, "MFC0") == 0){
     return MFC0_FUN;               
  }
  else if(strcmpi(OPCode, "SRL") == 0){
     return SRL_FUN;               
  }
  else if(strcmpi(OPCode, "JMP") == 0){
     return JMP_FUN;         
  }
  else if(strcmpi(OPCode, "MFHI") == 0){
     return MFHI_FUN;        
  }
  else if(strcmpi(OPCode, "MFLO") == 0){
     return MFLO_FUN;        
  }
  else if(strcmpi(OPCode, "MULT") == 0){
     return MULT_FUN;         
  }
  else if(strcmpi(OPCode, "MULTU") == 0){
     return MULTU_FUN;               
  }
  else if(strcmpi(OPCode, "DIV") == 0){
     return DIV_FUN;               
  }
  else if(strcmpi(OPCode, "DIVU") == 0){
     return DIVU_FUN;               
  }
  else if(strcmpi(OPCode, "ADD") == 0){
     return ADD_FUN;               
  }
  else if(strcmpi(OPCode, "ADDU") == 0){
     return ADDU_FUN;               
  }
  else if(strcmpi(OPCode, "SUB") == 0){
     return SUB_FUN;               
  }
  else if(strcmpi(OPCode, "SUBU") == 0){
     return SUBU_FUN;               
  }
  else if(strcmpi(OPCode, "AND") == 0){
     return AND_FUN;               
  }
  else if(strcmpi(OPCode, "OR") == 0){
     return OR_FUN;               
  }
  else if(strcmpi(OPCode, "NOR") == 0){
     return NOR_FUN;               
  }
  else if(strcmpi(OPCode, "SLT") == 0){
     return SLT_FUN;               
  }
  else if(strcmpi(OPCode, "SLTU") == 0){
     return SLTU_FUN;               
  }
   
  return "FUN - ERRO!";  
}

//Função para retornar o código binário de cada OP Code
char* getOPCode(char* FUN){
  if(strcmpi(FUN, "MFC0") == 0){
     return MFC0_OP;               
  }
  else if(strcmpi(FUN, "BEQ") == 0){
     return BEQ_OP;
  }
  else if(strcmpi(FUN, "BNE") == 0){
     return BNE_OP;
  }
  else if(strcmpi(FUN, "ADDI") == 0){
     return ADDI_OP;
  }
  else if(strcmpi(FUN, "ADDIU") == 0){
     return ADDIU_OP;
  }
  else if(strcmpi(FUN, "SLTI") == 0){
     return SLTI_OP;
  }
  else if(strcmpi(FUN, "SLTIU") == 0){
     return SLTIU_OP;
  }
  else if(strcmpi(FUN, "ANDI") == 0){
     return ANDI_OP;
  }
  else if(strcmpi(FUN, "ORI") == 0){
     return ORI_OP;
  }
  else if(strcmpi(FUN, "LUI") == 0){
     return LUI_OP;
  }
  else if(strcmpi(FUN, "LW") == 0){
     return LW_OP;
  }
  else if(strcmpi(FUN, "LBU") == 0){
     return LBU_OP;
  }
  else if(strcmpi(FUN, "LHU") == 0){
     return LHU_OP;
  }
  else if(strcmpi(FUN, "SB") == 0){
     return SB_OP;
  }
  else if(strcmpi(FUN, "SH") == 0){
     return SH_OP;
  }
  else if(strcmpi(FUN, "SW") == 0){
     return SW_OP;
  }
  else if(strcmpi(FUN, "J") == 0){
     return J_OP;
  }
  else if(strcmpi(FUN, "JAL") == 0){
     return JAL_OP;
  }
  else
     return R_OP;
}
