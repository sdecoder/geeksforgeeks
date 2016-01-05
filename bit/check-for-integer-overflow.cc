#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
 
int addOvf(int* result, int a, int b)
{
   if( a > INT_MAX - b)
     return -1;
   else
   {
     *result = a + b;
      return 0;
   }
}
 
int main()
{
  int *res = (int *)malloc(sizeof(int));
  int x = 2147483640;
  int y = 10;
 
  printf("%d", addOvf(res, x, y));
  printf("\n %d", *res);
  getchar();
  return 0;
}


