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
