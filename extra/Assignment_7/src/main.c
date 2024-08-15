//libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define word_num 50			//number of words in file
#define word_count 7			//7 random words
#define word_size 6			//avarage word lenght 
#define max_word_size 5			//max word size
#define chance 0			//3 chance for find true word
#define location_number 2		//for locaions
#define true 1				//for 1
#define zero 0				//for 0
#define row_size 15			//number of rows
#define colum_size 15			//number of collums
#define directions 8			//8 directions
#define minus -1			//minus 1

enum ways {way1, way2, way3, way4, way5, way6, way7, way8};
/* 
		1-) left to right horizontal
		2-) right to left horizontal
		3-) up to down vertical
		4-) down to up vertical
		5-) left up to right down diognal
		6-) right up to left down diognal
		7-) left down to right up diognal
		8-) right down to left up diognal
		
*/
int find_word(char map[row_size][colum_size], char word[max_word_size], int row, int colum);						//find words and print x
void take_7_different_word(char random_words[word_count][word_size],char word[word_num][word_size],int temp[word_count]);				//7 words which are taken from file
void word_list(char word_list[word_count][word_size]);												////listed 7 words which are taken from file list
void words_locations( char word_location[word_count][word_size],int location[word_count][location_number],int location_2[word_count][location_number]);		//find words locations
void fill_map_with_star(char size[row_size][colum_size]);													//fill map with *
void puzzle_table(char size[row_size][colum_size], char selected_words[word_count][word_size], int location[word_count][location_number]);		//create puzzle table with words
void gaming(char size[row_size][colum_size]);		//game part
void lefts(int left,int point);				//how many rights do you have left

int main(){
	srand(time(NULL));
	int temp[word_count];										
	char words_from_file[word_num][word_size];							
	char selected_words[word_count][word_size];							
	char area[row_size][colum_size];								
	int location[word_count][location_number];									
	take_7_different_word(selected_words,words_from_file,temp);					//7 words which are taken from file
	word_list(selected_words);									//7 words which are taken from file
	//for(i = 0; i <  word_num; ++i)							//for check all words taken from file
	//printf("%s \n", file_words[i]);
	//for(i = 0; i <  7; ++i)								//for check 7 different words chosen
	//printf("chosen %s \n", selected_words[i]);
	puzzle_table(area, selected_words, location);						//create puzzle table with words
	words_locations(selected_words,location,location);					//print words locations
	printf("\n");
	printf("0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n-----------------------------\n");				//for good looking
	gaming(area);										//game part
	return 0;
}

void take_7_different_word(char random_words[word_count][word_size],char word[word_num][word_size],int temp[word_count]){		// take 7 random words
int count, differ;
int i=zero,j=zero;
char words[word_num];
FILE *fp = fopen("wordlist.txt", "r");
while(fscanf(fp, "%s", words) == true ){
		if(i<word_num){
			strcpy(word[i], words);
			++i;
			}
		}
fclose(fp); 	//close file					
	for(i = zero; i < word_count; ++i)	temp[i] = -1;
	for(i = zero; i < word_count; ++i){	differ = rand() % word_num;
						for(j = zero; j  < word_count; ++j){
										if(differ == temp[j])	count = true;
											}
		if(count == true)	i--;	
			else{		temp[i] = differ;
					strcpy(random_words[i], word[temp[i]]);
				}
				count = zero;
					}
}

void word_list(char word_list[word_count][word_size]){				//listed 7 words
	int i;
		for ( i = zero; i < word_count; ++i){ 
			printf("%d. : %s\n",i+1,word_list[i]);
		}
}

void words_locations( char word_location[word_count][word_size],int location[word_count][location_number],int location_2[word_count][location_number]){	//print word locations
int i=zero;
printf("words locations\n");
for(i = zero; i < word_count; ++i)
		printf("%d\t%d\t%s\n",location[i][0],location_2[i][1],word_location[i]);
	printf("\n");
}

void fill_map_with_star(char size[row_size][colum_size]){	//fill map with *
int i=zero,j=zero;
for( i = zero; i < row_size; ++i){
		for( j = zero; j < colum_size; ++j)
			size[i][j] = '*';			//fill blnaks with '*'
	}
}

void puzzle_table(char size[row_size][colum_size], char selected_words[word_count][word_size], int location[word_count][location_number]){	//create puzzle table with words and random chars
int i=zero,j=zero;
char map;
int first_place[location_number];
int extent;
int condition=zero;
int direction;
	fill_map_with_star(size);
	i = zero;
	while(i < word_count){					
		first_place[zero] = rand() % row_size;
		first_place[1] = rand() % colum_size;
		extent = strlen(selected_words[i]);
		direction = 1 + (rand() % directions);		// randum direction
		condition=zero;
			if(direction == 1){
				if(first_place[1] + extent < row_size){
					for( j = zero; j < extent; ++j){	if(size[first_place[0]][first_place[1] + j] != '*')	condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0]][first_place[1] + j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
			else if(direction == 2){
				if(first_place[1] - extent > 0){
					for( j = zero; j < extent; ++j){	if(size[first_place[0]][first_place[1] - j] != '*')	condition = 1;	}
				if(condition == zero){
					for(j = zero; j < extent; ++j)		size[first_place[0]][first_place[1] - j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
			else if(direction == 3){
				if(first_place[0] + extent < row_size){
					for( j = zero; j < extent; ++j){	if(size[first_place[0] + j][first_place[1]] != '*')	condition = 1;	}	
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0] + j][first_place[1]] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
			else if(direction == 4){
				if(first_place[0] - extent > 0){
					for(j = zero; j < extent; ++j){		if(size[first_place[0] - j][first_place[1]] != '*')	condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0] - j][first_place[1]] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}		
			else if(direction == 5){
				if(first_place[0] + extent < row_size && first_place[1] + extent < row_size){
					for( j = zero; j < extent; j++){					if(size[first_place[0] + j][first_place[1] + j] != '*')		condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; j++)		size[first_place[0] + j][first_place[1] + j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
			else if(direction == 6){
				if(first_place[0] + extent < row_size && first_place[1] - extent > 0){
					for(j = zero; j < extent; ++j){						if(size[first_place[0] + j][first_place[1] - j] != '*')		condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0] + j][first_place[1] - j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
			else if(direction == 7){
				if(first_place[0] - extent > 0 && first_place[1] + extent < row_size){
					for( j = zero; j < extent; ++j){					if(size[first_place[0] - j][first_place[1] + j] != '*')		condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0] - j][first_place[1] + j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}	
			else if(direction == 8){
				if(first_place[0] - extent > 0 && first_place[1] - extent > 0){
					for( j = zero; j < extent; ++j){					if(size[first_place[0] - j][first_place[1] - j] != '*')		condition = 1;	}
				if(condition == zero){
					for( j = zero; j < extent; ++j)		size[first_place[0] - j][first_place[1] - j] = selected_words[i][j];
										location[i][0] = first_place[0];
										location[i][1] = first_place[1];
										++i;	}
									}
				}
	 }
	    		//fill blnaks with random  characters where is '*'
			for(i = zero; i < row_size; ++i){			
				for( j = zero; j < colum_size; ++j){
									if(size[i][j] == '*' ){	map = 'a'+rand()%26;
												size[i][j] = map;
												}
									}
							}
}

int find_word(char map[row_size][colum_size], char word[max_word_size], int row, int colum){	//checking all(8) directions 
	int i=0;
	int direction=0;
	int condition;
	char word_2[5];
	int extent;
	extent = strlen(word);
	int Right, Left, Up, Down;
	direction = way1;
	Right = (colum_size < colum + extent);		//for right
	Left = (minus > colum - extent);		//for left
	Up = (minus > row - extent);			//for up
	Down = (row_size < row + extent);		//for down

		while(direction < directions)
	{
		condition = 1;
			if (direction==way1){
				if(!Right){
					for(i=0; i<extent; ++i){	if(map[row][colum+i] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for( i=0; i<extent; ++i)	map[row][colum+i] = 'x';		return 1;}
						}
						++direction;
						}
			else if (direction==way2){
				if(!Left){
					for(i=0; i<extent; ++i){	if(map[row][colum-i] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row][colum-i] = 'x';		return 1;}
						}
						++direction;	
						}
			else if (direction==way3){
				if(!Down){
					for(i=0; i<extent; ++i){	if(map[row+i][colum] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row+i][colum] = 'x';		return 1;}
						}
						++direction;
						}
			else if (direction==way4){
				if(!Up){
					for(i=0; i<extent; ++i){	if(map[row-i][colum] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row-i][colum] = 'x';		return 1;}
						}					
						++direction;
						}
			else if (direction==way5){
				if(!Left){
					for(i=0; i<extent; ++i){	if(map[row-i][colum-i] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row-i][colum-i] = 'x';		return 1;}
						}
						++direction;
						}
			else if (direction==way6){
				if(!Right){
					for(i=0; i<extent; ++i){	if(map[row-i][colum+i] != word[i]){	condition = 0;		break; }	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row-i][colum+i] = 'x';		return 1;}
						}
						++direction;
						}
			else if (direction==way7){
				if(!Left && !Down){
					for(i=0; i<extent; ++i){	if(map[row+i][colum-i] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)		map[row+i][colum-i] = 'x';		return 1;}
						}
						++direction;
						}
			else if (direction==way8){
				if(!Right && !Down){
					for(i=0; i<extent; ++i){	if(map[row+i][colum+i] != word[i]){	condition = 0;		break;	}	}
					if(condition){
						for(i=0; i<extent; ++i)	map[row+i][colum+i] = 'x';		return 1;}
						}
						++direction;
						}	
	}
	return 0;
}

void gaming(char size[row_size][colum_size]){				//gaming part
	int i=zero,j=zero;
	char choice1[20];
	int finish;
	char terminated[5];
	int row;
	int colum;
	int point = zero;
	int chances = zero;
	int count = zero;

while(1){
		for( i = zero; i < row_size; ++i){
			for( j = zero; j < colum_size; ++j)
				printf("%c ", size[i][j]);
			printf("\n");
		}
		printf("Enter coordinates and word: ");
		fgets(choice1, 20, stdin);
		sscanf(choice1, "%d %d %s",&row, &colum, terminated); 							
		if (strncmp(choice1,":q",2)==zero){	printf("Game is terminated!!\n");	exit(1);	finish=zero;	}	else finish=1;	//if user types :q terminate the program
				if(find_word(size, terminated, row, colum) == true){
				point += 2;
				printf("Founded! You got 2 points. Your total points : %d\n\n", point);
				++count;
				}
				else{
					++chances;
					lefts(chances,point);
					if(chances==3) break;
				}
					
		if(count == word_count)		break;
	}
	printf("Game over!!!\n");
	printf("You won %d points.\n",point);
}

void lefts(int left,int point){													//how many rights do you have left
				if(left == 3){
					printf("Wrong choice! You have no more lefts.\nYour total points : %d\n\n",point);	//if you made 3 mistakes
				}
				if(left == 2){
					printf("Wrong choice! You have only 1 left.\nYour total points : %d\n\n",point);	//if you made 2 mistakes
					}
				else if(left == 1){
					printf("Wrong choice! You have only 2 lefts.\nYour total points : %d\n\n",point);	//if you made 1 mistakes
					}
}

