#include <stdio.h>
#include <math.h>

int main(){
    double numero,moedas;
    int num,n50,n20,n10,n5,n2,m1; 
    int m50=0,m25=0,m10=0,m05=0,m01=0;
    scanf("%lf", &numero);
    num=floor(numero);
    moedas=numero-num;
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", num/100);
    n50=num%100;
    printf("%d nota(s) de R$ 50.00\n", n50/50);
    n20=n50%50;
    printf("%d nota(s) de R$ 20.00\n", n20/20);
    n10=n20%20;
    printf("%d nota(s) de R$ 10.00\n", n10/10);
    n5=n10%10;
    printf("%d nota(s) de R$ 5.00\n", n5/5);
    n2=n5%5;
    printf("%d nota(s) de R$ 2.00\n", n2/2);
    m1=n2%2;
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", m1);
    double moeda=moedas;
    for(int i=0;i<15;i++){
        if((moeda-0.5)>=0){
        m50++;
        moeda-=0.5;
        }else{
            if((moeda-0.25)>=0){
                m25++;
                moeda-=0.25;
            }else{
                if((moeda-0.1)>=0){
                    m10++;
                    moeda-=0.10;
                }else{
                    if((moeda-0.05)>=0){
                        m05++;
                        moeda-=0.05;
                    }else{
                        if((moeda-0.01)>=0){
                            m01++;
                            moeda-=0.01;                           
                        }
                    }
                }
            }
        }
    }
    printf("%d moeda(s) de R$ 0.50\n", m50);
    printf("%d moeda(s) de R$ 0.25\n", m25);
    printf("%d moeda(s) de R$ 0.10\n", m10);
    printf("%d moeda(s) de R$ 0.05\n", m05);
    printf("%d moeda(s) de R$ 0.01\n", m01);
    return 0;
}