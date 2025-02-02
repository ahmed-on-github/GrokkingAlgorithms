#include <stdio.h>
#include <stdlib.h>

void swap( int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int * arr , int low,int high ){ 

    int pivotIdx = high;
    int i = low-1, j= high;

    int val1, val2 ;
    /**Partition**/
    while( i<= j){

        do{
            i++;
            val1 = arr[i];
            val2 = arr[ pivotIdx ];
        }while( val1 <= val2 && i < pivotIdx);

        do {
           j--;
           val1 = arr[pivotIdx];
           val2 = arr[j];

        }while( val1 <= val2 && j>=0);

        if(i<j){
            swap( &arr[i], &arr[j] );
        }
    }
    /**Place pivotIdx in its correct place*/
    swap( &arr[pivotIdx] , &arr[i] ); /**Swap arr[i] that is > pivotIdx, with pivotIdx**/
    pivotIdx = i;

    /** recursion **/
    if( low < pivotIdx-1){
        quicksort(arr,low,pivotIdx-1  );
    }
    if(high > pivotIdx+1){
        quicksort(arr,pivotIdx+1  ,high);
    }
}


int main(){

    int arr [] = {10 , 1 , 2 ,0, 5, 3, 6 , 9 , 8 , 14, 7};
    int size = sizeof(arr)/sizeof( arr[0]);

    quicksort(arr,0,size-1);

    for(int i= 0 ;i < size ; i++){
        printf("%d ",arr[i]);
    }
    //printf("\nEl7 Successful :) xD\n");
    return 0;
}
