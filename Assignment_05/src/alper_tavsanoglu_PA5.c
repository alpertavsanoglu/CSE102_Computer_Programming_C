#include <stdio.h>

void searching(double counter[27][27],FILE *fp);					/*searching bi-grams*/
void frequence(double counter[27][27],double sums);					/*find freequences*/
double dissimilarity(double counter_first[27][27],double counter_second[27][27]);	/*find dissimilarity*/	
void reset_array(double counter[27][27]);						/*for filled array with 0*/

int main(){

double counter1[27][27]={0};		/*count language_12345.txt bi-grams */
double counterx[27][27]={0};		/*count language_x.txt bi-grams */
double sum1=0.0,sumx=0.0;
double find_diss_x_file=0.0;		/*dissimilarity value*/

FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fpx;				/*opening files*/

fp1=fopen("language_1.txt","r");			/*language_1.txt*/
fp2=fopen("language_2.txt","r");			/*language_2.txt*/
fp3=fopen("language_3.txt","r");			/*language_3.txt*/
fp4=fopen("language_4.txt","r");			/*language_4.txt*/
fp5=fopen("language_5.txt","r");			/*language_5.txt*/
fpx=fopen("language_x.txt","r");			/*language_x.txt*/

					/*language_x.txt*/
	searching(counterx,fpx);					/*searching bi-grams*/
	frequence(counterx,sumx);					/*find freequences*/
					/*language_1.txt*/
	searching(counter1,fp1);					/*searching bi-grams*/
	frequence(counter1,sum1);					/*find freequences*/
	find_diss_x_file=dissimilarity(counterx,counter1);		/*find dissimilarity*/	
	printf("%f",find_diss_x_file);
					/*language_1.txt*/
reset_array(counter1);
find_diss_x_file=0.0;
sum1=0.0;
					/*language_2.txt*/
	searching(counter1,fp2);					/*searching bi-grams*/
	frequence(counter1,sum1);					/*find freequences*/
	find_diss_x_file=dissimilarity(counterx,counter1);		/*find dissimilarity*/	
	printf("\n%f",find_diss_x_file);
					/*language_2.txt*/
reset_array(counter1);
find_diss_x_file=0.0;
sum1=0.0;
					/*language_3.txt*/
	searching(counter1,fp3);					/*searching bi-grams*/
	frequence(counter1,sum1);					/*find freequences*/
	find_diss_x_file=dissimilarity(counterx,counter1);		/*find dissimilarity*/	
	printf("\n%f",find_diss_x_file);
					/*language_3.txt*/
reset_array(counter1);
find_diss_x_file=0.0;
sum1=0.0;
					/*language_4.txt*/
	searching(counter1,fp4);					/*searching bi-grams*/
	frequence(counter1,sum1);					/*find freequences*/
	find_diss_x_file=dissimilarity(counterx,counter1);		/*find dissimilarity*/	
	printf("\n%f",find_diss_x_file);
					/*language_4.txt*/
reset_array(counter1);
find_diss_x_file=0.0;
sum1=0.0;
					/*language_5.txt*/
	searching(counter1,fp5);					/*searching bi-grams*/
	frequence(counter1,sum1);					/*find freequences*/
	find_diss_x_file=dissimilarity(counterx,counter1);		/*find dissimilarity*/	
	printf("\n%f\n",find_diss_x_file);
					/*language_5.txt*/

fclose(fp1);			/*closing file*/
fclose(fp2);			/*closing file*/
fclose(fp3);			/*closing file*/
fclose(fp4);			/*closing file*/
fclose(fp5);			/*closing file*/
fclose(fpx);			/*closing file*/

return 0;
}

void reset_array (double counter[27][27]){		/*for filled array with 0*/
    
    for (int i = 0; i < 27; i++){
        for (int j = 0; j < 27; j++){
                                 counter[i][j] = 0;
                                  }
                                        }
}

double dissimilarity(double counter_first[27][27],double counter_second[27][27]){		/*find dissimilarity*/

double difference=0.0;
double temp=0.0;
				for(int i=0;i<27;i++){
					for(int j=0;j<27;j++){
						temp=counter_first[i][j]-counter_second[i][j];	/*subtraction bi-grams*/
							if(temp<0){				/*for checking negative values*/
								temp= temp * -1;
									}
						difference=difference+temp;
						temp=0.0;				/*reset temp*/
								}
							}
return difference;
}

void frequence(double counter[27][27],double sums){		/*find freequences*/
    
sums=0.0;
				for(int i=0;i<27;i++){
					for(int j=0;j<27;j++){
						sums=sums+counter[i][j];		/*add all bi-grams*/
								}
							}
				if(sums==0.0){				/*for 0/0 condition*/
					sums=0.000001;
						}
		for(int i=0;i<27;i++){
			for(int j=0;j<27;j++){
					counter[i][j]=counter[i][j]/sums;		/*find frequence*/
						}
					}
}

void searching(double counter[27][27],FILE *fp1){					/*searching bi-grams*/
    
char a,b,temp=EOF;
int condt=0;

while(condt!=EOF){	condt=fscanf(fp1,"%c%c",&a,&b);			/*take input from file1*/
			if(condt==EOF){							/*cheakin contd*/
				break;
					}
			if(condt==1){							/*if we scan 1 char*/
				if(temp==EOF){						/*and our temp didnt change so we have 1 char in txt file*/
					break;
						}
				for(int i=97,z=0;i<=122;i++,z++){
					for(int j=97,y=0;j<=122;j++,y++){
									if(temp ==i && a==j ){		/*check bi-gram conditions*/
										counter[z][y]++;	/*and increase it in 2d array*/
												}
									}
								}
				for(int i=32,j=97,z=26,y=0;j<=122;j++,y++){
									if(temp==i && a==j ){		/*check bi-gram for blank-char*/
										counter[z][y]++;	/*and increase it in 2d array*/
												}
										else if(temp==j && a==i){		/*check bi-gram for char-blank*/
											counter[y][z]++;		/*and increase it in 2d array*/
												   	 }
										}
					break;
					}
			if(temp!=EOF){
				for(int i=97,z=0;i<=122;i++,z++){
					for(int j=97,y=0;j<=122;j++,y++){
									if(temp ==i && a==j ){		/*check bi-gram conditions*/
										counter[z][y]++;	/*and increase it in 2d array*/
												}
									}
								}
				for(int i=32,j=97,z=26,y=0;j<=122;j++,y++){
									if(temp==i && a==j ){				/*check bi-gram for blank-char*/
											counter[z][y]++;		/*and increase it in 2d array*/
												}
										else if(temp==j && a==i){		/*check bi-gram for char-blank*/
											counter[y][z]++;		/*and increase it in 2d array*/
													}
										}
					}
			for(int i=97,z=0;i<=122;i++,z++){
				for(int j=97,y=0;j<=122;j++,y++){
							if(a ==i && b==j ){				/*check bi-gram conditions*/
								counter[z][y]++;			/*and increase it in 2d array*/
										}
								}
							}
			for(int i=32,j=97,z=26,y=0;j<=122;j++,y++){
							if(a==i && b==j ){					/*check bi-gram for blank-char*/
								counter[z][y]++;				/*and increase it in 2d array*/
										}
								else if(a==j && b==i){				/*check bi-gram for char-blank*/
									counter[y][z]++;			/*and increase it in 2d array*/
											}
									}
			temp=b;				/*store second char which we scanned*/
	}
}
