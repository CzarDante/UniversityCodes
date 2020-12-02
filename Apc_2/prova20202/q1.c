#include<stdio.h>

int main() {
   FILE *fp1, *fp2;
   int ch1, ch2;
   char nomearquivo1[40], nomearquivo2[40];
 
   printf("nome do primeiro arquivo :");
   gets(nomearquivo1);
 
   printf("nome do segundo arquivo:");
   gets(nomearquivo2);
 
   fp1 = fopen(nomearquivo1, "r");
   fp2 = fopen(nomearquivo2, "r");
 
   if (fp1 == NULL) {
      printf("\n Problemas na abertura do arquivo");
      exit(1);
   } else if (fp2 == NULL) {
      printf("\n Problemas na abertura do arquivo");
      exit(1);
   } else {
      ch1 = getc(fp1);
      ch2 = getc(fp2);
 
      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
         ch1 = getc(fp1);
         ch2 = getc(fp2);
      }
 
      if (ch1 == ch2)
         printf("Os arquivos sao iguais");
      else if (ch1 != ch2)
         printf("Os arquivos nao sao iguais");
 
      fclose(fp1);
      fclose(fp2);
   }
   return (0);
}