#include<stdio.h>
#include <string.h>

#define MAX_ROW 100					/*Maximum number of rows is 100*/
#define MAX_COLUMN 250					/* Maximum length of each row is 250 */
#define Word_size 10					/*Maximum length of the input sequence is 10*/
int main(){			/* main function */
	
char arr_from_file[MAX_ROW][MAX_COLUMN]={0},select,word[Word_size+1];				/* declaring arrays */
int check=Word_size,condt=Word_size,size_of_word=0,size_of_row=0,k=0,j=0,x=0,y=0,z=0;		/* declaring usefull integers */
int a_S,b_S;										/* variables for South */
int temp_S,control_S=0;
int a_E,b_E;										/* variables for East */
int temp_E,control_E=0;
int a_W,b_W;										/* variables for West */
int temp_W,control_W=0;
int a_N,b_N;										/* variables for North */
int temp_N,control_N=0;	
int a_NE,b_NE;										/* variables for North East */
int temp1_NE,control_NE=0,temp2_NE;
int a_NW,b_NW;										/* variables for North West */
int temp1_NW,control_NW=0,temp2_NW;	
int a_SE,b_SE;										/* variables for South East */
int temp1_SE,control_SE=0,temp2_SE;	
int a_SW,b_SW;										/* variables for South West */
int temp1_SW,control_SW=0,temp2_SW;

FILE *fp1,*fp2,*fp3;				/*opening files*/
fp1=fopen("input1.txt","r");			/*read from input1 file*/
fp2=fopen("input2.txt","r");			/*read from input2 file*/
fp3=fopen("output.txt","w");			/*write to output file*/

while(check!=EOF){	check=fscanf(fp2,"%c",&select);			/*take input from file2*/
		
			if(check==EOF){							/*cheaking contd*/
					if(size_of_row<j){							/*cheaking contd*/
							size_of_row=j;
							}
					break;
					}
			if(select=='\n'){						/*cheaking contd*/
					k++;
					if(size_of_row<j){							/*cheaking contd*/
							size_of_row=j;
							}
					j=0;
					}
			if(select!='\n'){						/*cheaking contd*/
					arr_from_file[k][j]=select;
					j++;
					}	
		}
k=k+1;
while(condt!=EOF){	condt=fscanf(fp1,"%s",word);			/*take input from file1*/
		
			if(condt==EOF){							/*cheakin contd*/
					break;
					}
		x=0;
		while(word[x]!=0){
				size_of_word++;				/*increasing size of word*/
				x++;
				}
/*Search EAST Direction*/
	for(a_E=0; a_E<MAX_ROW; a_E++){
		for(b_E=0; b_E<MAX_COLUMN; b_E++){	
						temp_E=b_E;				/*for store b_e value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[a_E][b_E]==word[z]){
													control_E++;				/*increasing control size*/
														}
									b_E++;
										}	
						if(control_E==size_of_word){
									fprintf(fp3,"%s (%d,%d) %s\n",word,a_E+1,temp_E+1,"E");			/*print word and coordinates to output file*/
										}
						b_E=temp_E;				/*stored b_e value after word search*/
						control_E=0;			/*reset control size*/
							}
						}
/*Search WEST Direction*/
	for(a_W=MAX_ROW; 0<=a_W; a_W--){
		for(b_W=MAX_COLUMN; 0<=b_W; b_W--){
						temp_W=b_W;				/*for store b_w value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[a_W][b_W]==word[z]){
													control_W++;				/*increasing control size*/
														}
									b_W--;
										}	
						if(control_W==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,a_W+1,temp_W+1,"W");				/*print word and coordinates to output file*/
										}
						b_W=temp_W;				/*stored b_w value after word search*/
						control_W=0;			/*reset control size*/
							}
						}

/*Search SOUTH Direction*/
	for(a_S=0; a_S<size_of_row; a_S++){
		for(b_S=0; b_S<k+size_of_word-1; b_S++){	
						temp_S=b_S;				/*for store b_s value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[b_S][a_S]==word[z]){
													control_S++;				/*increasing control size*/
				
														}
									b_S++;
										}
						if(control_S==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,temp_S+1,a_S+1,"S");				/*print word and coordinates to output file*/
										}
						b_S=temp_S;				/*stored b_s value after word search*/
						control_S=0;			/*reset control size*/	
							}
						}
/*Search NORTH Direction*/
	for(a_N=size_of_row; 0<=a_N; a_N--){		
		for(b_N=k+size_of_word-1; 0<=b_N; b_N--){
						temp_N=b_N;				/*for store b_n value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[b_N][a_N]==word[z]){
													control_N++;				/*increasing control size*/
										}
									b_N--;
										}
						if(control_N==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,temp_N+1,a_N+1,"N");				/*print word and coordinates to output file*/
										}
						b_N=temp_N;				/*stored b_n value after word search*/
						control_N=0;			/*reset control size*/
							}
						}
/*Search NORTH-EAST Direction*/
	for(a_NE=MAX_ROW; 0<=a_NE; a_NE--){		
		for(b_NE=0; b_NE<MAX_COLUMN; b_NE++){		
						temp1_NE=b_NE;				/*for store b_ne value if its equal word*/
						temp2_NE=a_NE;				/*for store a_ne value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[a_NE][b_NE]==word[z]){
													control_NE++;				/*increasing control size*/
													a_NE--;
													b_NE++;
														}
										}	
						if(control_NE==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,a_NE+1+control_NE,temp1_NE+1,"NE");		/*print word and coordinates to output file*/
										}	
						b_NE=temp1_NE;				/*stored b_ne value after word search*/
						a_NE=temp2_NE;				/*stored a_ne value after word search*/
						control_NE=0;			/*reset control size*/
							}
						}
/*Search NORTH-WEST Direction*/	
	for(a_NW=MAX_ROW; 0<=a_NW; a_NW--){	
		for(b_NW=MAX_COLUMN; 0<=b_NW; b_NW--){
						temp1_NW=b_NW;				/*for store b_nw value if its equal word*/
						temp2_NW=a_NW;				/*for store a_nw value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[a_NW][b_NW]==word[z]){
													control_NW++;				/*increasing control size*/
													a_NW--;
													b_NW--;
														}
										}	
						if(control_NW==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,a_NW+1+control_NW,temp1_NW+1,"NW");		/*print word and coordinates to output file*/
										}
						b_NW=temp1_NW;				/*stored b_nw value after word search*/
						a_NW=temp2_NW;				/*stored a_nw value after word search*/
						control_NW=0;			/*reset control size*/
							}
						}			
/*Search SOUTH-EAST Direction*/
	for(a_SE=0; a_SE<size_of_row; a_SE++){		
		for(b_SE=0; b_SE<k+size_of_word-1; b_SE++){
						temp1_SE=b_SE;				/*for store b_se value if its equal word*/
						temp2_SE=a_SE;				/*for store a_se value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[b_SE][a_SE]==word[z]){
													control_SE++;				/*increasing control size*/
													a_SE++;
													b_SE++;
														}
										}	
						if(control_SE==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,temp1_SE+1,a_SE+1-control_SE,"SE");		/*print word and coordinates to output file*/
										}
						b_SE=temp1_SE;				/*stored b_se value after word search*/
						a_SE=temp2_SE;				/*stored a_se value after word search*/
						control_SE=0;			/*reset control size*/
							}
						}
/*Search SOUTH-WEST Direction*/
	for(a_SW=0; a_SW<MAX_ROW; a_SW++){
		for(b_SW=MAX_COLUMN; 0<=b_SW; b_SW--){
						temp1_SW=b_SW;				/*for store b_sw value if its equal word*/
						temp2_SW=a_SW;				/*for store a_sw value if its equal word*/
						for(z=0; z<size_of_word; z++){
									if(arr_from_file[a_SW][b_SW]==word[z]){
													control_SW++;				/*increasing control size*/
													a_SW++;
													b_SW--;
														}
										}	
						if(control_SW==size_of_word){
								fprintf(fp3,"%s (%d,%d) %s\n",word,a_SW+1-control_SW,temp1_SW+1,"SW");		/*print word and coordinates to output file*/
										}
						b_SW=temp1_SW;				/*stored b_sw value after word search*/
						a_SW=temp2_SW;				/*stored a_sw value after word search*/
						control_SW=0;			/*reset control size*/
							}
						}
/*Ending Search Directions*/
		size_of_word=0;
		y=0;
		while(word[y]!=0){
				word[y]=0;		/*word array = 0*/
				y++;
				}
}
return 0;
}
