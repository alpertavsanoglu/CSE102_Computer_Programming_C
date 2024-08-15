#include <stdio.h>




int main(){
    	printf("## WELCOME TO Assignment 4          ##\n");			// for menu
	printf("## STUDENT NAME:ALPER TAVSANOGLU    ##\n");
	printf("## PLEASE SELECT FROM THE FOLLOWING ##\n");
	printf("## MENU:                            ##\n");
	int select_menu=0;



while(select_menu !=4){
			
	printf("\nSelect an operation...\n");
	printf("1 -> Enter the coefficients. \n");
	printf("2 -> Draw the graph.\n");
	printf("3 -> Print the graph into a . txt file.\n");
	printf("4 -> Exit.\n");
	printf("\n\nChoice:");
	scanf("%d",&select_menu);
	if(select_menu < 0 || select_menu >4 )
	{								//choice must be between 0 and 3
	printf("Invalid number.\n");
	}
	switch (select_menu)
	{
	case 1:		//if value is 1
		int a,b,c;
		printf("\n Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c \n\n");
		printf("a: ");
		scanf("%d",&a);			//taken from user
		printf("b: ");
		scanf("%d",&b);			//taken from user
		printf("c: ");
		scanf("%d",&c);			//taken from user
		FILE* files;			//file operation
		files = fopen("coefficients.txt", "wt");		//open file
		fprintf(files, "%d\n", a);				//print file
		fprintf(files, "%d\n", b);				//print file
		fprintf(files, "%d\n", c);				//print file
		printf("\ncoefficients.txt file has been created.\n");		
		fclose(files);		//close file
		break;
		
	case 2:		//if value is 2
		int a1,b1,c1;
		FILE* files_2;
		files_2 = fopen("coefficients.txt", "r");			
		if(files_2==NULL)					// check file is created or not
		{
			printf("\nThe file is not present\n");
			break;
		}
		else
		{
			while(!feof(files_2))
			{
				fscanf(files_2,"%d\n%d\n%d\n",&a1,&b1,&c1);					//taken from file
				printf("\n\nCoefficients has been read from the coefficient.txt file.\n");
				printf("Printing the graph of x=%d*(y*y) + %d*y + %d\n",a1,b1,c1);
			}
				fclose(files_2);

		int loop_1,loop_2;
		int equation;
		for(loop_1=15;loop_1!=-16;loop_1--)
		{
			for(loop_2=-50;loop_2<=50;loop_2++)
			{		
				equation=a1*loop_1*loop_1 + b1*loop_1 + c1;
				if(loop_2==equation){					//check equation for print #
						printf("\033[0;36m");			// for color
						printf("#");
						printf("\033[0m");			// for color
						}
						else
						{
							if(loop_2==0)
							{
								printf("|");		//for y axis
							}
						else
						{
							if(loop_1==0)
							{
								printf("-");		//for x axis
							}
						else
						{
							if(loop_2==3 && loop_1%5==0)
							{
								printf("\033[0;33m");		// for color
								printf("%d",loop_1);
								printf("\033[0m");		// for color
								if(loop_1>=10 || loop_1==-5)
								{
									loop_2++;
								}
								else
								{
									if(loop_1!=5)loop_2=loop_2+2;
								}
							}
								else
								{
									if(loop_1==-1 && loop_2%10==0)
									{
										printf("\033[0;33m");		// for color
										printf("%d",loop_2);
										printf("\033[0m");		// for color
										if(loop_2<0)
										{
											loop_2=loop_2+2;
										}
										else
										{
											loop_2++;
										}
									}
									else
									{
										printf(" ");
									}
								}
						}
						}
						}
			}
				printf("\n");
		}
		}
		break;
		
	case 3:		//if value is 3 
		int a2,b2,c2;
		FILE* files_3;
		files_3 = fopen("coefficients.txt", "r");
		if(files_3==NULL)					// check file is created or not
		{
			printf("\nThe file is not present\n");
			break;
		}
		else
		{
			while(!feof(files_3))
			{
				fscanf(files_3,"%d\n%d\n%d\n",&a2,&b2,&c2);					//taken from file
				printf("\n\nCoefficients has been read from the coefficient.txt file.\n");
				printf("The graph of x=%d*(y*y) + %d*y + %d has been written to graph.txt file\n",a2,b2,c2);
			}
				fclose(files_3);		//close file
		FILE* files_4;
		files_4 = fopen("graph.txt", "wt");
		int loop_3,loop_4;
		int equation_2;
		for(loop_3=15;loop_3!=-16;loop_3--)			//loop for plane
		{
			for(loop_4=-50;loop_4<=50;loop_4++)		//loop for plane
			{		
				equation_2=a2*loop_3*loop_3 + b2*loop_3 + c2;	
					
				if(loop_4==equation_2){				//check equation for print #
						fprintf(files_4,"#");		//print file
						}
						else
						{
							if(loop_4==0)
							{
								fprintf(files_4,"|");		// for y axis		//print file
							}
						else
						{
							if(loop_3==0)
							{
								fprintf(files_4,"-");		//for x axis		//print file
							}
						
									else
									{
										fprintf(files_4," ");		//print file
									}
								}
						}
						}
						
			
				fprintf(files_4,"\n");		//print file
		}		
				
				
				
			fclose(files_4);		//close file
			}	
				
				break;
	case 4:		//if value is 4
				
				break;
	default:	//if value is not from menu
			printf("Please enter a number from menu.\n");
				break;
			}
		}
		
	return 0;
}
