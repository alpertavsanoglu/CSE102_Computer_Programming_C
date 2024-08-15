#include <stdio.h>
#include <math.h> 
#include "util.h"

char dt1a(double PL, double  PW, double SL, double  SW) {
	int r = 0;
	if ( PL < 2.45) r = 1;								/*  check all possible nodes with if , else if */
	else if (PL >= 2.45 && PW >= 1.75) r = 2;
	else if (PL >= 2.45 && PW < 1.75 && PL >= 4.95) r = 2;
	else if (PL >= 2.45 && PW < 1.75 && PL < 4.95 && PW >= 1.65) r = 2;
	else if (PL >= 2.45 && PW < 1.75 && PL < 4.95 && PW < 1.65) r = 3;
	return r;
}

char dt1b(double PL, double  PW, double SL, double  SW) {
	int r = 0;
	if (PL < 2.55) r=1;								/*  check all possible nodes with if , else if */
	else if (PL >= 2.55 && PW >= 1.69) r = 2;
	else if (PL >= 2.55 && PW < 1.69 && PL >= 4.85) r = 2;
	else if (PL >= 2.55 && PW < 1.69 && PL < 4.85) r = 3;
	return r;
}

double dt2a(double x1,double x2,double x3,int x4,int x5){
	int r = 0;
	if (x1 < 31.5 && x2 > -2.5) r = 1;						/*  check all possible nodes with if , else if */
	else if (x1 < 31.5 && x2 <= -2.5 && (x2-0.1)<=x1 && x1<=(x2+0.1)) r = 2;
	else if (x1 < 31.5 && x2 <= -2.5 && ((x2-0.1)>x1 || x1>(x2+0.1))) r = 3;
	else if (x1 >= 31.5 && -1 <= x3 && x3 <= 2) r = 4;
	else if (x1 >= 31.5 && (-1 > x3 || x3 > 2) && (x4&&x5 ==1)) r = 5;
	else if (x1 >= 31.5 && (-1 > x3 || x3 > 2) && (x4 == 0 || x5 == 0)) r = 6;
	return r;
}

double dt2b(double x1,double x2,double x3,int x4,int x5){
	int r = 0;
	if (12<x1 && x1<22 && (x3>5/3)) r = 7;						/*  check all possible nodes with if , else if */
	else if (12<x1 && x1<22 && (x3<=5/3) && (x1-0.1)<=x3 && x3<=(x1+0.1)) r = 8;
	else if (12<x1 && x1<22 && (x3<=5/3) && ((x1-0.1)>x3 || x3>(x1+0.1))) r = 9;
	else if ((12>=x1 || x1>=22) && (x4&&x5 ==1)) r = 10;
	else if ((12>=x1 || x1>=22) && (x4 == 0 || x5 == 0) && -1<=x2 && x2<=2) r = 11;
	else if ((12>=x1 || x1>=22) && (x4 == 0 || x5 == 0) && (-1>x2 || x2>2)) r = 12;
	return r;

}

int dt3a(int y1,int y2,int y3,double y4,double y5){
	int r = 0;
	if (y1<5 && y2<6) r = 1;							/*  check all possible nodes with if , else if */
	else if (y1<5 && y2>=6 && y3 == 1) r = 2;
	else if (y1<5 && y2>=6 && y3 == 0 && y4<5000 && y5<500) r = 3;
	else if (y1<5 && y2>=6 && y3 == 0 && y4<5000 && y5>=500) r = 4;
	else if (y1<5 && y2>=6 && y3 == 0 && y4>=5000 && y5<500) r = 5;
	else if (y1<5 && y2>=6 && y3 == 0 && y4>=5000 && y5>=500) r = 6;
	else if (y1>=5 && y2<6) r = 7;
	else if (y1>=5 && y2>=6 && y3 == 1) r = 8;
	else if (y1>=5 && y2>=6 && y3 == 0 && y4<5000 && y5<500) r = 9;
	else if (y1>=5 && y2>=6 && y3 == 0 && y4<5000 && y5>=500) r = 10;
	else if (y1>=5 && y2>=6 && y3 == 0 && y4>=5000 && y5<500) r = 11;
	else if (y1>=5 && y2>=6 && y3 == 0 && y4>=5000 && y5>=500) r = 12;
	return r;
}

int dt3b(int y1,int y2,int y3,double y4,double y5){
	int r = 0;
	if (y1<=7 && (y2<=1 || y2>=8)) r = 1;						/*  check all possible nodes with if , else if */
	else if (y1<=7 && (y2>1 || y2<8) && y3 == 0) r = 2;
	else if (y1<=7 && (y2>1 || y2<8) && y3 == 1 && y4<5000 && y5<500) r = 3;
	else if (y1<=7 && (y2>1 || y2<8) && y3 == 1 && y4<5000 && y5>=500) r = 4;
	else if (y1<=7 && (y2>1 || y2<8) && y3 == 1 && y4>=5000 && y5<500) r = 5;
	else if (y1<=7 && (y2>1 || y2<8) && y3 == 1 && y4>=5000 && y5>=500) r = 6;
	else if (y1>7 && (y2<=1 || y2>=8)) r = 7;
	else if (y1>7 && (y2>1 || y2<8) && y3 == 0) r = 8;
	else if (y1>7 && (y2>1 || y2<8) && y3 == 1 && y4<5000 && y5<500) r = 9;
	else if (y1>7 && (y2>1 || y2<8) && y3 == 1 && y4<5000 && y5>=500) r = 10;
	else if (y1>7 && (y2>1 || y2<8) && y3 == 1 && y4>=5000 && y5<500) r = 11;
	else if (y1>7 && (y2>1 || y2<8) && y3 == 1 && y4>=5000 && y5>=500) r = 12;
	return r;
}

