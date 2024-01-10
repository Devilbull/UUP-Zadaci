#include <stdio.h>
#include <math.h>

double rekurzivno(int n, double suma){
    if(n==0)
    return suma;
    
    if(n%2){
        double razlomak = n/(n+1.0);
        return rekurzivno(n-1, sqrt(razlomak +(n+1.0)*suma));
    }else{
         double razlomak = n/((n+1.0)*(n+1));
        return rekurzivno(n-1, sqrt(razlomak +suma));
    }
}


double iterativno(int n){
    double suma = 0;
    double razlomak=0;
    for(int i = n; i > 0; i--){
        if(i%2){
            razlomak = i/(i+1.0);
            suma = sqrt(razlomak+(i+1)*suma);
        }else{
            razlomak = i/((i+1.0)*(i+1));
            suma = sqrt(razlomak+suma);
        }
    }
    
    
    return suma;
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    printf("%lf\n",rekurzivno(n,0));
    printf("%lf\n",iterativno(n));

    return 0;
}