#include <stdio.h>
#include <math.h>
int prost(int n){
    for(int i = 2; i <= sqrt(n);i++){
        if(n%i == 0)    {
            return 0;
        }
    }
    
    return 1;
}

int pom(int p, int k){
    int poslednjiManji;
    int prviVeci;
    int mid = (p+k)/2;
    
    for(int i = p; i < mid; i++){
        if(prost(i)){
            poslednjiManji = i;
        }
    }
    
    for(int i = mid; i < k ;i++){
        if(prost(i)){
            prviVeci = i;
            break;
        }
    }
    
    int sredina = (mid - poslednjiManji > prviVeci - mid) ? prviVeci : poslednjiManji;
    
    
    return sredina;
}

void kolikoIhJe(int sredina, int *manji, int *veci, int p, int k){
    
    for(int i = p; i < sredina; i++){
        if(prost(i) && sredina > i){
            (*manji)++;
        }
    }
    
    for(int i = sredina; i <= k ;i++){
        if(prost(i) && sredina < i){
            (*veci)++;
        }
    }
    
}

int main()
{
    int p;
    int k;
    scanf("%d%d", &p,&k);
    
    int manji = 0;
    int veci = 0;
    int sredina = pom(p,k);
    
    kolikoIhJe(sredina, &manji, &veci, p, k);
    
    printf("Manjih %d, vecih %d\n", manji,veci);

    return 0;
}