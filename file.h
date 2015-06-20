#ifndef _file_
#define _file_

FILE* arq;

void openFile(char* fileName){
	arq = fopen(fileName, "w+");
}

void writeToFile(char* string){
	fprintf(arq, "%s\n", string);
}

#endif
