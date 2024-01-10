//#include <stdio.h>
////2543670 14862 14761 246 0
////4367025 14862 61147 462
//
//int prost(int br);
//
//int pom(int arg){
//    int a[20];
//    int n = 0;
//    while(arg){
//        a[n] = arg%10;
//        arg/=10;
//        n++;
//    }
//    int maxProsti = 1;
//
//    for(int i =0; i < n/2; i++){
//        int suma = a[i] + a[n-i-1];
//
//        if(suma > maxProsti && prost(suma))
//         maxProsti = suma;
//    }
//    int sredina = a[n/2];
//    if(n%2 && sredina > maxProsti && prost(sredina))
//         maxProsti = sredina;
//
//    if(maxProsti == 1)
//    return n;
//
//    return maxProsti;
//}
//
//int prost(int br){
//    for(int i = 2; i <= br/2; i++){
//        if(br%i == 0)
//        return 0;
//    }
//
//    return 1;
//}
//
//void rotiraj(int a[], int n){
//    for(int i =0; i < n-1; i++){
//        int tmp = a[i];
//        a[i] = a[n-1];
//        a[n-1] = tmp;
//    }
//}
//
//int ciklicnoZa(int broj, int k){
//    int a[20];
//
//    int n = 0;
//    while(broj){
//        a[n] = broj%10;
//        broj/=10;
//
//        n++;
//
//
//    }
//    for(int i = 0; i < n/2;i++){
//        int tmp = a[i];
//        a[i] = a[n-i-1];
//        a[n-i-1] = tmp;
//    }
//
//    int ostatak = k%n;
//
//    while(ostatak--){
//        rotiraj(a,n);
//
//    }
//    int konacni = a[0];
//    for(int i =1; i <n; i++){
//        konacni=konacni*10+a[i];
//    }
//    return konacni;
//}
//
//int kojiProsti(int y){
//    for(int i = 2; i < 10000; i++){
//        if(prost(i)){
//            y--;
//            if(y == 0)
//            return i;
//        }
//    }
//}
//
//int main()
//{
//    int niz[1000];
//    int n;
//    for(int i = 0; i < 1000; i++){
//        int x;
//        scanf("%d", &x);
//        if(x == 0){
//            n = i;
//            break;
//        }
//        niz[i] = x;
//    }
//
//    for(int i = 0; i < n; i++){
//        int k;
//
//        k = kojiProsti(pom(niz[i]));
//        printf("%d ",  ciklicnoZa(niz[i], k));
//    }
//    putchar('\n');
//
//    return 0;
//}

//Bez upotrebe nizova
#include <stdio.h>
#include <math.h>
//2543670 14862 14761 246 0
//4367025 14862 61147 462

int prost(int br);
int rotiraj(int n);
int kojiProsti(int y);
int velicina(int br);

int pom(int arg){
    int n = velicina(arg);

    int l;
    int d;
    int prMAXSuma = -1;

    int tmp1 = arg;
    int tmp2 = rotiraj(arg);
    int tmpN = n;
    while(tmpN > n/2+1){
        l = tmp1%10;
        d = tmp2%10;
        tmp1/=10;
        tmp2/=10;
        int suma = l + d;
        if(prost(suma)){

           if(prMAXSuma < suma)
           prMAXSuma = suma;
        }
        tmpN--;
    }

    if(n%2){
        l = tmp1%10;
        if(prost(l)){
           if(prMAXSuma < l)
           prMAXSuma = l;
        }
    }


    if(prMAXSuma == -1){
        return kojiProsti(n);
    }else{
        return kojiProsti(prMAXSuma);
    }


}

int rotiraj(int n){
    int br = 0;

    while(n){
        br = br*10 + n%10;
        n/=10;
    }

    return br;
}

int prost(int br){
    for(int i = 2; i <= br/2; i++){
        if(br%i == 0)
        return 0;
    }

    return 1;
}

int kojiProsti(int y){
    for(int i = 2; i < 10000; i++){
        if(prost(i)){
            y--;
            if(y == 0)
            return i;
        }
    }
}

int ciklicno(int br, int k){
    int n = velicina(br);
   k = k%n;

    while(k){
        k--;
        int x = br%10;
        br/=10;

        x = x*pow(10,n-1);

        br = br + x;

    }

    return br;
}

int velicina(int br){
    int n = 0;
    while(br){
        n++;
        br/=10;
    }
    return n;
}

int main()
{
    int x;
    scanf("%d",&x);
    while(x != 0){

       int k =  pom(x);
       printf("%d ", ciklicno(x,k));
       scanf("%d",&x);
    }

    putchar('\n');

    return 0;

}