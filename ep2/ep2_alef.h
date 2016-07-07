#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef FUNC_H
#define FUNC_H
//A função max verifica dois inteiros e retorna o maior.
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
//A função maior_subsequencia verifica duas strings e retorna a maior subsequencia comum.
void maior_subsequencia(char* string1, char* string2){
	int tam1, tam2, i, j, maior, maximo, a, b, cont=0;
	char ultimo;
	//Verifica o tamanho das strings.
	tam1= strlen(string1);
	tam2= strlen(string2);
	//Aloca dinâmicamente os vetores e as matrizes utilizados pela função.
	int* vetor1= (int*) malloc((tam1+2)*sizeof(int)); 
	int* vetor2= (int*) malloc((tam2+2)*sizeof(int));	
	int** matriz= (int**) malloc((tam2+2)*sizeof(int*));
	char** aux= (char**) malloc((tam2+2)*sizeof(char*));
	for(i=0; i<(tam2+2); i++){
		matriz[i]= (int*) malloc((tam1+2)*sizeof(int));
		aux[i]= (char*) malloc((tam1+2)*sizeof(char));
	}	
	// Aloca cada string em um vetor do tipo inteiro, de forma que cada caractere passará a ter o seu valor correspondente na Tabela ASCII. 
	for(i=0;i<tam2+2; i++){
		vetor2[i]= (string2[i]);
		for(j=0; j<tam1+2; j++){
			vetor1[j]= (string1[j]);
			matriz[i][j]=0;
		}
	}
	// A matriz recebe as strings 1 e 2 na linha zero e na coluna zero, respectivamente.
	for(i=0; i<tam2; i++){
		for(j=0; j<tam1; j++){
			matriz[0][j+2]= vetor1[j];
			matriz[i+2][0]= vetor2[i];	
			maximo= max(matriz[i+2][j+1], matriz[i+1][j+2]);
			//Verificação dos caracteres comuns às duas strings e, por fim, verificação da maior subsequência comum.	
			if(vetor1[j]== vetor2[i]){
				matriz[i+2][j+2]= matriz [i+1][j+1] + 1;
				aux[i+2][j+2]= 'd';
			}	
			else if(maximo==matriz[i+2][j+1]){
				matriz[i+2][j+2]= maximo;
				aux[i+2][j+2]= 'e';
			}	
			else{
				matriz[i+2][j+2]= maximo;
				aux[i+2][j+2]= 'c';
			}
		}
	}
	a=tam2+1;
	b=tam1+1;
	maior= matriz[a][b];
	ultimo= aux[a][b];
	//Armazena os caracteres da maior subsequência comum em um vetor auxiliar.
	char* vetor_aux= (char*) malloc(maior*sizeof(char));
	i=0;
	while(cont<maior){
		if(ultimo=='d'){
			vetor_aux[i]= string2[a-2];
			a--;
			b--;
			cont++;
			i++;
		}
		if(ultimo=='c')
			a--;
		if(ultimo=='e')
			b--;
		ultimo= aux[a][b];
	}
	//Imprime a maior subsequência comum.
	if(maior==0)
		printf("Nao há subsequência comum!");
	else{
		for(i=maior-1; i>=0; i--)
			printf("%c ", vetor_aux[i]);
	}	
	printf("\n");
	free(vetor1);
	free(vetor2);
	free(vetor_aux);
	for(i=0; i<(tam2+2); i++){
		free(matriz[i]);
		free(aux[i]);
	}	
	free(matriz);
	free(aux);
}


#endif