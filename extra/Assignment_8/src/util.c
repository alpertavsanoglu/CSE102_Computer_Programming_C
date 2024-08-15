#include <stdio.h>
#include <stdlib.h>
#include "util.h"

#define return_0 0			//define 0 for return 0
#define return_1 1			//define 1 for return 1

void generate_sequence(int xs, int currentlen, int seqlen, int *seq){		// function for part 1

int stored;

if(seqlen <= currentlen) return ;
	else{
do{
		if(xs%2==0){		stored=(xs/2);			//check mod 2
					seq[currentlen]=stored;
					currentlen++;
					generate_sequence(stored,currentlen,seqlen,seq);	//recursion func
					return;
				}
					else{		stored = xs * 3 + 1;		//Collatz Conjecture
							seq[currentlen]=stored;
							currentlen++;
							generate_sequence(stored,currentlen,seqlen,seq);	//recursion func
							return;
						}
}while(seqlen != currentlen);
		}
}

void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop, int *looplen){		//function for part 2
int *temp;
int flag=0;
int a=0;
int b=0;
int long_1;
int long_2;
int over_2=2;
int condt=0;
int condt_2=0;
int condt_3=0;
int condt_4=0;
int condt_5=0;

temp = (int*) malloc((10+seqlen)*sizeof(int));			temp[flag]=xs;			generate_sequence(xs, 1, seqlen,temp);	//go part1 func
if(*looplen!=(seqlen/over_2)){ condt=1;}			//check conditions
if(*looplen<=1){ condt_3=1;}					//check conditions
if(has_loop(temp, seqlen, *looplen, &long_2, &long_1) == 0){ condt_4=1;}			//check conditions
if(*looplen>=2){ condt_5=1;}									//check conditions
				if(condt != 1){		//check conditions
						printf("\nSequence :");
						printf("{");
						while(a<seqlen){	printf("%d", temp[a]);	if((-1)+seqlen==a){ condt_2=1;}		if(condt_2!=1){	printf(" , ");}		a++;}//while loop
						printf("}\n");}
				if(condt_3 != 1){	//check conditions
						printf("\nChecking if there is a loop of length %d...\n", *looplen);
						if(condt_4 != 1){
								printf("\nLoop detected with a length of %d.\n", *looplen);
								printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n", long_2, long_1-1);
								while(b<*looplen){		loop[b] = temp[long_2 + b];			b++;}	return;
								}
						else{	*looplen = *looplen - 1;		check_loop_iterative(generate_sequence, xs, seqlen, loop, looplen);	return;	}	//recursion func
						}
				if(condt_5 != 1){	*looplen = 0;}	return;		//check conditions
}

int has_loop (int *arr, int n, int looplen, int *ls, int *le){			//function for part 3
/*it will return 1 if a loop exists, 0 otherwise.*/
int flag=0;
int a=0;
int b=0;
	while(a<n){		//while loop
			b=a;
			while(b<looplen+a){	if(arr[looplen+b] == arr[b])		flag++;			b++;	}			//while loop
			
			
			if(looplen == flag){		*ls = (b - looplen);
							*le = b;
							return return_1;
						}
			flag = 0;
			a++;
		}
		return return_0;
}

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit){			//function for part 4
int *temp;
int flag=0;
int a=0;
int b=0;
int size=10;

temp = (int*) malloc((1+seqlen)*sizeof(int));		/*malloc*/	temp[flag]=xs;
generate_sequence(xs, 1, seqlen, temp);	//go part1 func

while(a<seqlen){
			while(temp[a] >= size){		temp[a] = temp[a] / size;		//while loop
						}		
		a++;
		}

if(size-1 >=digit-1){			while(b<seqlen){	if( digit == temp [b] )	h[digit-1] += 1;		//digit-1 because ignore 0
							b++;
							}
		hist_of_firstdigits(generate_sequence, xs, seqlen, h, digit+1);		//recursion func
		return;
			}
}
