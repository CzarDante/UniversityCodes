#include <stdio.h>

 
int main ( )
{
    int b10 , b3 =  0 , i, res1, res2, res3, res4, res5, res6, res7;
    scanf ( "%d" ,  & b10 ) ;

    if (b10 % 3 == 0) {
      res1 = 0;
    } else {
      res1 = b10 % 3;
    }
    if ((b10 / 3) % 3 == 0) {
      res2 = 0;
    } else {
      res2 = (b10 / 3) % 3;
    }
    if ((b10 / 9) % 3 == 0) {
      res3 = 0;
    } else {
      res3 = (b10 / 9) % 3;
    }if ((b10 / 27) % 3 == 0) {
      res4 = 0;
    } else {
      res4 = (b10 / 27) % 3;
    }
    if ((b10 / 81) % 3 == 0) {
      res5 = 0;
    } else {
      res5 = (b10 / 81) % 3;
    }if ((b10 / 243) % 3 == 0) {
      res6 = 0;
    } else {
      res6 = (b10 / 243) % 3;
    }
    if ((b10 / 729) % 3 == 0) {
      res7 = 0;
    } else {
      res7 = (b10 / 729) % 3;
    }
    printf("%d %d %d %d %d %d %d\n",  res7, res6, res5, res4, res3, res2, res1);

    return 0;
}