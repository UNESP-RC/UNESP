#ifndef _BinAss_
#define _BinAss_
#include "constsOP_Fun.h"
#include "constsReg.h"
#include "useful.h"
#include "binary.h"
#include "file.h"

int cont ,  controlLabelB = -1;
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

	//registrador RS
	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

    //registrador RT
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

    //registrador RD
	substring(result, binary, 11, 5);
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

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
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

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
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

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
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

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
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

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void ORI_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "ORI ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SLT_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SLT ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary,11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SLTU_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SLTU ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SUBU_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SUBU ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void XOR_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "XOR ");

	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void ADDI_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "ADDI ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void ADDIU_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "ADDIU ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void ANDI_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "ANDI ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LW_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "LW ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SLTI_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SLTI ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void J_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "J ");

	substring(result, binary, 25, 6);
	strcat(instruction, gLabelB[getControlLabelB(result)].title);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void DIV_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "DIV ");

    //registrador RS
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void MULT_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "MULT ");

    //registrador RS
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void MULTU_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "MULTU ");
    //registrador RS
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void MFHI_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "MFHI ");

	// Registrador rd
	substring(result, binary, 21, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void MFLO_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "MFLO ");

	// Registrador rd
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SW_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SW ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void BEQ_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "BEQ ");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//LABEL
    substring(result, binary, 25, 6);
	strcat(instruction, gLabelB[getControlLabelB(result)].title);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void BNE_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "BNE ");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//LABEL
    substring(result, binary, 25, 6);
	strcat(instruction, gLabelB[getControlLabelB(result)].title);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void JR_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "JR ");

    //registrador RS
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SLL_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SLL ");

	//Register rd
    substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Shamt
    substring(result, binary, 21, 5);
    binaryToDecimal(result, result);
    strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SRL_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SRL ");

	//Register rd
    substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Shamt
    substring(result, binary, 21, 5);
    binaryToDecimal(result, result);
    strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SRA_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SRA ");

	//Register rd
    substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Shamt
    substring(result, binary, 21, 5);
    binaryToDecimal(result, result);
    strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SLLV_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SLLV ");
    //registrador RS
	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RD
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SRAV_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SRAV ");
    //registrador RS
	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RD
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SRLV_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "SRLV ");
    //registrador RS
	substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RD
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SB_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SB ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LBU_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "LBU ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LHU_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SLL ");

	//Register rd
    substring(result, binary, 16, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Register rt
	strcat(instruction, "LHU ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void SH_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "SH ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void DIVU_B(char* binary){
	char instruction[255] = "";
	char result[10] = "";
	char aux[10] = "";

	strcat(instruction, "DIVU ");
    //registrador RS
	substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");
    //registrador RT
	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LH_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "LH ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LB_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "LB ");

    //Register rt
    substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	strcat(instruction, "(");

	//Register rs
    substring(result, binary, 6, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ")");

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void LUI_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "LUI ");

	substring(result, binary, 11, 5);
	getNameRegister(aux, result);
	strcat(instruction, aux);
	strcat(instruction, ", ");

	//Constant
	substring(result, binary, 16, 16);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void JAL_B(char* binary){
	char instruction[255] = "";
	char result[255] = "";
	char aux[10] = "";

	strcat(instruction, "JAL ");

	substring(result, binary, 7,32);
	binaryToDecimal(result, result);
	strcat(instruction, result);

	printf("%s\n", instruction);
	writeToFile(instruction);
}
void analiseBinary(char* binary){
	char opCode[7] = "";
	char funct[10] = "";

	strcpy(binary, trim(binary));

    //Tratamento para label
	if(strlen(binary) == 6){
		char llabel[10] = "";
		strcpy(llabel, gLabelB[getControlLabelB(binary)].title);
		strcat(llabel, ":");
		printf("%s\n", llabel);
		writeToFile(llabel);
		return;
	}

	substring(opCode, binary, 0, 6);
	substring(funct, binary, 26, 6);

	//Binários tipo R
    if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADD_FUN) == 0) )
    	ADD_B(binary);
	else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, ADDU_FUN) == 0) )
    	ADDU_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SUB_FUN) == 0) )
    	SUB_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SUBU_FUN) == 0) )
    	SUBU_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MULT_FUN) == 0) )
    	MULT_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MULTU_FUN) == 0) )
        MULTU_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, DIV_FUN) == 0) )
        DIV_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, DIVU_FUN) == 0) )
    	DIVU_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFHI_FUN) == 0) )
    	MFHI_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFLO_FUN) == 0) )
    	MFLO_B(binary);
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MFCZ_FUN) == 0) ) //mfcZ
    //	printf("ADD\n");
    //else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, MTCZ_FUN) == 0) ) // mtcZ
    //	printf("ADD\n");
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, AND_FUN) == 0) )
    	AND_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, OR_FUN) == 0) )
    	OR_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, XOR_FUN) == 0) )
        XOR_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, NOR_FUN) == 0) )
        NOR_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLT_FUN) == 0) )
    	SLT_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLL_FUN) == 0) )
    	SLL_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRL_FUN) == 0) )
    	SRL_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRA_FUN) == 0) ) // sra
    	SRA_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLLV_FUN ) == 0) ) // sllv
    	SLLV_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRLV_FUN) == 0) ) //SRLV
    	SRLV_B(binary);
	else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SRAV_FUN) == 0) ) //SRAV
    	SRAV_B(binary);
    else if ( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, JMP_FUN) == 0) )
    	JR_B(binary);
    else if	( (strcmpi(opCode, R_OP) == 0) && (strcmpi(funct, SLTU_FUN) == 0) )
        SLTU_B(binary);

    //Binários tipo I
    else if ( (strcmpi(opCode, ADDI_OP) == 0) )
    	ADDI_B(binary);
    else if ( (strcmpi(opCode, ADDIU_OP) == 0) )
    	ADDIU_B(binary);
    else if ( (strcmpi(opCode, LW_OP) == 0) )
    	LW_B(binary);
    else if ( (strcmpi(opCode, LH_OP) == 0) )
    	LH_B(binary);
    else if ( (strcmpi(opCode, LHU_OP) == 0) )
    	LHU_B(binary);
    else if ( (strcmpi(opCode, LB_OP) == 0) )
    	LB_B(binary);
    else if ( (strcmpi(opCode, LBU_OP) == 0) )
    	LBU_B(binary);
    else if ( (strcmpi(opCode, SW_OP) == 0) )
    	SW_B(binary);
    else if ( (strcmpi(opCode, SH_OP) == 0) )
    	SH_B(binary);
    else if ( (strcmpi(opCode, SB_OP) == 0) )
    	SB_B(binary);
    else if ( (strcmpi(opCode, LUI_OP) == 0) )
    	LUI_B(binary);
    else if ( (strcmpi(opCode, ANDI_OP) == 0) 	)
    	ANDI_B(binary);
    else if ( (strcmpi(opCode, ORI_OP) == 0) )
    	ORI_B(binary);
    else if ( (strcmpi(opCode, SLTI_OP) == 0) )
        SLTI_B(binary);
    else if ( (strcmpi(opCode, BEQ_OP) == 0) )
    	BEQ_B(binary);
    else if ( (strcmpi(opCode, BNE_OP) == 0) )
    	BNE_B(binary);

	//Binários tipo J
	else if ( (strcmpi(opCode, J_OP) == 0) )
    	J_B(binary);
    else if ( (strcmpi(opCode, JAL_OP) == 0) )
    	JAL_B(binary);
}
#endif
