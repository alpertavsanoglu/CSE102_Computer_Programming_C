#include <stdio.h>

#define p1 0.5			/*easy way for trying different number of samples */
#define p2 20			/*easy way for trying different number of samples */
#define MAX_INPUT 1000		/*Maximum length of the input sequence is 1000*/
#define MAX_NUM_CHUNK 100	/*Maximum number of chunks is 100*/

int main(){				/* main function */
	int i,j,z;					/* i,j and z for loops	*/
	double a=0.0,b=0.0,n=0.0;			/* variables for checked condition */
	double number_from_file[MAX_INPUT],store[MAX_INPUT],average[MAX_NUM_CHUNK],chunk_array[MAX_NUM_CHUNK][MAX_NUM_CHUNK],size[MAX_NUM_CHUNK];	/* arrays for counting,ordering,.. numbers  */
	double size_store,average_store,total=0.0;
	int size_of_input=1,x=0,y=1;

FILE* input=fopen("input.txt","r");						/*opening file*/

if((input = fopen("input.txt", "r")) == NULL){ 			/* error check */
		printf("File not found");				/* if file didnt found */
		return -1;			
						}
else{
	int return_value=fscanf(input,"%lf",&number_from_file[0]);		/*take variables from file*/
		while(return_value==1 && return_value!=EOF ){			/*until eof*/
								return_value=fscanf(input,"%lf",&number_from_file[size_of_input]);		/*store valuesto array*/
	if(return_value!=1 || return_value==EOF ){ break; }
								size_of_input++;								/*counting numbers*/
								}
}
fclose(input);			/*closing file*/

chunk_array[0][0]=number_from_file[0];			/*stored first number */
i=0;
while(i<size_of_input){				/*while loop*/

total+=number_from_file[i];
n=number_from_file[i+1];
a=total/y;				/*average of the chunk*/
b=(total+n)/(y+1);
			if(!(b>a*(1+p1) || b<a*(1-p1) || a>n*p2 || a<n/p2)){					/*check condition*/
										chunk_array[x][y]=n;
										y++;
										}
			else{
				size[x]=y;
				average[x]=a;
				x++;
				if (x == MAX_NUM_CHUNK){ break; }			/*check max chunk number (100)*/
				a=0,b=0,y=1,total=0;
				chunk_array[x][y-1]=n;
				}
i++;
}

j=0;
while(j<x){			/*while loop*/ /*this part for sorting*/
	i=j+1;
	while(i<x){					/*while loop*/
		if(average[j]>average[i]){
average_store=average[j];		/* buble sort */
average[j]=average[i];				/*sorting*/
average[i]=average_store;
				
				z=0;
				while(z<size[j]){				/*while loop*/
					store[z]=chunk_array[j][z];
				z++;
				}
				z=0;
				while(z<size[i]){				/*while loop*/
					chunk_array[j][z]=chunk_array[i][z];
				z++;
				}
				z=0;
				while(z<size[j]){				/*while loop*/
					chunk_array[i][z]=store[z];
				z++;
				}
				
size_store=size[j];			/* buble sort */
size[j]=size[i];				/*sorting*/
size[i]=size_store;
			}
	i++;
	}
j++;
}

FILE* output=fopen("output.txt","w");			/*opening file*/
i=0;
while(i<x){		/*while loop*/
	j=0;
	while(j<size[i]){			/*while loop*/
			if(j==size[i]-1){
					fprintf(output,"%.4lf",chunk_array[i][j]);		/*check for not print unwanted chars and spaces in output.txt*/
					}
			else{
				fprintf(output,"%.4lf ",chunk_array[i][j]);		/*print " " until end*/
				}
	j++;
	}
			if(i==x-1){}								/*check for not print unwanted chars and spaces in output.txt*/
			else{
				fprintf(output,"\n");					/*print "\n" until end*/
				}
i++;
}
fclose(output);			/*closing file*/
return 0;
}
