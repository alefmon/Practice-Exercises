#include "ep2_alef.h"

int main(int argc, char *argv[])
{
	//Verifica se a entrada está correta.
	if(argv[1]==NULL || argv[2]==NULL){
		printf("Nao há subsequência comum!\n");
		exit(0);
	}
	else if(argc!=3){
		printf("Entrada incorreta! Insira apenas duas strings.\n");
		exit(0);
	}	
	char* string1, *string2;
	//Aloca os argumentos passados no terminal em strings.
	string1= (argv[1]);
	string2= (argv[2]);
	//Chama a função que verifica e imprime a maior subsequência comum entre as strings.
	maior_subsequencia(string1, string2);
	return 0;
}