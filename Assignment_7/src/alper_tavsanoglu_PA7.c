#include <stdio.h>		/*libraries*/
#include <stdlib.h>
#include <string.h>

typedef struct Gate
{
    int type;			/* type of the gate 1 to 7*/
    char name[20];		/* name of the gate*/
    int output;			/* stores the current output */
    int former_out;		/* only for flipflop*/
    struct Gate** inputs;	/* points to a dynamically created array of pointers which store,the addresses of input gate structs*/
    struct Gate *next;		/* storing all of them in a linked list*/
}Gate;

typedef struct Input{
    char* line;			/* name of the gate*/
    unsigned int size;
    struct Input *next;

}Input;

char * read_line( FILE *);	/*functions*/
void read_input();			/*taking inputs*/
void read_circuit();			/*taking circuit*/
void calculate();			/*for calculates*/
Gate* find_gate(char *);
int get_output();		/*functions*/

Gate *gates = NULL;
Input *inputs = NULL;
								/* result of connection is equal the connected input that is not an input for any other connection*/
int main() {				/* main function */
    Input *itr;
    Gate  *itr2, *itr3;

    read_input();			/*taking inputs*/
    read_circuit();			/*taking circuit*/
	
    itr = inputs;
    itr2 = gates;

    calculate();			/*for calculates*/
    return 0;
}

void calculate(){
    Gate *itr_gate;
    Input *itr_input = inputs;

    while(itr_input){
        itr_gate = gates;
        for(int i=0;i<itr_input->size;i++){
            while(itr_gate){
                if(itr_gate->type == 1)		/*means that it is input*/
                {
                    itr_gate->output = itr_input->line[i] == '0' ? 0 : 1;
                    itr_gate = itr_gate->next;
                    break;
                }
                itr_gate = itr_gate->next;
            }
        }
        itr_gate = gates;					/*All inputs are set into circuit now calculate gate output*/
        while(itr_gate){
            if(itr_gate->type == 2)				/*AND GATE*/
            {
                if(itr_gate->inputs[0]->output == 1 && itr_gate->inputs[1]->output == 1)
                    itr_gate->output = 1;
                else
                    itr_gate->output = 0;
            }
            else if(itr_gate->type == 3)			/*OR GATE*/
            {
                if(itr_gate->inputs[0]->output == 0 && itr_gate->inputs[1]->output == 0)
                    itr_gate->output = 0;
                else
                    itr_gate->output = 1;
            }
            else if(itr_gate->type == 4)			/*NOT GATE*/
            {
                if(itr_gate->inputs[0]->output == 0)
                    itr_gate->output = 1;
                else
                    itr_gate->output = 0;
            }
            else if(itr_gate->type == 5)			/*FLIPFLOP*/
            {
                if( (itr_gate->inputs[0]->output == 0 && itr_gate->former_out == 0) || (itr_gate->inputs[0]->output == 1 && itr_gate->former_out == 1))
                {
                    itr_gate->output = 0;
                    itr_gate->former_out = 0;
                }
                else
                {
                    itr_gate->output = 1;
                    itr_gate->former_out = 1;
                }
            }
            else if(itr_gate->type == 6)				/*OUTPUT*/
            {
                itr_gate->output = itr_gate->inputs[0]->output;
            }
            itr_gate = itr_gate->next;
        }
        printf("%d\n", get_output());
        itr_input = itr_input->next;
    }
}
void read_input(){					/*taking inputs*/
    FILE *input_file_fp, *circuit_file_fp;
    char* ch;
    Input *itr;					/* iterator for inputs*/
    input_file_fp = fopen("input.txt", "r");
    while( ch = read_line(input_file_fp)) {				/*taking from file*/
        if(strlen(ch) > 0) {
            if (!inputs) {
                inputs = (Input *) malloc(sizeof(Input));		/*dynamic allocation */
                inputs->line = ch;
                inputs->size = strlen(ch);
                inputs->next = NULL;
                itr = inputs;
            } else {
                itr->next = (Input *) malloc(sizeof(Input));		/*dynamic allocation */
                itr = itr->next;
                itr->line = ch;
                itr->size = strlen(ch);
                itr->next = NULL;
            }
        }
    }
}
void read_circuit(){
    FILE *circuit_file_fp;
    char* ch;
    char token1[20], token2[20], token3[20];
    Gate *itr;						/* iterator for inputs*/
    circuit_file_fp = fopen("circuit.txt", "r");
    while( ch = read_line(circuit_file_fp)) {		/*taking from file*/
        if(strlen(ch) > 0) {
            sscanf(ch, "%s %s %s", token1, token2, token3 );
            if(strcmp(token1, "GATE") == 0) {
                if (!gates) {
                    gates = (Gate *) malloc(sizeof(Gate));		/*dynamic allocation */
                    strcpy(gates->name, token3);

                    if(strcmp(token2, "INPUT") == 0)			/*check input*/
                        gates->type = 1;
                    else if(strcmp(token2, "AND") == 0)			/*check and gate*/
                        gates->type = 2;
                    else if(strcmp(token2, "OR") == 0)			/*check or gate*/
                        gates->type = 3;
                    else if(strcmp(token2, "NOT") == 0)			/*check not gate*/
                        gates->type = 4;
                    else if(strcmp(token2, "FLIPFLOP") == 0)		/*check flipflop*/
                    {
                        gates->type = 5;
                        gates->former_out = 0;
                    }
                    else if(strcmp(token2, "OUTPUT") == 0)		/*check output*/
                        gates->type = 6;

                    gates->next = NULL;
                    gates->inputs = NULL;
                    itr = gates;
                } else {
                    itr->next = (Gate *) malloc(sizeof(Gate));
                    itr = itr->next;
                    strcpy(itr->name, token3);

                    if(strcmp(token2, "INPUT") == 0)			/*check input*/
                        itr->type = 1;
                    else if(strcmp(token2, "AND") == 0)			/*check and gate*/
                        itr->type = 2;
                    else if(strcmp(token2, "OR") == 0)			/*check or gate*/
                        itr->type = 3;
                    else if(strcmp(token2, "NOT") == 0)			/*check not gate*/
                        itr->type = 4;
                    else if(strcmp(token2, "FLIPFLOP") == 0){		/*check flipflop*/
                        itr->type = 5;
                        itr->former_out = 0;
                    }
                    else if(strcmp(token2, "OUTPUT") == 0)		/*check output*/
                        itr->type = 6;

                    itr->next = NULL;
                    itr->inputs = NULL;
                }
            }
            else{										/*CONNECTION*/
                Gate *gate1 = find_gate(token2);
                Gate *gate2 = find_gate(token3);
                if(gate2->inputs == NULL){
                    gate2->inputs = (Gate **) malloc(sizeof(Gate *) * 2);			/*dynamic allocation */
                    gate2->inputs[0] = gate1;


                }else{
                    gate2->inputs[1] = gate1;
                }
            }
        }
    }
}

char * read_line( FILE * f ) {				/*for reading file*/
    int cap = 32,  next = 0, c;
    char * p = malloc( cap );

    while( 1 ) {
        if ( next == cap ) {
            p = realloc( p, cap *= 2 );
        }
        c = fgetc( f );

        if ( c == EOF || c == '\n' || c == '\r') {
            p[next++] = 0;
            break;
        }
        p[next++] = c;
    }
    if ( c == EOF && next == 1 ) {
        free( p );
        p = NULL;
    }
    return p;
}
Gate* find_gate(char *name){				/*finding gate*/
    Gate *itr = gates;

    while(itr){
        if(strcmp(itr->name, name) == 0)
            return itr;
        itr=itr->next;
    }
    return NULL;
}

int get_output(){				/*There is only one OUTPUT gate*/
    Gate *itr = gates;

    while(itr){
        if(itr->type == 6)
            return itr->output;
        itr=itr->next;
    }
    return 0;
}
