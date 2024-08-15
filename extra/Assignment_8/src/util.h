// util.h
#ifndef _UTIL_H_
#define _UTIL_H_

int has_loop(int *arr, int n, int looplen, int *ls, int *le);					//part3

void generate_sequence (int xs, int currentlen, int seqlen, int *seq);				//part1

void check_loop_iterative(void (*f)(), int xs, int seqlen, int *loop, int *looplen);		//part2

void hist_of_firstdigits(void (*f)(), int xs, int seqlen, int *h, int digit);		//part4

#endif 
