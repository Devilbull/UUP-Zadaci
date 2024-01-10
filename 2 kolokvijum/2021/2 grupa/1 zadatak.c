/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

double iterativno(int n){
    if(n == 0)
    return 0;
    if(n%2 == 0){
        char ch = 'A'+n/2-1;
    char plus = 'A'+n/2;
    double suma = plus;
    double br = n/2;
    for(int i = 2; i <=n; i++){
        if(i%2){
            plus++;
             
            suma = plus + br/suma;
            
        }else{
             
            suma = ch + br/suma;
            ch--;
        }
        if(i < n/2+1){
            br--;
        }else
            br++;
        
        }
        return suma;
    }
    
    else{
    char ch = 'A'+n/2;
    char plus = 'A'+n/2;
    double suma = ch;
    double br = n/2;
    
    ch--;
        for(int i = 2; i <=n; i++){
        if(i%2==0){
            plus++;
            
            suma = plus + br/suma;
            
        }else{
             
            suma = ch + br/suma;
            ch--;
        }
        if(i < n/2+1){
            br--;
        }else if(i == n/2+1){
            continue;
        }else{
            br++;
            }
        }
        return suma;
    }
    
}

double rekurentno(int n, double suma,double br, char plus, char ch,int tmp){
   if(tmp%2){
       if(n == 0)
   return suma;
    if(n > tmp/2){
            br--;
        }else if(n == tmp/2){
            
        }else{
            br++;
            }
        
   if(n%2==0){
       
       return rekurentno(n-1,plus + br/suma,br ,plus+1,ch,tmp);
   }else{
       
       return rekurentno(n-1,ch + br/suma,br ,plus,ch-1,tmp);
   }
   }else{
       if(n == 0)
        return suma;
    if(n > tmp/2){
            br--;
        }
            
        else{
            br++;
            }
        
   if(n%2==0){
       
       return rekurentno(n-1,plus + br/suma,br ,plus+1,ch,tmp);
   }else{
       
       return rekurentno(n-1,ch + br/suma,br ,plus,ch-1,tmp);
   }
   }
   
   
}

int main()
{
    int n;
    scanf("%d",&n);
    
    printf("%lf\n", iterativno(n));
   if(n%2 == 0){
    char ch = 'A'+n/2;
    char plus = 'A'+n/2;
    double suma = ch;
    double br = n/2;
    ch--;   
    printf("%lf\n", rekurentno(n,suma,br,plus,ch,n));
   }else{
    char ch = 'A'+n/2-1;
    char plus = 'A'+n/2;
    double suma = plus;
    double br = n/2;
    plus++;
    printf("%lf\n", rekurentno(n-1,suma,br+1,plus,ch,n));
   }
   
    return 0;
}
