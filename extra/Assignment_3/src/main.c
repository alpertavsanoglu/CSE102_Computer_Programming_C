#include <stdio.h>
#include <math.h>

//part1
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);

//part2
int isprime(int a);

//part3
void write_file(int number);
void sort_file();
void print_file();

// for menu
void choice1();
void choice2();
void choice3();
void choice4();

int main()
{

	// Menu.
	printf("## WELCOME TO Assignment 3          ##\n");
	printf("## STUDENT NAME:ALPER TAVSANOGLU    ##\n");
	printf("## PLEASE SELECT FROM THE FOLLOWING ##\n");
	printf("## MENU:                            ##\n");
	printf("Select operation\n");
	printf("1. Calculate sum/multiplication between two numbers.\n");
	printf("2. Calculate prime numbers.\n");
	printf("3. Show number sequence in file.\n");
	printf("4. Sort number sequence in file.\n");
	printf("----------------------------------------------------\n");

	int select_menu;
	scanf("%d", &select_menu);

	switch (select_menu)
	{
	case 1:		//if value is 1
		choice1();
		break;
	case 2:		//if value is 2
		choice2();
		break;
	case 3:		//if value is 3
		choice3();
		break;
	case 4:		//if value is 4
		choice4();
		break;
	default:	//if value is not from menu
		printf("Please enter a number from menu.\n");
		break;
	}

	return 0;

}

void choice1()
{
	FILE* files;				//file operation
	int choice,num1,num2,check,result=0;

	files = fopen("results.txt", "at");	//open file

	printf("Select operation.\n");
	printf("Please enter '0' for sum, '1' for multiplication.\n");
	scanf("%d", &choice);						//taken from user
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
	scanf("%d", &check);						//taken from user
	printf("Please enter two different numbers.\n");
	printf("Number 1: ");
	scanf("%d", &num1);						//taken from user
	printf("Number 2: ");
	scanf("%d", &num2);						//taken from user

	if (check == 0 || check == 1)			//if check value is invalid, prints error message.
	{
		if (choice == 0 || choice == 1)		//if choice value is invalid, prints error message.
		{
			if (num1 < num2)		//num2 must be greater than number 1
			{
				switch (choice)
				{
				case 0:		//if value is 0
					result = sum(num1, num2, check);
					break;
				case 1:		//if value is 1
					result = multi(num1, num2, check);
				default:	//if value is invalid
					break;
				}
				fprintf(files, "%d ", result);
				printf("The result is written to the results.txt file.\n");
				fclose(files);		//close file
			}
			else
			{
				printf("number2 must be grater than number1 \n");
			}
		}
		else
		{
			printf("Please enter 0 or 1\n");
		}
	}
	else
	{
		printf("Please enter 0 or 1 \n");
	}
}

int multi(int n1, int n2, int flag)
{
	int total = 1;

	printf("Result\n");

	for (int i = n1 + 1; i < n2; i++)		//check range
	{

		if (i % 2 == flag)			//mod2 equal flag
		{
			printf("%d ", i);

			if (i + 1 == n2 || i + 2 == n2)
			{
				printf( " = ");
			}
			else
			{
				printf("* ");
			}

			total *= i;
		}
	}
	printf("%d\n", total);
	return total;
}

int sum(int n1, int n2, int flag)
{
	int total = 0;

	printf("Result\n");

	for (int i = n1 + 1; i < n2; i++)		//check range
	{
		if (i % 2 == flag)			//mod2 equal flag
		{
			printf("%d ", i);

			if (i + 1 == n2 || i + 2 == n2)
			{
				printf(" = ");
			}
			else
			{
				printf(" + ");
			}

			total += i;
		}
	}
	printf("%d\n", total);
	return total;
}



void choice2()
{
	int max,i,check;

	printf("Please enter an integer: ");
	scanf("%d", &max);

	if (max > 1)
	{
		for (i = 2; i< max; i++)
		{
			check = isprime(i);

			if (check == 1)
			{
				printf("%d is a prime number.\n", i);
			}
			else
			{
				printf("%d is not a prime number, it is divisible by %d.\n", i, check);
			}
		}
	}
	else
	{
		printf("Please enter bigger than 1!\n");
	}
}

int isprime(int a)
{
	int check,i,total=1;

	check = (int)sqrt(a);

	for (i = check; i >= 2; i--)
	{
		if (a % i == 0)
		{
			total = i;
		}
	}

	return total;
}

void write_file(int number)
{
	FILE* file;
	
	file = fopen("results.txt", "at");

	fprintf(file, "%d ", number);

	fclose(file);
}

void choice3()
{
	print_file();
}
void print_file()
{
	FILE* file;
	int i = 0, j;

	file = fopen("results.txt", "rt");		//open file

	do
	{
		i = fscanf(file, "%d", &j);		//read from file
		if (i != -1)				//check true or false
		{
			printf("%d ", j);
		}

	} while (i > 0);
	fclose(file);					//close file
}



void choice4()
{
	sort_file();
}
void sort_file()
{
	int top = 2147483647; //Value from limits.h
	
	int min1,min2,min3,check,temp;
	
	FILE* file;
	FILE* temporary1;
	FILE* temporary2;

	temporary1 = fopen("results_copied.txt", "wt");
	fclose(temporary1);					//close file
	temporary2 = fopen("results_sorted.txt", "wt");
	fclose(temporary2);					//close file

			do
				{
				min1 = top;
				min2 = top;
				min3 = top;
				check = 0;

				{
					file = fopen("results.txt", "rt");		// open file 

				do
				{
						check = fscanf(file, "%d", &temp);		//check number 3by3

							if (check != -1)
							{
							if (temp < min1)
							{
								min3 = min2;
								min2 = min1;
								min1 = temp;
							}
							else if (temp < min2)
							{
								min3 = min2;
								min2 = temp;
							}
							else if (temp < min3)
							{
								min3 = temp;
							}
							}	

						} while (check > 0);

						fclose(file);		//close file
				}

				{
				check = 0;
				temp;
				file = fopen("results.txt", "rt");		//open file

				temporary1 = fopen("results_copied.txt", "wt");		// open file

				do
					{
					check = fscanf(file, "%d", &temp);

					if (check != -1)

					{
					if (temp != min1 && temp != min2 && temp != min3)
					{
						fprintf(temporary1, "%d ", temp);
					}
					}

					} while (check > 0);
			
					fclose(file);		//close file
					fclose(temporary1);		//close file
					check = 0;
					temp;
					file = fopen("results.txt", "wt");		//open file
					temporary1 = fopen("results_copied.txt", "rt"); // open file

					do
					{
						check = fscanf(temporary1, "%d", &temp);

						if (check != -1)
						{
							fprintf(file, "%d ", temp);
						}

					} while (check > 0);

					fclose(file);		//close file
					fclose(temporary1);	//close file
					}

					{
					temporary2 = fopen("results_sorted.txt", "at");  // open file

					if (min1 != top)
					{
						fprintf(temporary2, "%d ", min1);
					}
		
					if (min2 != top)
					{
						fprintf(temporary2, "%d ", min2);
					}

					if (min3 != top)
					{
						fprintf(temporary2, "%d ", min3);
					}

					fclose(temporary2);		// close file
					}

					} while (min1 != top || min2 != top || min3 != top);

					check = 0;
					temp;

					file = fopen("results.txt", "wt");		//open file

					temporary2 = fopen("results_sorted.txt", "rt");		//copy

					do
					{						//read number from file
					check = fscanf(temporary2, "%d", &temp);

					if (check != -1)
					{							//copy them to a different file.
					if (temp != min1 && temp != min2 && temp != min3)
					{
						fprintf(file, "%d ", temp);
					}
					}

					} while (check > 0);

					fclose(file);			//close file
					fclose(temporary2);		//close file

					printf("Sorting is complete.\nResult:\n");
					print_file();
}
