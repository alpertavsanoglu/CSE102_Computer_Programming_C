#include <stdio.h>

#define classes 10		/*easy way for trying different number of samples */
#define EPSILON 0.001		/*value for divide-by-zero situations */

int mid_x_finder(double avg1_x,double avg2_x);		/*function for finding x's midpoint */

int mid_y_finder(double avg1_y,double avg2_y);		/*function for finding y's midpoint */

void print_class(double sepline_slope,double mid_x,double mid_y,double avg1_x,double avg2_x,double avg1_y,double avg2_y);		/*function for print testpoint's class*/

int main(){

int i=0;

double x,y;

double sum1_x=0,sum1_y=0,sum2_x=0,sum2_y=0;		/* variables for sum classes */

double avg1_x=0,avg1_y=0,avg2_x=0,avg2_y=0;		/* variables for average of classes */

double mid_x=0,mid_y=0,slope=0,sepline_slope=0;		/* variables for midpoint and slope */


for(i=0;i<classes;i++){					/* Get class1 coordinates from user */

			if((scanf("%lf",&x)!=1) || (scanf("%lf",&y))!=1){			/* User enters something not expected Program quits */
									return 0;
									}
			sum1_x= x+sum1_x;		/* sum x points for class1 */
			sum1_y= y+sum1_y;		/* sum y points for class1 */
			}

	avg1_x=sum1_x/classes;		/*avg point of x for class1*/
	avg1_y=sum1_y/classes;		/*avg point of y for class1*/



for(i=0;i<classes;i++){					/* Get class1 coordinates from user */

			if((scanf("%lf",&x)!=1) || (scanf("%lf",&y))!=1){			/* User enters something not expected Program quits */
									return 0;
									}
			sum2_x= x+sum2_x;		/* sum x points */
			sum2_y= y+sum2_y;		/* sum y points */
			}

	avg2_x=sum2_x/classes;		/*avg point of x for class1*/
	avg2_y=sum2_y/classes;		/*avg point of y for class1*/


mid_x=mid_x_finder( avg1_x, avg2_x);		/*finding midpoint of x with function returns*/
mid_y=mid_y_finder( avg1_y, avg2_y);		/*finding midpoint of y with function returns*/



		if(avg2_x-avg1_x == 0){							/* if the divider is 0 make it 0+000.1 with macro*/
					slope=(avg2_y-avg1_y)/((avg2_x-avg1_x)+EPSILON);
					}
		else{
			slope=(avg2_y-avg1_y)/(avg2_x-avg1_x);				/* finding slope */
			}

			if(slope==0){							/* if the divider is 0 make it 0+000.1 with macro*/
					slope+=EPSILON;
					}
sepline_slope=-1/slope;									/* fing sepline slope*/

print_class(sepline_slope, mid_x, mid_y, avg1_x, avg2_x, avg1_y, avg2_y);	/*finding testpoint classes with function*/

return 0;
}

int mid_x_finder(double avg1_x,double avg2_x){		/*function for finding x's midpoint */

double mid_x=0;

mid_x=(avg1_x+avg2_x)/2;	/*find midpoint value*/

return mid_x;		/*return midpoint value*/
}

int mid_y_finder(double avg1_y,double avg2_y){		/*function for finding y's midpoint */

double mid_y=0;

mid_y=(avg1_y+avg2_y)/2;	/*find midpoint value*/

return mid_y;		/*return midpoint value*/
}

void print_class(double sepline_slope,double mid_x,double mid_y,double avg1_x,double avg2_x,double avg1_y,double avg2_y){		/*function for print testpoint's class*/

double test_point_x=0,test_point_y=0;

while(scanf("%lf %lf",&test_point_x,&test_point_y)==2){			/* User enters something not expected Program quits */

	if((test_point_y-mid_y)>(sepline_slope*(test_point_x-mid_x)))		  /* checked the location of the test point */
	{

		if(avg1_y-mid_y > (sepline_slope*(avg1_x-mid_x))){
								printf("class 1\n");
								}

		else{
									printf("class 2\n");
									}
	}

	if((test_point_y-mid_y)<(sepline_slope*(test_point_x-mid_x)))		  /* checked the location of the test point */
	{

		if(avg1_y-mid_y < (sepline_slope*(avg1_x-mid_x))){
								printf("class 1\n");
								}

		else{
									printf("class 2\n");
									}
	} 
test_point_x=0,test_point_y=0;
	}
}
