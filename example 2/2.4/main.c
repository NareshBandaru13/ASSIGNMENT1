#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
FILE*  ptr;
double x;
int count = 0;
long double sum=0;
char c[10];
ptr = fopen("gau.dat","r");
while(fgets(c,sizeof(c),ptr) != NULL){
   x = atof(c);
    sum = sum + x;
    count += 1;   
}
 fseek(ptr, 0,SEEK_SET);
double  mean = sum/count;
sum =0;
while(fgets(c,sizeof(c),ptr) != NULL){
   x = atof(c);
    sum += (x-mean)*(x - mean);  
}   

 double  var = sum/count;
printf("mean = %lf\n",mean);
printf("var = %lf\n",var);
fclose(ptr);
  return 0;
}