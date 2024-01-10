
#include <stdio.h>
#include <math.h>
#define MAXN 100

double iterativno(int n){
    double suma = 0;
    double tmp = n;
    
    for(int i = n; i >=1;i--){
        double kvadrat = i*i;
        suma =  tmp/kvadrat + sqrt(suma);
       //printf("%lf %d %lf %lf\n", suma, i, tmp, kvadrat);
       if(n%2){
           if(i < n/2){
           tmp++;
        }else if(i > n/2+1){
           tmp--;
        }else{
            tmp++;
        }
       }else{
           if(i <= n/2){
           tmp++;
        }else if(i > n/2+1){
           tmp--;
        }
       }
       
        if(i == 1)
        suma = sqrt(suma);
        
    }
    
    
    return suma;
    
}
double rekurentno(int n, double suma, double kvadrat, int i,int tmp){
    if(n == 0)
        return suma;
        //printf("%lf %d %d %lf \n",suma, n, i, kvadrat);
    if(tmp%2){
    if(n <= tmp/2+1){
        
          return rekurentno(n-1,sqrt(i/(kvadrat*kvadrat)+suma),kvadrat-1,i+1,tmp);
    }else{
           return rekurentno(n-1,sqrt(i/(kvadrat*kvadrat)+suma),kvadrat-1,i-1,tmp);
    }}else{
        if(n <= tmp/2){
        
          return rekurentno(n-1,sqrt(i/(kvadrat*kvadrat)+suma),kvadrat-1,i+1,tmp);
        }else if(n > tmp/2+1){
           return rekurentno(n-1,sqrt(i/(kvadrat*kvadrat)+suma),kvadrat-1,i-1,tmp);
        }else{
        return rekurentno(n-1,sqrt(i/(kvadrat*kvadrat)+suma),kvadrat-1,i,tmp);
        }
    }
}


int main()
{
   int n;
   scanf("%d", &n);
    double suma = 0;
    printf("%lf\n",iterativno(n));
    printf("%lf\n",rekurentno(n,suma,n,n,n));
    
    return 0;
}