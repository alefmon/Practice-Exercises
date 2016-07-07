#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//A funçao minimo compara 3 custos e retorna o menor valor. 

int minimo( int custoCima, int custoEsquerda, int custoDiagonal){
	if(custoCima < custoEsquerda && custoCima < custoDiagonal) 
		return custoCima;
	else if(custoEsquerda < custoCima && custoEsquerda < custoDiagonal)
		return custoEsquerda;
	else
		return custoDiagonal;
}
//A função custoTotal receberá a matriz feita a partir das duas palavras que o usuário fornecer e o tamanho das duas palavras. A partir disso, ela retornará a distância de edição entre as duas palavras.

int custoTotal(int x[50][50], int tamanho1, int tamanho2){
	int i, j, custoEsquerda, custoCima, custoDiagonal, custoTotal;
	
	// Os dois "for" aninhados completam a matriz, de forma que o elemento [i][j] seja o menor possível, a partir da análise do menor custo.
	
	for(i=2;i<(tamanho2+2);i++){		
		for(j=2;j<(tamanho1+2);j++){
			// Verificar se as letras comparadas são iguais.
			if(x[i][0] == x[0][j])
				custoDiagonal= x[i-1][j-1];
			else
				custoDiagonal= x[i-1][j-1]+2;
			custoEsquerda= x[i][j-1] + 1;
			custoCima= x[i-1][j] + 1;
			// Calcular menor custo e atribuí-lo ao elemento [i][j].
			x[i][j]= minimo(custoCima, custoEsquerda, custoDiagonal);	
		}
	}
	custoTotal= x[tamanho2 + 1][tamanho1 +1];
	return custoTotal;
}

int main(){
	int matriz[50][50]={0};
	int i, j, tamanho1, tamanho2; 			
	char palavra1[50]={0}, palavra2[50]={0};
	printf("Digite as palavras 1 e 2:\n");
	scanf ("%s", palavra1);
	scanf ("%s", palavra2);
    //Verificar se o tamanho das palavras é compatível com o programa. 
    if(strlen(palavra1)>=50 || strlen(palavra2)>=50){
    		printf("PALAVRA MAIOR QUE 50 LETRAS! TENTE NOVAMENTE.\n");
    		exit(0);
    }		

	// Atribuir à tamanho1 e tamanho2 o tamanho das palavras fornecidas pelo usuário.
	tamanho1= strlen(palavra1);
	tamanho2= strlen(palavra2);
	// O "for" preenche a linha 0 e a coluna 0 com os números correspondentes às letras das palavras de acordo com a tabela ASCII. 
	for(i=0;i<(tamanho1+1) || i<(tamanho2+1);i++){	
		palavra1[i]= tolower(palavra1[i]);
		palavra2[i]= tolower(palavra2[i]); 
		matriz[0][i+2]= palavra1[i];
		matriz[i+2][0]= palavra2[i];
		matriz[1][i+1]= i;
		matriz[i+1][1]= i;
	}
	// Impressão da distância de edição entre as palavras, ou seja, o custo total retornado pela função custoTotal.
	printf("A distancia de edicao eh: %d\n", custoTotal(matriz, tamanho1, tamanho2));
}
