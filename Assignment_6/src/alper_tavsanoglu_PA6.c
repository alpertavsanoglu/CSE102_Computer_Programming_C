#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CARB_CAL_1G 4               /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4            /* Number of calories in 1g protein */
#define FAT_CAL_1G 9                /* Number of calories in 1g fat */
#define WATER_CAL_1G 0              /* Number of calories in 1g water */
#define MAX 100

void anafonk(char object[MAX],double *gram,double *tot_carb,double *tot_protein,double *tot_fat);			
void clear_space_2(char a[MAX]);									/* clearing white space in the sentence  at the beginning and the ending*/
void clear_space_1(char obj[MAX]);									/* clearing white space in the sentence */
int check_number(char obj[MAX] );									/*checking sentence include number in in or not */
int parse(char *obj,char str[][MAX], int *value);							/*parsing the string */
	
int main(void)
{
    double gram=0;				/*variables for calculations*/
    double total_carb=0;
    double total_protein=0;
    double total_fat=0;
    double total_cal=0;
    char object[MAX] = {};
    printf("What is the meal?:\n");
    scanf("%[^\n]s",object);
    getc(stdin);
    clear_space_2(object);							/* clearing white space in the sentence  at the beginning and the ending*/
    clear_space_1(object);							/* clearing white space in the sentence */
    anafonk(object,&gram,&total_carb,&total_protein,&total_fat);

    total_cal=total_carb+total_protein+total_fat;				/*calculations*/
    total_carb=total_carb*100/total_cal;
    total_protein=total_protein*100/total_cal;
    total_fat=total_fat*100/total_cal;
    
    printf("Total calories is %.2lf in %.2lfg %s. %%%.2lf calories from carbs, %%%.2lf from proteins, %%%.2lf from fats.\n",total_cal,gram,object,total_carb,total_protein,total_fat);
}

void anafonk(char object[MAX],double *gram,double *tot_carb,double *tot_protein,double *tot_fat){	

    char obj[MAX];			/*for parsed values*/
    char store[MAX];			/*for % values*/
    char *ptr = &(obj[0]);			/*for parsed values*/
    char *str = &(store[0]);			/*for % values*/
    char parts[MAX][MAX];
    int num_of_parts;
    size_t lenght=MAX;

    char *var;				/*for taking numbers from string*/
    const char s[2] = "(";
    char *kalsn[2];
    char *kalsn2[5];
    char *delp;				/*for taking numbers from string*/
    
    int xx=0;				/*temp values*/
    int xy=0;	
    double yas=0;			/*temp values*/
    double yas2=0;    
    double carb=0;			/*temp values*/
    double protein=0;
    double fat=0;			/*temp values*/
    double temp_value_carb=0;
    double temp_value_protein=0;
    double temp_value_fat=0;


printf("What is %s?:\n",object);
getline(&ptr,&lenght,stdin);
clear_space_2(obj);							/* clearing white space in the sentence  at the beginning and the ending*/
clear_space_1(obj);							/* clearing white space in the sentence */
parse(obj,parts,&num_of_parts);						/*parsing the string */

for (int i = 0; i < num_of_parts; i++)
    {
        if(check_number(parts[i]))
        {
                            var = strtok(parts[i], s);					/*parsing the string */
                            xx=0;
                            while( var != NULL ) {					
                                                    kalsn[xx]=var;			/*store parsed values*/
                                                    var = strtok(NULL, s);
                                                    xx++;
                                                    }					/*end parsing the string */
                        yas=0;
                        sscanf(kalsn[1],"%lf",&yas);							/*for taking numbers from string*/
                        *gram+=yas;

            printf("List the amount macro nutrients in %s:\n",kalsn[0]);
            getline(&str,&lenght,stdin);
            clear_space_2(store);								/* clearing white space in the sentence  at the beginning and the ending*/
            clear_space_1(store);								/* clearing white space in the sentence */
                				delp=strtok(store," %");			/*parsing the string */
                				xy=0;
                	while (delp!=NULL){
                                           	 kalsn2[xy]=delp;					/*store parsed values*/
                                            	delp =strtok(NULL," %");
                                            	xy++;
                                            }							/*end parsing the string */
                        carb=0;
                        protein=0;
                        fat=0;
                        sscanf(kalsn2[1],"%lf",&carb);					/*for taking numbers from string*/
                        sscanf(kalsn2[2],"%lf",&protein);				/*for taking numbers from string*/
                        sscanf(kalsn2[3],"%lf",&fat);					/*for taking numbers from string*/
                        				temp_value_carb=yas*carb/100;						/*finding tot cal coming from carb*/
                        				carb=temp_value_carb*CARB_CAL_1G;
                        				*tot_carb+=carb;
                        
                       					temp_value_protein=yas*protein/100;					/*finding tot cal coming from protein*/
                        				protein=temp_value_protein*PROTEIN_CAL_1G;
                        				*tot_protein+=protein;
                        
                        				temp_value_fat=yas*fat/100;						/*finding tot cal coming from fat*/		
                        				fat=temp_value_fat*FAT_CAL_1G;
                        				*tot_fat+=fat;
            }
        else
        {
            if(check_number(parts[i]))
            {
                            var = strtok(parts[i], s);				/*parsing the string */
                            xx=0;
                            while( var != NULL ) {				
                                                    kalsn[xx]=var;		/*store parsed values*/
                                                    var = strtok(NULL, s);
                                                    xx++;
                                                    }				/*end parsing the string */
                        yas2=0;
                        sscanf(kalsn[1],"%lf",&yas2);							/*for taking numbers from string*/
                        *gram+=yas2;
                
            printf("List the amount macro nutrients in %s:\n",kalsn[0]);
            getline(&str,&lenght,stdin);
            clear_space_2(store);								/* clearing white space in the sentence  at the beginning and the ending*/
            clear_space_1(store);								/* clearing white space in the sentence */
                            			delp=strtok(store," %");			/*parsing the string */
                            			xy=0;
                        while (delp!=NULL){
                                            	kalsn2[xy]=delp;				/*store parsed values*/
                                            	delp =strtok(NULL," %");
                                            	xy++;
                                            }							/*end parsing the string */
                        carb=0;
                        protein=0;
                        fat=0;
                        sscanf(kalsn2[1],"%lf",&carb);					/*for taking numbers from string*/
                        sscanf(kalsn2[2],"%lf",&protein);				/*for taking numbers from string*/
                        sscanf(kalsn2[3],"%lf",&fat);					/*for taking numbers from string*/
                        				temp_value_carb=yas*carb/100;						/*finding tot cal coming from carb*/
                        				carb=temp_value_carb*CARB_CAL_1G;
                        				*tot_carb+=carb;
                        
                        				temp_value_protein=yas*protein/100;					/*finding tot cal coming from protein*/
                       					protein=temp_value_protein*PROTEIN_CAL_1G;
                       					*tot_protein+=protein;
                        
                        				temp_value_fat=yas*fat/100;						/*finding tot cal coming from fat*/
                        				fat=temp_value_fat*FAT_CAL_1G;
                        				*tot_fat+=fat;
            }
            else{
            anafonk(parts[i],gram,tot_carb,tot_protein,tot_fat);								/*recursive part*/
                }
        }
        }
}

int parse(char *obj,char str[][MAX], int *value)			/*parsing the string */
{
    char *temp = obj;
    char *flag;
    int x = 0;

    while ((flag = strtok_r(temp, " , ", &temp))) 				/*parsing the string considering the comma*/
    {  
    strcpy(str[x], flag);
    x++;  
    }
    *value = x;							/*number of parsing*/
    return 0;
}

int check_number(char obj[MAX] )					/*checking sentence include number in in or not */
{
    int number = 0;

    for (int i = 0; i < strlen(obj) - 1; i++)
    {
        if((obj[i]>='0' && obj[i]<='9') )			/*checking sentence include digit */
        {
            number = 1;
            break;
        }
    }
    return number;
}

void clear_space_1(char obj[MAX])	/* clearing white space in the sentence */
{
    int size = strlen(obj); 
    int counter = 0;

    
    for(int i = 0 ; i < size+1; i++)
    {
        if(obj[i] != ' ')			/*checking extra spaces*/
        {
            obj[counter] = obj[i];
            counter++;
        }
    }
    obj[counter-1] = '\0'; 				/*checking ending */
}

void clear_space_2(char a[MAX]){				/* clearing white space in the sentence  at the beginning and the ending*/
	
	int i=0,j,counter_start=0,len;
	char temp[MAX+1];

	while(a[i]!='\n' && a[i]!=0){			/*cheching newline*/
		i++;
	}
	a[i]=0;
	
	i=0;
	while(a[i]==' '){					/*checking extra spaces*/
		
		counter_start++;
		i++;
	}
	if(counter_start!=0){
		j=0;
		while(a[i]!=0){
			a[j]=a[i];
			j++;
			i++;
		}
		a[j]=0;
	}
	len=strlen(a);
	len=len-1;
	
	while(a[len]==' '){					/*clearing extra spaces*/
		len--;
	}
	a[len+1]=0;	
}
