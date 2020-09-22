#include <stdio.h>
int min ( int a , int b ) {
  if ( a <= b ) return a ; 
  return b  ;
}
int main(void) {
  // ct = compile time 
  // TAT = turn around time 
  // wt = wait time 
  int n , Q , CT = 0 , TAT = 0 , WT = 0  ;
  scanf( "%d %d" , &n , &Q ) ; 
  int processes [100][100] ; 
  for (int i = 0 ; i<n ; i++ ) {
      int a , b ; 
      scanf( "%d %d" , &a , &b ) ;
      processes[i][0] = a ; 
      processes[i][1] = b ;
      processes[i][2] = a ;
  } 
  int k = 1 ;
  while (k == 1 ) {
   k = 0 ; 
    for (int i = 0 ; i<n ; i++ ) { 
      int a = processes[i][0] ; 
      int b = processes[i][1] ;
      if (b > 0) k = 2 ; 
      if (a <= CT && b > 0 ) {
        k = 1 ; 
        WT += CT - processes[i][2] ; 
        int v = min( b , Q ) ;
        CT += v ; 
        processes[i][2] = CT ;
        processes[i][1] -= v ;
        if (processes[i][1] == 0 ) 
        TAT += CT ; 
      }
    }
    if ( k == 2 ) {
      k = 1 ; 
      CT++ ; 
    }
  }
  printf ("Completion time = %d \n" , CT ) ;
  printf ("Turn around time = %d \n" , TAT ) ; 
  printf ("Waiting time = %d \n" , WT ) ; 
  printf ("Average Turnaround time = %d \n" , TAT/n ) ; 
  printf ("Average waiting time = %d \n" , WT/n ) ; 
  return 0;
}
