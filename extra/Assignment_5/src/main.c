#include <stdio.h>					//libraries
#include <stdlib.h>
#include <math.h>

#define PI 3.14                                                                 //define PI

enum Shapes {Triangle=1, Quadrilateral, Circle, Pyramid, Cylinder, Exit=0};	//enumerated types
enum Calculators {Area=1, Perimeter, Volume, Exit_2=0};				//enumerated types

			//Functions
int select_shape ();
int select_calc ();
int calculate (int (*a)(),int(*b)());
int calc_triangle(int triangle);
int calc_quadrilateral(int quadrl);
int calc_circle(int circle);
int calc_pyramid(int pyramid);
int calc_cylinder(int cylinder);


int main(){
printf("Welcome to the geometric calculator!\n");
calculate(select_shape,select_calc);				// The calculate function with select_shape() and select_calc() functions as parameters


return 0;
}

int select_shape (){						//Select a shape function

	int selection_shape;
	
do{
	
	printf("\nSelect a shape to calculate:\n");		//Select a shape MENU
	printf("------------------------------\n");
	printf("1. Triangle\n");
	printf("2. Quadrilateral\n");
	printf("3. Circle\n");
	printf("4. Pyramid\n");
	printf("5. Cylinder\n");
	printf("0. Exit\n");
	printf("------------------------------\n");
	printf("Input :");
	
	
	if(scanf("%d",&selection_shape) != 1){				//check  character error 
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");	//print error
		continue;
	}
	else if(selection_shape == Triangle || selection_shape == Quadrilateral || selection_shape == Circle || selection_shape == Pyramid || selection_shape == Cylinder || selection_shape == Exit)
	{									//check value is true
	break;
	}
	else {
	        while(getchar() != '\n' );					//check  character error 
		printf("\nERROR ! Please enter a valid entry.\n");		//print error
		continue;
	}
	}while (1);								//do while for loop
	
	return selection_shape;							// return selection_shape choice
	}
	
int select_calc (){				//Select calculator function
		int selection_calcuator;
		
do{
		printf("\nSelect calculator:\n");			//Select calculator MENU
		printf("------------------------------\n");
		printf("1. Area\n");
		printf("2. Perimeter\n");
		printf("3. Volume\n");
		printf("0. Exit\n");
		printf("------------------------------\n");
		printf("Input :");	
		
		if(scanf("%d",&selection_calcuator) != 1){		//check  character error 
			while(getchar() != '\n' );
			printf("\nERROR ! Please enter a valid entry.\n");		//print error
			continue;
		}
		else if (selection_calcuator == Area || selection_calcuator == Perimeter || selection_calcuator ==  Volume || selection_calcuator == Exit_2 )		//check value is true
		{
		break;
		}
		else {
			while(getchar() != '\n' );					//check  character error 
			printf("\nERROR ! Please enter a valid entry.\n");		//print error
			continue;
			}
		}while (1);
		
		return selection_calcuator;				//return selection_calcuator choice
		}
	
int calculate (int (*a)(), int (*b)()){				
int first,second;

do{
first=select_shape();						//equate the retun from the shape function to first
if(first == 0) break;

second=select_calc();						//equate the return from the calculate function to second
if(second == 0) break;

switch(first)							//switch case for shape MENU
{
case Triangle: calc_triangle(second);				//for triangle
	break;
case Quadrilateral: calc_quadrilateral(second);			//for quadrilateral
	break;
case Circle: calc_circle(second);				//for circle
	break;
case Pyramid: calc_pyramid(second);				//for pyramid
	break;
case Cylinder: calc_cylinder(second);				//for cylinder
	break;

}

	}while(1);

return 0;
}


int calc_triangle(int triangle){			// triangle function
	float k1,k2,k3;
	float s,p,area;
switch(triangle)					//choice Area or perimeter or volume
{
case Area: printf("Please enter three sides of Triangle:\n\n");		//for area
	do{
	if(scanf("%f",&k1) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k2) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k3) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(k1<=0 || k2<=0 || k3<=0){				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if((k1 + k2 > k3) && (k2 + k3 > k1) && (k3 + k1 > k2)){	//check invalid triangle error
		s=(k1+k2+k3)/2;
		area=sqrt(s*(s-k1)*(s-k2)*(s-k3));			// find area
		printf("\nArea of TRIANGLE : %.2f\n",area);		//print area
		break;
	}
	else {
		printf("\nERROR ! Please enter a valid triangle.\n");
		continue;
	}
	}while (1);
	break;

case Perimeter: printf("Please enter three sides of Triangle:\n\n");	//for perimeter
	do{
	if(scanf("%f",&k1) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k2) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k3) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(k1<=0 || k2<=0 || k3<=0){				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if((k1 + k2 > k3) && (k2 + k3 > k1) && (k3 + k1 > k2)){	//check invalid triangle error
		p=k1+k2+k3;						//find perimeter
		printf("Perimeter of TRIANGLE : %.2f\n",p);		//print perimeter
		break;
	}
	else {
		printf("\nERROR ! Please enter a valid triangle.\n");	//print error
		continue;
	}
	}while (1);
	break;


case Volume: printf("\nERROR ! You cannot calculate the volume of a triangle.Please try again.\n\n");		//for volume
	break;

}
return 0;
}


int calc_quadrilateral(int quadrl){			// quadrilateral function
	float k1,k2,k3,k4;
	float s,area,p;

switch(quadrl)						//choice Area or perimeter or volume
{
case Area: printf("Please enter four sides of Quadrilateral:\n\n");	////for Area
	do{
	if(scanf("%f",&k1) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k2) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k3) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k4) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(k1<=0 || k2<=0 || k3<=0){				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		s=(k1+k2+k3+k4)/2;
		area=sqrt((s-k1)*(s-k2)*(s-k3)*(s-k4));			//find area
		printf("\nArea of Quadrilateral : %.2f\n",area);	//print area
		break;
	}
	}while (1);
	break;
	
case Perimeter: printf("Please enter four sides of Quadrilateral:\n\n");	//for perimeter
	do{
	if(scanf("%f",&k1) != 1){						//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k2) != 1){						//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k3) != 1){						//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&k4) != 1){						//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(k1<=0 || k2<=0 || k3<=0){					//check invalid number error
		printf("\nPlease enter a valid entry.\n");
		continue;
	}
	else{
		p=k1+k2+k3+k4;							//find perimeter
		printf("\nPerimeter of Quadrilateral : %.2f\n",p);		//print perimeter
		break;
	}
	}while (1);
	break;

case Volume: printf("\nERROR ! You cannot calculate the volume of a quadrilateral.Please try again.\n\n");		// for volume
	break;
}
return 0;
}


int calc_circle(int circle){					// circle function
	float radius;
	float p,area;
switch(circle)								//choice Area or perimeter or volume
{
case Area: printf("Please enter the radius  of a Circle:\n\n");
	do{
	if(scanf("%f",&radius) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(radius<=0 ) {						//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		area=PI*radius*radius;					//find area
		printf("\nArea of Circle : %.2f\n",area);		//print area
		break;
	}
	}while (1);
	break;

case Perimeter: printf("Please enter the radius  of a Circle:\n\n");
	do{					
	if(scanf("%f",&radius) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(radius<=0 ) {						//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		p=2*PI*radius;						//find perimeter
		printf("\nPerimeter of Circle : %.2f\n",p);		//print perimeter
		break;
	}
	}while (1);
	break;
	
case Volume: printf("\nERROR ! You cannot calculate the volume of a Circle.Please try again.\n\n");		// for volume
	break;
}
return 0;
}


int calc_pyramid(int pyramid){								// pyramid function
	float base_side,height,slant_height;
	float base_circumference,volume,base_surface,lateral_surface,surface;
switch(pyramid)										//choice Area or perimeter or volume
{
case Area: printf("Please enter the base side and slant height of a Pyramid:\n\n");
	do{
	if(scanf("%f",&base_side) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&slant_height) != 1){				//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(base_side<=0 || slant_height<=0 ) {				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		base_surface=(base_side)*(base_side);						//find base_surface
		lateral_surface=2*(base_side)*(slant_height);					//find lateral_surface
		surface=(base_surface)+(lateral_surface);					//find surface
		printf("\nBase Surface Area of a PYRAMID : %.2f\n",base_surface);				//print base_surface
		printf("\nLateral Surface Area of a PYRAMID : %.2f\n",lateral_surface);				//print lateral_surface
		printf("\nSurface Area of a PYRAMID : %.2f\n",surface);						//print surface
		break;
	}
	}while (1);
	break;
	
case Perimeter: printf("Please enter the base side of a Pyramid:\n\n");		//for perimeter
	do{
	if(scanf("%f",&base_side) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(base_side<=0 ){							//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		base_circumference=base_side+base_side+base_side+base_side;		//find perimeter
		printf("\nBase Circumference of PYRAMID : %.2f\n",base_circumference);	//print perimeter
		break;
	}
	}while (1);
	break;
	
case Volume: printf("Please enter the base side and height of a Pyramid:\n\n");
	do{
	if(scanf("%f",&base_side) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&height) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(base_side<=0 || height<=0 ) {					//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		volume=((base_side)*(base_side)*(height))/3;			//find volume
		printf("\nVolumme of PYRAMID : %.2f\n",volume);			//print volume
		break;
	}
	}while (1);
	break;
}
return 0;
}


int calc_cylinder(int cylinder){						//cylinder function
	float radius,height;
	float volume,p,base_surface,lateral_surface,surface;
switch(cylinder)								//choice Area or perimeter or volume
{
case Area: printf("Please enter the radius and height of a Cylinder:\n\n");
	do{
	if(scanf("%f",&radius) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&height) != 1){				//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(radius<=0 || height<=0 ){				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		base_surface=PI*radius*radius;							//find base_surface
		lateral_surface=2*PI*radius*height;						//find lateral_surface
		surface=2*PI*radius*(radius+height);						//find surface
		printf("\nBase Surface Area of a CYLINDER : %.2f\n",base_surface);					//print base_surface
		printf("\nLateral Surface Area of a CYLINDER : %.2f\n",lateral_surface);				//print base_surface
		printf("\nSurface Area of a CYLINDER : %.2f\n",surface);						//print base_surface
		break;
	}
	}while (1);
	break;
	
case Perimeter: printf("Please enter the radius and height of a Cylinder:\n\n");		//for perimeter
	do{
	if(scanf("%f",&radius) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&height) != 1){				//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(radius<=0 || height<=0 ) {				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		p=2*PI*radius;								//find perimeter
		printf("\nBase Surface Perimeter of a CYLINDER : %.2f\n",p);		//print perimeter
		break;
	}
	}while (1);
	break;
	
case Volume: printf("Please enter the radius and height of a Cylinder:\n\n");		// for volume
	do{
	if(scanf("%f",&radius) != 1){					//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(scanf("%f",&height) != 1){				//check character error
		while(getchar() != '\n' );
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else if(radius<=0 || height<=0 ) {				//check invalid number error
		printf("\nERROR ! Please enter a valid entry.\n");
		continue;
	}
	else{
		volume=PI*radius*radius*height;					//find volume
		printf("\nVolume of a CYLINDER : %.2f\n",volume);		//print volume
		break;
	}
	}while (1);
	break;
}
return 0;
}
