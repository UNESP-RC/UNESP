#ifndef _BinAss_
#define _BinAss_

#include "constsOP_Fun.h"
#include "constsReg.h"
#include "useful.h"
#include "file.h"

int controlLabelB = -1;
typedef struct labelB{
	char binary[7];
    char title[10];
} labelB;
labelB gLabelB[32];

int getControlLabelB(char* prLabelB){
	int i=0;
	for(i=0; i <= controlLabelB; i++)
		if(strcmpi(gLabelB[i].binary, prLabelB) == 0)
		  return i;

	controlLabelB++;
	char stCtrlLabel[10] = "";
	char title[10] = "LABEL";
	itoa(controlLabelB, stCtrlLabel, 10);
	strcat(title, stCtrlLabel);	
	
	strcpy(gLabelB[controlLabelB].binary, prLabelB);
	strcpy(gLabelB[controlLabelB].title, title);

    return controlLabelB;
}

void ADD_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";
	
	strcat(instruction, "ADD ");
	
	substring(result, binary, 6, 5);	
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
	
	substring(result, binary, 11, 5);	
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
	
	substring(result, binary, 16, 5);	
	getNameRegister(aux, result);
	strcat(instruction, aux);
	
	printf("%s\n", instruction);
	writeToFile(instruction);
}

void analiseBinary(char* binary){
	char opCode[7] = "";
	char funct[10] = "";
	
	strcpy(binary, trim(binary));
	
	if(strlen(binary) < 32){
		printf("%s\n", gLabelB[getControlLabelB(binary)].title);
		return;
	}
	
	substring(opCode, binary, 0, 6);	
	substring(funct, binary, 20, 6);
		
	//Binários tipo R
    if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADD_FUN) == 0) )
    	ADD_B(binary);
	else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADDU_FUN) == 0) )
    	printf("ADDU\n"); //ADDU_B(instruction);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SUB_FUN) == 0) )
    	printf("SUB\n"); //SUB_B(instruction);
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
    	printf("OR\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, XOR_FUN) == 0) ) // xor
    //	printf("XOR\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, NOR_FUN) == 0) )
    	printf("NOR\n");
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
