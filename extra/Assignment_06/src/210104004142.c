#include <stdio.h>			//libraries
#include <stdlib.h>
#include <time.h>

enum moves {right,left,down,up,back};			//enumerated types
enum moves2 {right2,left2,down2,up2,back2};		//enumerated types

int dice();						//Functions
void printMap(int map[][30]);
int mapper(int map[][30]);
int startGame(int map[][30]);
int startGame2(int map[][30]);

int main(){
		int map[15][30];
		
	mapper(map);					//make map
	printMap(map);					//print map

	printf("\n\nTo start to game, players should dice and decide who is going to start first according to it...\n");

srand(time(NULL));		//for dice

while(1){
	printf("\033[0;33m");					//colour
	printf("Player 1... press ENTER to dice");		//player 1's dice
	getc(stdin);						//for press enter
	int p1=dice();
	printf("\033[0;33m");					//colour
	printf("DICE: %d\n",p1);
	printf("\033[0;34m");					//colour
	printf("Player 2... press ENTER to dice");		//player 2's dice	
	getc(stdin);						//for press enter
	int p2=dice();
	printf("\033[0;34m");
	printf("DICE: %d\n",p2);
	printf("\033[0m");

	if(p1>p2){
		printf("\n*** Player 1 will start the game ***\n");			//which player gonna start

		startGame(map);
	break;
		}
	else if(p1<p2){
		printf("\n*** Player 2 will start the game ***\n");			//which player gonna start
	
		startGame2(map);
	break;
		}
	else{
		printf("Same dice value... Please try again.\n");			//if tie
	}
}






return 0;
}





int dice(){					//for dice
	int p= (rand() % 6)+ 1;
	return p;
}

int mapper(int map[][30]){			//printing map

int i,j;
int temp[15][30] = {
 		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
    		{':','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':'},
    		{':','_','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ',':'},
    		{':',' ',':','2',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':'},
    		{':',' ',':','_','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ',':',' ',':'},
    		{':',' ',':',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':','X',':',' ',':'},
    		{':',' ',':',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':',' ',':'},
    		{':',' ',':',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':','X',':'},
    		{':',' ',':',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':',' ',':'},
    		{':',' ',':',' ',':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':',' ',':'},
    		{':',' ',':',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','X',':',' ',':'},
    		{':',' ',':',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',':',' ',':'},
    		{':',' ','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.',' ',':'},
    		{':',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',':'},
    		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
 	 };

for(i=0; i<15; i++){
	for(j=0;j<30;j++){
		map[i][j]=temp[i][j];		//printing map
		}
		}

return 0;
}

void printMap(int map[][30]){
	int i, j;
	
	

for(i=0; i<15; i++) {
	for(j=0;j<30;j++) {

	if(map[i][j]=='1'){				//1's place
	printf("\033[0;33m");				//colour
	printf("%c ", map[i][j]);			//1's place
	printf("\033[0m");				//colour
      	 }					
	else if(map[i][j]=='2'){			//2's place
	printf("\033[0;34m");				//colour
	printf("%c ", map[i][j]);			//2's place
	printf("\033[0m");				//colour
	}
	else if(map[i][j]=='_'){			//_'s place
	printf("\033[0;32m");				//colour
	printf("%c ", map[i][j]);			//_'s place
	printf("\033[0m");				//colour
	}
	else if(map[i][j]=='X'){			//X's place
	printf("\033[0;31m");				//colour
	printf("%c ", map[i][j]);			//X's place
	printf("\033[0m");				//colour
	}
	else{
	printf("%c ", map[i][j]);
         }
         if(j==29){
            printf("\n");
         }
      }
   }
}


int startGame(int map[][30]){

int winner=0;



int i,j;
int currentrow =1;
int currentindex =1;
int currentrow2 =3;
int currentindex2 =3;

enum moves dir=right;				//for p1's direction
enum moves2 dir2=right2;			//for p2's direction	


while(winner==0){				//loop until game over
	printf("\033[0;33m");
	printf("Player 1... press ENTER to dice");	//player 1's dice
	getc(stdin);					//for press enter
	int p1=dice();
	printf("\033[0;33m");
	printf("DICE: %d\n",p1);
	printf("\033[0;34m");
	printf("\033[0m");
	printf("\033[0;34m");
	printf("Player 2... press ENTER to dice");	//player 1's dice
	getc(stdin);					//for press enter
	int p2=dice();
	printf("\033[0;34m");
	printf("DICE: %d\n",p2);
	printf("\033[0m");
	

			
			
			for(i=0;i<p1;i++){									//for p1
				
					if(currentrow==1 && currentindex==28)		dir=down;		//go until come index 28
						
					
						
					if(currentrow==13 && currentindex==28)		dir=left;		//go until come index 28 and row 13
						
						
						
					if(currentrow==13 && currentindex==1)		dir=up;			//go until come index 1 and row 13
					
					
					
					
					
					if(dir==left){
							map[currentrow][currentindex-1]='1';			//for going left
							map[currentrow][currentindex]=' ';
							currentindex--;
						}
						
					if(dir==up){
							map[currentrow-1][currentindex]='1';			//for going up
							map[currentrow][currentindex]=' ';
							currentrow--;
						}
						
						
					if(dir==right){
							map[currentrow][currentindex+1]='1';			//for going right
							map[currentrow][currentindex]=' ';
							currentindex++;
						}
					if(dir==down){
							map[currentrow+1][currentindex]='1';			//for going down
							map[currentrow][currentindex]=' ';
							currentrow++;
						}
					if(currentrow==2 && currentindex==1){				//finish
							
							winner=1;
							break;
							
							}
			
					}
			for(i=0;i<p2;i++){								//for p2
					
					if(currentrow2==3 && currentindex2==26)		dir2=down2;	//go until come index 26 and row 3
					
					if(currentrow2==11 && currentindex2==26)	dir2=left2;	//go until come index 26 and row 11
					
					if(currentrow2==11 && currentindex2==3)		dir2=up2;	//go until come index 3 and row 11
					
					if(dir2==left2){						//for going left
							map[currentrow2][currentindex2-1]='2';
							map[currentrow2][currentindex2]=' ';
							currentindex2--;
						}
					if(dir2==up2){							//for going up
							map[currentrow2-1][currentindex2]='2';
							map[currentrow2][currentindex2]=' ';
							currentrow2--;
						}
					if(dir2==right2){						//for going right
							map[currentrow2][currentindex2+1]='2';
							map[currentrow2][currentindex2]=' ';
							currentindex2++;
						}
					if(dir2==down2){						//for going down
							map[currentrow2+1][currentindex2]='2';
							map[currentrow2][currentindex2]=' ';
							currentrow2++;
						}
					if(currentrow2==4 && currentindex2==3){				//finish
							
							winner=2;
							break;
							
							}
							
				}
					
			
			
			
	printMap(map);
	
	}
if(winner==1)	printf("\n\n\n*****Player 1 Won The Game ****\n\n");

else if(winner==2) printf("\n\n\n*****Player 2 Won The Game ****\n\n");
	

printMap(map);


return 0;
}


int startGame2(int map[][30]){

int winner=0;



int i,j;
int currentrow =1;
int currentindex =1;
int currentrow2 =3;
int currentindex2 =3;

enum moves dir=right;
enum moves2 dir2=right2;


while(winner==0){
	printf("\033[0;34m");
	printf("Player 2... press ENTER to dice");
	getc(stdin);
	int p2=dice();
	printf("\033[0;34m");
	printf("DICE: %d\n",p2);
	printf("\033[0m");
	printf("\033[0;33m");
	printf("Player 1... press ENTER to dice");
	getc(stdin);
	int p1=dice();
	printf("\033[0;33m");
	printf("DICE: %d\n",p1);
	printf("\033[0;34m");
	printf("\033[0m");

	

			for(i=0;i<p2;i++){								//for p2
					
					if(currentrow2==3 && currentindex2==26)		dir2=down2;		//go until come index 26 and row 3
					
					if(currentrow2==11 && currentindex2==26)	dir2=left2;		//go until come index 26 and row 11
					
					if(currentrow2==11 && currentindex2==3)		dir2=up2;		//go until come index 3 and row 11
					
					if(dir2==left2){							//for going left
							map[currentrow2][currentindex2-1]='2';
							map[currentrow2][currentindex2]=' ';
							currentindex2--;
						}
					if(dir2==up2){								//for going up
							map[currentrow2-1][currentindex2]='2';
							map[currentrow2][currentindex2]=' ';
							currentrow2--;
						}
					if(dir2==right2){							//for going right
							map[currentrow2][currentindex2+1]='2';
							map[currentrow2][currentindex2]=' ';
							currentindex2++;
						}
					if(dir2==down2){							//for going down
							map[currentrow2+1][currentindex2]='2';
							map[currentrow2][currentindex2]=' ';
							currentrow2++;
						}
					if(currentrow2==4 && currentindex2==3){					//finish
							
							winner=2;
							break;
							
							}
							
				}
			
			for(i=0;i<p1;i++){									//for p1
				
					if(currentrow==1 && currentindex==28)		dir=down;		//go until come index 28 and row 1
						
					
						
					if(currentrow==13 && currentindex==28)		dir=left;		//go until come index 28 and row 13
						
						
						
					if(currentrow==13 && currentindex==1)		dir=up;			//go until come index 1 and row 13
					
					
					
					
					
					if(dir==left){								//for going left
							map[currentrow][currentindex-1]='1';
							map[currentrow][currentindex]=' ';
							currentindex--;
						}
						
					if(dir==up){								//for going up
							map[currentrow-1][currentindex]='1';
							map[currentrow][currentindex]=' ';
							currentrow--;
						}
						
						
					if(dir==right){								//for going right
							map[currentrow][currentindex+1]='1';
							map[currentrow][currentindex]=' ';
							currentindex++;
						}
					if(dir==down){								//for going down
							map[currentrow+1][currentindex]='1';
							map[currentrow][currentindex]=' ';
							currentrow++;
						}
					if(currentrow==2 && currentindex==1){					//finish
							
							winner=1;
							break;
							
							}
			
					}
			
					
			
			
			
	printMap(map);
	
	}
if(winner==1)	printf("\n\n\n*****Player 1 Won The Game ****\n\n");

else if(winner==2) printf("\n\n\n*****Player 2 Won The Game ****\n\n");
	

printMap(map);


return 0;
}



