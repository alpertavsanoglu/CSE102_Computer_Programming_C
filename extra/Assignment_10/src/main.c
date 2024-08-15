#include <stdio.h>
#include <stdlib.h>
#define STACK_BLOCK_SIZE 10

struct Stack	{ int * array; int currentsize; int maxsize;	};		//struct

struct Stack* s(int maxsize){
	struct Stack* s =(struct Stack*) malloc(sizeof(struct Stack));
	s -> maxsize = maxsize;
	s -> currentsize = -1;
	s -> array = (int*) malloc(s -> maxsize * sizeof(int));
	return s;		}
int init(struct Stack* s);				//functions
int init_return(struct Stack* s);
void push(struct Stack *s, int d);
int pop(struct Stack* s);
void puzzle(char first ,char second, int p);
void tower(struct Stack *a, struct Stack *b, char temp, char arr);
void gameplay(int size, struct Stack*a, struct Stack *b, struct Stack *c);
void final_func(int x);

int main(){
	int size=0;
	printf("Enter Tower size:");			//take size from user
	scanf("%d",&size);
	final_func(size);
	return 0;
}
void gameplay(int size, struct Stack*a, struct Stack *b, struct Stack *c){		//gameplay function
	int k=0;
	int temp;
	char one = '1';
	char second = '2';
	char third = '3';
	if (size % 2 == 0){
	char temp = third;
	third = second;
	second = temp;	}
	int sonuc=1;
	while(size>k){	sonuc=sonuc*2;	k++;	}		//while loop
	temp = (sonuc)-1; 
	k=size;
	while(1<=k){	push(a,k);	k--;	}		//while loop
	k=1;
	while(k <= temp){					//while loop
			if (k % 3 == 1){	tower(a, c, one, third);	}		// check condt.
			else if (k % 3 == 2){	tower(a, b, one, second);	}
			else if (k % 3 == 0){	tower(b, c, second, third);	}
			k++;	}
}

void final_func(int x){			//final function	
struct Stack *a, *b, *c;
	a = s(x);
	b = s(x);
	c = s(x);
	gameplay(x, a, b, c);
}

int init(struct Stack* s){	return (s->currentsize == s->maxsize - 1);	}			//init function

int init_return(struct Stack* s){	return (s->currentsize == -1);	}			//init_return function

void push(struct Stack *s, int d){	if (init(s))		return;
							s -> array[++s -> currentsize] = d ;		}		//push
							
int pop(struct Stack* s){	if (init_return(s))		return -2147483648;		//INT_MIN
					return s -> array[s -> currentsize--];	}					//pop

void puzzle(char first ,char second, int p){	printf("Move the disk %d from \'%c\' to \'%c\'\n", p, first, second);	}	//for print

void tower(struct Stack *a, struct Stack *b, char temp, char arr){
int size = pop(a);
int size_2 = pop(b);
	if (size == -2147483648){	push(a, size_2);	puzzle(arr, temp, size_2);	}	//INT_MIN
	else if (size_2 == -2147483648){	push(b, size);	puzzle(temp, arr, size);	}	//INT_MIN
	else if (size > size_2){	push(a, size);	push(a, size_2);	puzzle(arr, temp, size_2);	}
	else{	push(b, size_2);	push(b, size);	puzzle(temp, arr, size);	}
}
