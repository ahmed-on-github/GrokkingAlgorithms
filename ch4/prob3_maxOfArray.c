#include <stdio.h>

/* This file is compiled and ran as: 
 * > gcc prob3_maxOfArray.c -o out.exe
   > ./out.exe 1
   > ./out.exe 2
 */

int max(int a, int b){
	return ((a>b)?a:b);
}

int maxVal_recursive1( int *arr , unsigned int len){
	if( arr != NULL && len > 0){
		/*Base case; Length = 1*/
		if(len == 1){
			return arr[0];
		}
		/*Recursive case*/
		return max(arr[0], maxVal_recursive1(arr+1, len-1));
	}
	else{
		return (int)0x80000000; /*return smallest int value*/
	}
}

int maxVal_recursive2( int *arr , unsigned int len){
	if( arr != NULL && len > 0){
		/*Base case; Length = 1*/
		if(len == 1){
			return arr[0];
		}
		/*Recursive case*/
		int midIdx = len/2; /*Integer division*/
		
		int max1 = maxVal_recursive2(arr, midIdx);
		int max2 = maxVal_recursive2(arr + midIdx, midIdx + (len&0x01) /*Consider odd value of 'len' */ );
		
		return max(max1, max2);
	}
	else{
		return (int)0x80000000; /*return smallest int value*/
	}
}


int main(int argc, char **argv){
	if(argc < 2 || argc > 3 || argv == NULL || argv[1] == NULL ){
		printf("argc = %d\n", argc);
	
		printf("Invalid Arguments passed!\n");
		return -1;
		printf("argv[1] = %s\n", argv[1]);
		printf("argv[1][0] = %c\n", argv[1][0]);
	}
	int arr [] = {10 , 1 , 2 ,0, 5, 3, 6 , 9 , 8 , 14, 7};
	//int arr [] = {0,1,2,3,5,6,7,8,9,10,14};
	int size = sizeof(arr)/sizeof( arr[0]);
	int maxVal = 0;
	if(argv[1][0] == '1' )
		maxVal = maxVal_recursive1(arr, size);
	else if(argv[1][0] == '2' )
		maxVal = maxVal_recursive2(arr, size);
	else
		printf("Invalid Arguments passed!\n");
	printf("maxVal_recursive(arr, %d) = %d\n", size, maxVal);
	return 0;
}
