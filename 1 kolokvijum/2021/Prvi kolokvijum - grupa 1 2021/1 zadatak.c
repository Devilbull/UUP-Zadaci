#include <stdio.h>
#include <math.h>

//Ulaz: 8 22
//Izlaz: 7 7 11 11 11 13 13 13 17 17 17 19 19 19 23
int prost(int n);

int pom(int arg){
    int lp;
    int dp;
    for(int i = arg;; i--){
        if(prost(i)){
            lp = i;
            break;
        }
    }
    
    for(int i = arg; 1; i++){
        if(prost(i)){
            dp = i;
            break;
        }
        
    }
    
    if((arg - lp) == (dp - arg))
    return lp;
    
    int minL = arg-lp;
    int minD = dp-arg;
    
    return  minL > minD ? dp : lp;
}

int prost(int n){
    
    
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    
    for(int i = n; i <=m; i++){
        printf("%d ", pom(i));
    }

    return 0;
}