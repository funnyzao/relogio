#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numeros.c"

//primeiro digito (0,1)
//segundo digito (8, 1)
//dois pontos (14, 1)
//terceiro digito (20, 1)
//quarto ditito (28, 1)

void printNumber(const int (*number)[6], int*, int*);

int main(){
	time_t now=time(NULL);
	struct tm *t = localtime(&now);
	int i, j, y=1, x=0, numero1, numero2;
	
	
	while(1){
		now=time(NULL);
		struct tm *t = localtime(&now);
		
		numero1=t->tm_hour/10;
		numero2=t->tm_hour%10;
		
		system("cls");
		//printf("\033[2J");
		
		printNumber(vetor[numero1], &x, &y);
		x+=8;
		y=1;
		printNumber(vetor[numero2], &x, &y);
		x+=6;
		y=1;
		
		printNumber(vetor[10], &x, &y);
		x+=6;
		y=1;
		
		numero1=t->tm_min/10;
		numero2=t->tm_min%10;
		
		printNumber(vetor[numero1], &x, &y);
		x+=8;
		y=1;
		printNumber(vetor[numero2], &x, &y);
		x+=6;
		y=1;
		
		printNumber(vetor[10], &x, &y);
		x+=6;
		y=1;
		
		numero1=t->tm_sec/10;
		numero2=t->tm_sec%10;
		
		printNumber(vetor[numero1], &x, &y);
		x+=8;
		y=1;
		printNumber(vetor[numero2], &x, &y);
		
		puts("");
		y=1;
		x=0;
		Sleep(1000);
	}
	return 0;
}

void printNumber(const int (*number)[6], int *x, int *y){
	int i, j;
	char string[7];
	
	for(i=0;i<5;i++){
		for(j=0;j<6;j++){
			if(number[i][j]==0){
				string[j]=' ';
			}
			else{
				string[j]=number[i][j]+218;
			}
		}
		string[j]='\0';
		printf("\033[%i;%iH", (*y)++, *x);
		fputs(string, stdout);
	}
}
