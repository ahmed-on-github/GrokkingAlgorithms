#include <stdio.h>

/*this function implicitly returns the GCD of l and w*/
unsigned int max_square_size( unsigned int l , unsigned int w ){

	/*base case : One is multiple of the other*/
	if( l >= w ){
		if( l%w == 0){
			  return w;
		}
	}
	else { /* w > l  */
		if( w%l == 0){
			  return l;
		}
	}
	/*Recursive case*/
	if( l > w ){
		return   max_square_size( w, l-w);
	}
	return max_square_size( l , w-l);  /* l <= w */ 
}


int main(void){
	/*Ex1: L = 1680, W = 640*/
	unsigned int l = 1680, w = 640;
	printf("max_square_size(%u, %u) = %u\n",l,w, max_square_size(l,w));
	
	/*Ex2: L = 25, W = 50 (One is multiple of the other --> Base case)*/
	l = 25, w = 50;
	printf("max_square_size(%u, %u) = %u\n",l,w, max_square_size(l,w));
	
	return 0;
}