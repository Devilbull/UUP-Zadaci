#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 100

// Primer: 4385 53913 335
// Rezultat: 5506 65234 456


int main()
{   
    char str[10000];
   fgets(str, sizeof(str), stdin); 
   
   int n = strlen(str)-1;
   int razmak = 0;
   for(int i =0; i<=n; i++){
       if(str[i] == ' ' || i == n){
           int k = i;
           int br = 1;
           
           for(int j = razmak; j < k; ){
               if((str[j]>='0' && str[j] <='9') && (str[k]>='0' && str[k] <='9')){
                   int l = str[j]-'0';
                   int d = str[k]-'0';
                  // printf("%c %c \n", str[j], str[k]);
                   l = (l+br)%10;
                   d = (d+br)%10;
                   str[j] = l + '0';
                   str[k] = d + '0';
                   br++;
                   j++;
                   k--;
               }else if(!(str[j]>='0' && str[j] <='9') && (str[k]>='0' && str[k] <='9')){
                   j++;
                   
               }else if((str[j]>='0' && str[j] <='9') && !(str[k]>='0' && str[k] <='9')){
                   k--;
               }else{
                   j++;
                   k--;
               }
           }
           if((i - razmak)%2){
               int srd = str[razmak + (i-razmak)/2] - '0';
               str[razmak + (i-razmak)/2] = (srd+br)%10 + '0';
           }
           razmak = i+1;
       }
   }
  printf("%s\n", str);
  
    return 0;
    
    
}