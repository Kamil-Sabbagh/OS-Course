#include <stdio.h>

int main(void) {
  // ct = compile time 
  // TAT = turn around time 
  // wt = wait time 
  int n , CT = 0 , TAT = 0 , WT = 0  ;
  scanf( "%d" , &n ) ; 
  int processes [100][100] ; 
  for (int i = 0 ; i<n ; i++ ) {
      int a , b ; 
      scanf( "%d %d" , &a , &b ) ;
      processes[i][0] = a ; 
      processes[i][1] = b ; 
  } 
  int k = 1 ; 
  while (k ==1 ) { 
    int mn = 9999999 ; int j = -1 ;  
    int c = 0 ; 
    //here we will look for the preceess with the shortest processing needed 
    for (int i = 0 ; i<n ; i++ ) {
      int a = processes[i][0] ; 
      int b = processes[i][1] ;
      if (a <= CT &&  b < mn && b > 0  ) {
        mn = b ; 
        j = i ; 
      }
      if (b > 0 ) k = 2 ; 
      //this if will help us count the wiating processes 
      if ( a <= CT && b > 0 ) c+= 1 ; 
    } 
    if (j == -1 && k==1 ) break ;
    if (j == -1 && k == 2 ) { CT ++ ; k =1 ; continue; }
    k = 1  ; 
    WT += c-1 ;  
    CT += 1 ;
    processes[j][1] -= 1 ;
    if (processes[j][1] == 0 ) TAT += CT - processes[j][0] ; 
  }
  printf ("Completion time = %d \n" , CT ) ;
  printf ("Turn around time = %d \n" , TAT ) ; 
  printf ("Waiting time = %d \n" , WT ) ; 
  printf ("Average Turnaround time = %d \n" , TAT/n ) ; 
  printf ("Average waiting time = %d \n" , WT/n ) ; 
  return 0;
}
