#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main(){

int select_1;
int select_2;
int a=0;
int b=0;
int one=1;
int size;
int *stored;
int *temp;
int over_2=2;
int condt=0;
int condt_2=0;
int digits=10;

temp=(int*)calloc((digits-1),sizeof(int));			//calloc


do{
	printf("Please enter the sequence length : ");
	if(scanf("%d",&select_2) != 1){				//check  character error 
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");	//print error
		continue;
	}
	else break;
}while (1);
do{
	printf("Please enter the first element : ");
	if(scanf("%d",&select_1) != 1){				//check  character error 
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");	//print error
		continue;
	}
	else break;
}while (1);
stored=(int*)malloc((select_2)*sizeof(int));				//malloc
size = select_2/over_2;			//n/2
check_loop_iterative(generate_sequence, select_1, select_2, stored, &size);			//function for part2

if(size !=0){condt=1;}							//condtion 1

	if(condt != 1){		printf("No loop found.\n");	}
			else{
				printf("Loop :");			//list loop
				printf("{");
				while(a<size){		printf("%d", stored[a]);	if((-1)+size != a)		printf(" , ");		a++;}
				printf("}\n");
				}
hist_of_firstdigits(generate_sequence, select_1, select_2, temp,one);				//function for part4
	printf("\nHistogram of the sequence :");				//list histogram
	printf("{");
	while(b<digits-1){		printf("%d", temp[b]);		if(b != digits-2)		printf(" , ");			b++;}
	printf("}\n");
		
	return 0;		//end of program
}
