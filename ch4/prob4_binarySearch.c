#include <stdio.h>

/*
 *
 * Search for 'val' inside a sorted array 'arr' of 'arr_len' elements
 *
 */

int bin_search( int * arr ,int val , unsigned int arr_len){
	static int  low = 0; /*Static to be stored once away from the stack frames of the functions*/
	static int high = 0;
	static unsigned int offset = 0;

	low = 0; /*Must be reset as 'arr' may be changed in the recursive call*/
	high = 0 + arr_len -1; /*Bec. this initializer value is not constant*/
	int mid = (0 + high)/2 ; /*replacing 'low' with 0 for less memory access */

	/*Base case*/
	if( val == arr[mid]  && 0 <= high ){
	    mid = mid + offset;
	    offset = 0 ; /*reset for next calls*/
		return mid;
	}
	else if ( high <= 0 ){ /*Do not use else as it will ignore the value in equality (which doesn't mean 'va' is not found)*/
	    offset = 0; /*reset for next calls*/
		return -1;  /*not found*/
	}
	/*recursive case*/
	if( val > arr[mid] ){
		low = mid+1;
		offset += low; /*Offset from the address 'arr' passed in the 1st call*/
	}
	else { /* val < arr[mid] */
		high = mid-1;
	}
	return bin_search( (int*)(arr+low), val , high - low + 1 /* +1 bec both indices are included*/);
}

int main(){
	/*Testing the code*/
    int arr [] = {-1,0,1,2,3,5,6,7,8,9,10,14}; /*Must be a sorted array*/
    int size = sizeof(arr)/sizeof( arr[0]);

	int val = 4; /*Not present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = -2; /*Not present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 5; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 8; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 10; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 2; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = -1; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 14; /*present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	val = 18; /* not present*/
	printf("Index of %d = %d\n", val , bin_search(arr, val, size) );

	/*Passing all the array elements as values*/
	for(int i = -1 /* -1 reads a value before the array,
	value may be in the array may be garbage or may cause segmentation fault if it's an illegal memory access*/  ;
	i < size + 1 ; i++){
	    printf("Index of arr[%d] = %d\n", i , bin_search(arr, arr[i], size) );
	}
	return 0;
}
