#include <stdio.h>
void swap(int* xp, int* yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void  bubble_sort( int arr[] ) {
  for ( int i = 0 ; i < 5 ; i ++ ) {
    for (int j = i+1 ; j< 5 ; j++ ) {
      if ( arr[i] > arr[j] )
        swap( &arr[i] , &arr[j]) ; 
    }
  }
}
int main(void) {
  int arr[6] = {10 , 2 , 4 , 5 , 2  ,6 } ; 
  bubble_sort( arr ) ;
  for ( int i = 0 ; i < 5 ; i++  ) {
    printf( "%d " , arr[i]) ;
  }
  return 0 ; 
}

