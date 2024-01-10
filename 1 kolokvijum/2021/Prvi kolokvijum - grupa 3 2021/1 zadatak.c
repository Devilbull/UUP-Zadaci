
// Ulaz: 819 1030
// Izlaz: 819 824 837 864 910 911 912 913 914 915 916 917 918 919
// 920 928 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 1024


#include <stdio.h>
#include <math.h>

int velicin(int arg){
    int i = 0;
    while(arg){
        i++;
        arg/=10;
    }
    return i;
}


int pom(int arg){
    int brCif = velicin(arg);
    if(brCif%2){
        int deljenik = pow(10, brCif/2);
        arg/=deljenik;
        
        return arg % 10;
    }else{
        int deljenik = pow(10, brCif/2-1);
        arg/=deljenik;
        int desni = arg%10;
        arg/=10;
        int levi = arg%10;
        return desni > levi ? desni : levi;
    }
    
}


int main()
{
    int n, m;
    scanf("%d%d", &n,&m);
    
    for(int i = n; i <= m; i++){
        int srednja = pom(i);
        int deljenik = pow(srednja,3);
        if(srednja != 0 && i%deljenik == 0){
         printf("%d ", i );
        }
    }

    return 0;
}