#include <stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
    int a ;
    float b ;
    double c ;
    a = INT_MAX ;
    b = FLT_MAX ;
    c = DBL_MAX ;
    printf("for the int : %d %d \n" , sizeof(a) , a) ;
    printf("for the int : %d %f \n" , sizeof(b) , b) ;
    printf("for the int : %d %f \n" , sizeof(c) , c) ;
    return 0;
}
