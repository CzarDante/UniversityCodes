#include <stdio.h>


typedef struct cadastro
{
    int matricula;
    float n1,n2,media;

}cadastro;

float media(float n1, float n2){
    return (n1+n2)/2;
}

int main(){
    cadastro x;
    //cadastro * y;//

    scanf("%f",&x.n1);    
    scanf("%f",&x.n2);
    x.media = media(x.n1, x.n2);
    printf("\n %.2f", x.media);
    return 0;
}
