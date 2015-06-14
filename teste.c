#include<stdio.h>
#include <stdlib.h>
#include "binary.h"

int main(){
	char teste[10] = "a";
	
	stringComplete(5, teste, teste);
	printf("%s\n", teste);
	
	system("pause");
}
