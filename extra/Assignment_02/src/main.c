#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "util.h"


int main() {
    	printf("## WELCOME TO Assignment 2          ##\n");			// for menu
	printf("## STUDENT NAME:ALPER TAVSANOGLU    ##\n");
	printf("## PLEASE SELECT FROM THE FOLLOWING ##\n");
	printf("## MENU:                            ##\n");
	int choice;
	do 									/*  do while for menu */
	{	
		printf("(1) Problem 1\n");					// for menu
		printf("(2) Problem 2\n");
		printf("(3) Problem 3\n");
		printf("(0) EXIT \n");
		printf("PLEASE SELECT FROM MENU:");				
		scanf("%d",&choice);	
		if(choice < 0 || choice >3 ){						//choice must be between 0 and 3
		printf("Invalid number.Please enter the numbers in MENU.\n");
		}
		switch(choice)								/*  switch for menu */
		{
			case 1: double PL,PW,SL,SW;
				int result,result2;
				printf("Please Enter Petal length (PL):\n");		
				scanf("%lf", &PL);					/*  take PL from user */
				printf("Please Enter Petal width (PW):\n");
				scanf("%lf", &PW);					/*  take PW from user */
				printf("Please Enter Sepal length (SL):\n");
				scanf("%lf", &SL);					/*  take SL from user */
				printf("Please Enter Sepal width (SW):\n");
				scanf("%lf", &SW);					/*  take SW from user */
				result = dt1a (PL,PW,SL,SW);				/* check decision tree*/
				result2 = dt1b (PL,PW,SL,SW);				/* check decision tree */
				if (result == result2){					/*  compare results */
				if( result == 1 ){					/*  if results are the same */
				printf("Both decision trees are the same. Answer is Setosa\n");
						}
				else if ( result == 2 ){
				printf("Both decision trees are the same. Answer is Virginica\n");
							}
				else if ( result == 3 ){
				printf("Both decision trees are the same. Answer is Versicolor\n");
							}
				}
				
				if(result != result2){				/*  if results are not the same */
				if( result == 1 ){				/*  check all possible nodes with if , else if */
				printf("The first decision tree for P1: Setosa\n");
						}
				else if ( result == 2 ){
				printf("The first decision tree for P1: Virginica\n");
							}
				else if ( result == 3 ){
				printf("The first decision tree for P1: Versicolor\n");
							}
				if ( result2 == 1 ){
				printf("The second decision tree for P1: Setosa\n");
						}
				else if ( result2 == 2 ){
				printf("The second decision tree for P1: Virginica\n");
							}
				else if ( result2 == 3 ){
				printf("The second decision tree for P1: Versicolor\n");
							}
				}			
				break;
				
			case 2: double x1,x2,x3;
				int x4,x5,result3,result4;
				printf("Please Enter Real Number 1 (x1):\n");
				scanf("%lf", &x1);						/*  take x1 from user */
				printf("Please Enter Real Number 2 (x2):\n");
				scanf("%lf", &x2);						/*  take x2 from user */
				printf("Please Enter Real Number 3 (x3):\n");
				scanf("%lf", &x3);						/*  take x3 from user */
				printf("Please Enter Binary Number 1 (x4):\n");
				scanf("%d", &x4);						/*  take x4 from user */
				if( x4 != 0 && x4 !=1 ){					/*  check binary number */
				printf("Binary Number must be 0 or 1 Please try again.\n");
				break;
				}
				printf("Please Enter Binary Number 2 (x5):\n");
				scanf("%d", &x5);						/*  take x5 from user */
				if( x5 != 0 && x5 !=1 ){					/*  check binary number */
				printf("Binary Number must be 0 or 1 Please try again.\n");
				break;
				}
				result3 = dt2a (x1,x2,x3,x4,x5);				/* check decision tree*/
				result4 = dt2b (x1,x2,x3,x4,x5);				/* check decision tree*/
				if( result3 == 1 ){						/*  check all possible nodes with if , else if */
				printf("The first decision tree for P2: 5.0\n");
				}
				else if( result3 == 2 ){
				printf("The first decision tree for P2: 2.1\n");
				}
				else if( result3 == 3 ){
				printf("The first decision tree for P2: -1.1\n");
				}
				else if( result3 == 4 ){
				printf("The first decision tree for P2: +1.4\n");
				}
				else if( result3 == 5 ){
				printf("The first decision tree for P2: -2.23\n");
				}
				else if( result3 == 6 ){
				printf("The first decision tree for P2: +11.0\n");
				}
				
				if( result4 == 7 ){					/*  check all possible nodes with if , else if */
				printf("The second decision tree for P2: -2.0\n");
				}
				else if( result4 == 8 ){
				printf("The second decision tree for P2: 1.01\n");
				}
				else if( result4 == 9 ){
				printf("The second decision tree for P2: -8\n");
				}
				else if( result4 == 10 ){
				printf("The second decision tree for P2: -1\n");
				}
				else if( result4 == 11 ){
				printf("The second decision tree for P2: -1/7\n");
				}
				else if( result4 == 12 ){
				printf("The second decision tree for P2: √2/3\n");
				}
				break;
				
			case 3:	int y1,y2,y3,result5,result6;
				double y4,y5;
				printf("Wedding Organization \n");
				printf("Choose one of the next 10 years\nFor 2023=0, 2024=1, 2025=2,  ...  2032=10\nPlease Enter The Year Of Your Choice:\n");		
				scanf("%d", &y1);														/*  take y1(categorical) from user */
				if( y1 != 0 && y1 !=1 && y1 !=2 && y1 !=3 && y1 !=4 && y1 !=5 && y1 !=6 && y1 !=7 && y1 !=8 && y1 !=9 && y1 !=10  ){
				printf("Please enter a number from 0 to 11 Please try again.\n");
				break;										//y2>=0 && y2<=10 i tried that but gives error for 1.5,2.6 etc.
				}
				printf("Choose which month you want\nFor January=0, February=1, March=2,  ...  December=11\nPlease Enter The Month You Want:\n");
				scanf("%d", &y2);														/*  take y2(categorical) from user */
				if( y2 != 0 && y2 !=1 && y2 !=2 && y2 !=3 && y2 !=4 && y2 !=5 && y2 !=6 && y2 !=7 && y2 !=8 && y2 !=9 && y2 !=10 && y2 !=11 ){	
				printf("Please enter a number from 0 to 11 Please try again.\n");
				break;										//y2>=0 && y2<=11 i tried that but gives error for 1.5,2.6 etc.
				}
				printf("Country Wedding or Wedding Hall\nFor Country Wedding = 0 , Wedding Hall = 1\nPlease Enter Country Wedding or Wedding Hall:\n");
				scanf("%d", &y3);														/*  take y3(binary) from user */
				if( y3 != 0 && y3 !=1 ){
				printf("Please enter 0 or 1 Please try again.\n");
				break;
				}
				printf("Please Enter How Many People Will Come:\n");
				scanf("%lf", &y4);														/*  take y4 from user */
				printf("Please Enter How Many People Will Come with Car:\n");
				scanf("%lf", &y5);														/*  take y5 from user */
				result5 = dt3a (y1,y2,y3,y4,y5);						/* check decision tree*/
				result6 = dt3b (y1,y2,y3,y4,y5);						/* check decision tree*/
				if( result5 == 1 ){								/*  check all possible nodes with if , else if */
				printf("The first decision tree for P3: $10.000\n");
				}
				else if( result5 == 2 ){
				printf("The first decision tree for P3: $15.000\n");
				}
				else if( result5 == 3 ){
				printf("The first decision tree for P3: $20.000\n");
				}
				else if( result5 == 4 ){
				printf("The first decision tree for P3: $22.000\n");
				}
				else if( result5 == 5 ){
				printf("The first decision tree for P3: $24.000\n");
				}
				else if( result5 == 6 ){
				printf("The first decision tree for P3: $26.000\n");
				}
				else if( result5 == 7 ){
				printf("The first decision tree for P3: $12.000\n");
				}
				else if( result5 == 8 ){
				printf("The first decision tree for P3: $17.000\n");
				}
				else if( result5 == 9 ){
				printf("The first decision tree for P3: $30.000\n");
				}
				else if( result5 == 10 ){
				printf("The first decision tree for P3: $32.000\n");
				}
				else if( result5 == 11 ){
				printf("The first decision tree for P3: $34.000\n");
				}
				else if( result5 == 12 ){
				printf("The first decision tree for P3: $36.000\n");
				}
				
				if( result6 == 1 ){						/*  check all possible nodes with if , else if */
				printf("The second decision tree for P3: $9.000\n");
				}
				else if( result6 == 2 ){
				printf("The second decision tree for P3: $13.000\n");
				}
				else if( result6 == 3 ){
				printf("The second decision tree for P3: $17.000\n");
				}
				else if( result6 == 4 ){
				printf("The second decision tree for P3: $19.000\n");
				}
				else if( result6 == 5 ){
				printf("The second decision tree for P3: $21.000\n");
				}
				else if( result6 == 6 ){
				printf("The second decision tree for P3: $23.000\n");
				}
				else if( result6 == 7 ){
				printf("The second decision tree for P3: $11.000\n");
				}
				else if( result6 == 8 ){
				printf("The second decision tree for P3: $27.000\n");
				}
				else if( result6 == 9 ){
				printf("The second decision tree for P3: $29.000\n");
				}
				else if( result6 == 10 ){
				printf("The second decision tree for P3: $31.000\n");
				}
				else if( result6 == 11 ){
				printf("The second decision tree for P3: $33.000\n");
				}
				else if( result6 == 12 ){
				printf("The second decision tree for P3: $35.000\n");
				}
				break;
				
			case 0: printf("End of the program.\n");		/*  if users input 0 exit */
				exit(0);
				break;
			default:
        			printf("invalid input");
           			break;
		}

	} while (choice != 0);					/*  if choice 0 exit */
    return 0;
}
