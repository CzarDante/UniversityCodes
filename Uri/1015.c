#include <stdio.h>

float raiz_quadrada (float distance)
{
    int n;
    float recorre = distance;
   
    for (n = 0; n < 10; ++n)
          recorre = recorre/2 + distance/(2*recorre);
           
    return(recorre);    
}  

int main(){
    double x1, x2, y1, y2, distance, raiz;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    distance = ((x2 -x1)*(x2-x1))+((y2-y1)*(y2-y1));

    printf("%0.4lf\n", raiz_quadrada(distance));
    return 0;
}

