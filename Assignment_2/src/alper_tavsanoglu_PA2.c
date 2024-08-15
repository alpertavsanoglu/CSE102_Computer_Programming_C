#include <stdio.h>

int main(){				/* main function */
	int numbers[100] = {0};		/* array for numbers from file */
	int counter[100] = {0};		/* array for counting numbers  */
	int i=0,j=0,k=0;			/* i,j and k for loops	*/
	int number_from_file;		/* for taking numbers*/
	int flag = 0;			/* for cheking conditions*/
	int size = 0;			/* for size*/
	int temp = 0;			/* for temporary values */
FILE *fp;
	if((fp = fopen("input.txt", "r")) == NULL){ 			/* error check */
		printf("File not found");				/* if file didnt found */
		return -1;			
						}
	else{
		while(!feof(fp)){									/*while loop*/
					if(fscanf(fp, "%d", &number_from_file)==-1){ break; }					/*if there is no integer for read*/
												flag=0;
		for (i=0; i<size; i++){
						if(number_from_file == numbers[i]){						
										counter[i]++;
										flag =1;
										break;
											}
						}
			if(flag == 0){						/*if flag =0*/
					numbers[size] = number_from_file;
					counter[size] = 1;
					size++;
					}
				}
		}
fclose(fp);
	i=0;
	while(i<size){				/*while loop*/
		for(k=0; k<size-1; k++){			/*for loop*/
			if(counter[k]>counter[k+1]){							/* buble sort */
							temp= counter[k];						/*sorting*/
							counter[k]=counter[k+1];
							counter[k+1]= temp;
							temp= numbers[k];
							numbers[k]=numbers[k+1];
							numbers[k+1]= temp;
							}
			else if (counter[k] == counter[k+1]){
					if(numbers[k]>numbers[k+1]){					/* buble sort */
									temp = numbers[k];				/*sorting*/
									numbers[k] = numbers[k+1];
									numbers[k+1] = temp;
									temp= counter[k];
									counter[k]=counter[k+1];
									counter[k+1]= temp;
								}
							}

					}
				i++;
				}
if((fp = fopen("output.txt", "w")) == NULL){							/* error check */
						printf("File didnt created");			/* if file didnt create */
						return -1;
					}
else{
		i=0;
		while(i<size){								/* while loop */
				if(i==size-1){
					fprintf(fp, "%d:%d", numbers[i], counter[i]);
					}
				else{
				fprintf(fp, "%d:%d\n", numbers[i], counter[i]);			/* printing sorted numbers */
				}
				i++;
				}
	}
fclose(fp);
return 0;
}					

