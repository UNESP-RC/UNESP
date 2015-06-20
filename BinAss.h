#ifndef _BinAss_
#define _BinAss_

#include "constsOP_Fun.h"
#include "constsReg.h"
#include "useful.h"
#include "file.h"

void ADD_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "ADD ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SUB_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SUB ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void ADDU_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "ADDU ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void AND_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "AND ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void NOR_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "NOR ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void OR_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "OR ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}


void analiseBinary(char* binary){
	char opCode[7] = "";
	char funct[10] = "";

	strcpy(binary, trim(binary));

	substring(opCode, binary, 0, 6);
	substring(funct, binary, 20, 6);

	//Binários tipo R
    if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADD_FUN) == 0) )
    	ADD_B(binary);
	else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADDU_FUN) == 0) )
    	ADDU_B(instruction);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SUB_FUN) == 0) )
    	SUB_B(instruction);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SUBU_FUN) == 0) )
    	printf("SUBU\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MULT_FUN) == 0) )
    	printf("MULT\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MULTU_FUN) == 0) )
    	printf("MULTU\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, DIV_FUN) == 0) )
    	printf("DIV\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, DIVU_FUN) == 0) )
    	printf("DIVU\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFHI_FUN) == 0) )
    	printf("MFHI\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFLO_FUN) == 0) )
    	printf("MFLO\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFCZ_FUN) == 0) ) //mfcZ
    //	printf("ADD\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MTCZ_FUN) == 0) ) // mtcZ
    //	printf("ADD\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, AND_FUN) == 0) )
    	printf("AND\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, OR_FUN) == 0) )
    	OR_B(instruction);
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, XOR_FUN) == 0) ) // xor
    //	printf("XOR\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, NOR_FUN) == 0) )
        NOR_B(instruction);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLT_FUN) == 0) )
    	printf("SLT\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLL_FUN) == 0) )
    	printf("SLL\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRA_FUN) == 0) ) // sra
    //	printf("SRA\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLLV_FUN ) == 0) ) // sllv
    //	printf("SLLV\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRLV_FUN) == 0) ) //SRLV
    //	printf("SRLV\n");
	//else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRAV_FUN) == 0) ) //SRAV
    //	printf("SRAV\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, JMP_FUN) == 0) )
    	printf("JR\n");

    //Binários tipo I
    else if ( (strcmpi(opCode, ADDI_OP) == 0) )
    	printf("ADDI\n");
    else if ( (strcmpi(opCode, ADDIU_OP) == 0) )
    	printf("ADDIU\n");
    else if ( (strcmpi(opCode, LW_OP) == 0) )
    	printf("LW\n");
    //else if ( (strcmpi(opCode, LH_OP) == 0) )
    //	printf("LH\n");
    else if ( (strcmpi(opCode, LHU_OP) == 0) )
    	printf("LHU\n");
    //else if ( (strcmpi(opCode, LB_OP) == 0) )
    //	printf("LB\n");
    else if ( (strcmpi(opCode, LBU_OP) == 0) )
    	printf("LBU\n");
    else if ( (strcmpi(opCode, SW_OP) == 0) )
    	printf("SW\n");
    else if ( (strcmpi(opCode, SH_OP) == 0) )
    	printf("SH\n");
    else if ( (strcmpi(opCode, SB_OP) == 0) )
    	printf("SB\n");
    else if ( (strcmpi(opCode, LUI_OP) == 0) )
    	printf("LUI\n");
    else if ( (strcmpi(opCode, ANDI_OP) == 0) 	)
    	printf("ANDI\n");
    else if ( (strcmpi(opCode, ORI_OP) == 0) )
    	printf("ORI\n");
    else if ( (strcmpi(opCode, SLTI_OP) == 0) )
    	printf("SLTI\n");
    else if ( (strcmpi(opCode, BEQ_OP) == 0) )
    	printf("BEQ\n");
    else if ( (strcmpi(opCode, BNE_OP) == 0) )
    	printf("BNE\n");

	//Binários tipo J
	else if ( (strcmpi(opCode, J_OP) == 0) )
    	printf("J\n");
    else if ( (strcmpi(opCode, JAL_OP) == 0) )
    	printf("JAL\n");
}

#endif
