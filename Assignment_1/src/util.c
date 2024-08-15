#include <stdio.h>
#include <string.h>
#include "util.h"

 int find_divisible(int x, int y, int z) {
 	
 	int i,result;
 
 	if(x>y) return -1;						/* second integer must be bigger than first */
 
 	for(i=x;i<y;i++){
 	
 	if(i%z==0){							/* if there is integer between X and Y can be divided by Z return i */
 	return i; 
 	}
 	}
 	return -1;
}
 int find_nth_divisible(int n, int f_I, int z){
 
 	int i,counter=0;
 
 	while(1){
 	
 	if(f_I%z==0 && counter==n){					/* if there is Nth integer between X and Y can be divided by Z return f_I */
 	
 	return f_I;
 	}
 	if(f_I%z==0){							/* find all integer between X and Y can be divided by Z */
 	counter++;
 	}
 	f_I+=z;
 	}
 return -1;
}
 int validate_identity_number(char identity_number []){
	
 	int i,recorder=1;
 	int identity_confirm[12];
 	int sum1=0,sum2=0,sum3=0;
 	
 	 if(strlen(identity_number)!=11){				/* Check TR Identity Numbers 11 characters */
 		recorder=0;
 		}
 	for(i=0;i<=10;i++){						/* Check each digit must be a digit */
 	if(!(identity_number[i]>=48&&identity_number[i]<=57)){		/* 0-9 ,48-57 in ascii table  */
 		recorder=0;
 		}
 	}
 	if(identity_number[0]=='0'){					/* Check the first digit cannot be 0 */
 		recorder=0;
 		}
	for(i=0;i<=10;i++){						
	identity_confirm[i]=identity_number[i]-'0';			/* string to int easy way */
	}
	for(i=0;i<=8;i++){
	if(i%2==0){
			sum1 += identity_confirm[i]*7 ;			/* 7 times the sum of the digits 1, 3, 5, 7, 9 */
	}
	else{
			sum2 += identity_confirm[i];			/* the sum of the digits 2, 4, 6, 8 */
 	}
 	}
 	if(identity_confirm[9]!=(sum1-sum2)%10){			/* Check 4th rule */
 		recorder=0;
 		}
 	for(i=0;i<=9;i++){
 			sum3 += identity_confirm[i];			/* the sum of the first 10 digits */
 			}
 	if(identity_confirm[10]!=(sum3)%10){				/* Check 5th rule */ 
 		recorder=0;
 		}
 	return recorder;
}
 int create_customer(char identity_number [], int password){			/* creating file */
	FILE *fp1;								
	if(fp1=fopen("customeraccount.txt","w")){				/* opening file */
		fprintf(fp1,"%s,%d",identity_number,password);			/* information saved into the file */
		fclose(fp1);							/* closing file */
		printf("Customer created\n");
		}
	else
		printf(" Error creating file ");
}
int check_login(char identity_number [], int password){
	int check=1;
	int password_file;
	char identity_number_file[12];
	
 	FILE *fp1=fopen("customeraccount.txt","r");								/* opening file */
 	
 		fscanf(fp1,"%11[^,],%d",identity_number_file,&password_file);					/* information taken from the file */
 		fclose(fp1);											/* closing file */
		if(strcmp(identity_number,identity_number_file)==0 && password==password_file){			/* information received from the user and read from the file are equal */
		printf("Login Successful\n");
		}
		else{
		printf(" Invalid identity number or password\n ");						/* information received from the user and read from the file are not equal */
		check=0;
		}
		return check;
}
int withdrawable_amount(float cash_amount){
	float remainder;
	int store;
	store=(int)cash_amount;						/* float to int */
	remainder=store%10;						/* mod 10 */
	if(remainder>0){
	cash_amount=store+(-remainder);					/* withdrawable amount */
	}
	printf("Withdrawable amount is:%.0f\n",cash_amount);

}
