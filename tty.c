#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numeros.c"

//primeiro digito (0,1)
//segundo digito (8, 1)
//dois pontos (14, 1)
//terceiro digito (20, 1)
//quarto ditito (28, 1)

void printNumber(const Numero, int*, int*);

int main(){
	time_t now=time(NULL);
	struct tm *t = localtime(&now);
	int i, j, y=1, x=0, numero1, numero2;
	
	numero1=t->tm_hour/10;
	numero2=t->tm_hour%10;
	
	printf("\033[2J");
	
	printNumber(*vetor[numero1], &x, &y);
	x+=8;
	y=1;
	printNumber(*vetor[numero2], &x, &y);
	x+=6;
	y=1;
	
	printNumber(*vetor[10], &x, &y);
	x+=6;
	y=1;
	
	numero1=t->tm_min/10;
	numero2=t->tm_min%10;
	
	printNumber(*vetor[numero1], &x, &y);
	x+=8;
	y=1;
	printNumber(*vetor[numero2], &x, &y);
	
	puts("");

	return 0;
}

void printNumber(const Numero number, int *x, int *y){
	int i, j;
	char string[5];
	
	for(i=0;i<5;i++){
		for(j=0;j<6;j++){
			if(number.grade[i][j]==0){
				string[j]=' ';
			}
			else{
				string[j]=number.grade[i][j]+218;
			}
		}
		string[j]='\0';
		printf("\033[%i;%iH", (*y)++, *x);
		fputs(string, stdout);
	}
}
