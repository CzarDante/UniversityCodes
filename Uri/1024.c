#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000], str1[1000];
    int qtd_strings,tamanho_string,inverte,i;
    scanf("%d",&qtd_strings);
    getchar();
    while (qtd_strings--)
    {
        gets(str);
        tamanho_string=strlen(str);
        for(i = 0; i < tamanho_string; i++)
        {
            if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z')
                str[i] = str[i] + 3;
        }
        inverte=0;
        for(i=tamanho_string-1;i>=0;i--)
        {
            str1[inverte] = str[i];
            inverte++;
        }
        str1[inverte] = '\0';
        for(i=tamanho_string/2;i<tamanho_string;i++)
        {
            str1[i] =  str1[i] - 1;
        }
        printf("%s\n",str1);
    }
    return  0;
}