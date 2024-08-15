#include <stdio.h>
#include <string.h>
#include "util.h"


int main(){
	//////////////////////// PART 1 ////////////////////////////////
	int X,Y,Z,N;
	int result,result2;
	printf("Enter the first integer:");									/*  take first integer from user */
	scanf("%d",&X);
	printf("Enter the second integer:");									/*  take second integer from user */
	scanf("%d",&Y);
	printf("Enter the divisor:");										/*  take divisor from user */
	scanf("%d",&Z);
	result = find_divisible( X, Y, Z);									/* check integer between X and Y can be divided by Z */
	if(result ==-1){
	printf("There is not any integer between %d and %d can be divided by %d\n",X,Y,Z);
	}
	else{	
	printf("The first integer between %d and %d divided by %d is %d\n",X,Y,Z,result);
	printf("Enter the number how many next:");								/*  take  how many next from user */
	scanf("%d",&N);
	result2 = find_nth_divisible(N,result,Z);								/* check integer Nth number between X and Y can be divided by Z */
	
	if(result2 ==-1 || result2>Y){
	printf("There is not any integer between %d and %d can be divided by %d\n",X,Y,Z);				 /* print output */
	
		}
	else{
	printf("The %d. integer between %d and %d divided by %d is %d\n",N+1,X,Y,Z,result2);				/* print output */
		}
	}
	///////////////////// PART 2 //////////////////
	char identity_number [12];
	int password;
	int recorder;
	printf("Enter your identity number:");					/*  take identity number from user */
	scanf("%s",identity_number);
	recorder=validate_identity_number( identity_number );			/* check identity number true */
	if(recorder==0){
	printf("Invalid identity number \n");
	return 0;
	}
	printf("Enter your password:");						/*  take password from user */
	scanf("%d",&password);
	char str[5];
	int i;
	sprintf(str, "%d", password);						/* int to string */
	if(strlen(str)!=4){							/* check password 4 digits and dont start with 0 */
		printf("Password must be 4 digits\n");
			return 0;
			}
	for(i=0;i<=4;i++){							
 		if((str[i]<=48&&str[i]>=57)){					/* check each digit must be a digit */
 			printf("Password must be digits\n");
 			return 0;
		}
	}
	create_customer( identity_number ,  password);				/* create customer.txt */

	///////////////////// PART 3 /////////////////////
	char check_identity_number [12];
	int  check_password;
	int check;
	printf("Enter your identity number:");					/*  take identity number from user */
	scanf("%s",check_identity_number);
	printf("Enter your password:");						/*  take password from user */
	scanf("%d",&check_password);
	check=check_login( check_identity_number , check_password);		/* check identity number and password are equal with customer.txt */
	if(check==0){
	return 0;
	}
	float cash;
	printf("Enter your withdraw amount:");					/* money user's want */
	scanf("%f",&cash);
	withdrawable_amount(cash);						/* how much money can be given */

	return 0;
}

