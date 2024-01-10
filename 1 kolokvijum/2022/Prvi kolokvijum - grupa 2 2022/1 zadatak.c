//  Ulaz : 123  242  347  1631 1231 2420 43127 7512132 0
// Izlaz : 123  22   347  131  131  40   17    5232


#include <stdio.h>
#include <math.h>
int velicina(int arg){
    int n = 0;
    while(arg){
        n++;
        arg/=10;
    }

    return n;
}

int pom(int arg){
    int stepen = velicina(arg);
    int i = (stepen%2) ? 1 : 0;
    int suma = 0;
    while(arg){
        if(i%2){
            suma += arg%10;
        }
        i++;
        arg/=10;
    }

    return pow(suma,stepen);
}

int izbaci(int arg, int cifre){
    int konacni = 0;
    int stepen = 0;

    while(arg){
        int tmp = cifre;
        int flag = 1;
        while(tmp){
            if(arg%10 == tmp%10){
                flag = 0;
                break;
            }
            tmp/=10;
        }
        if(flag){
            konacni += (arg%10)*pow(10,stepen);
            stepen++;
        }
        arg/=10;
    }
    return konacni;
}

int main()
{
    int x;

    while(1){
        scanf("%d",&x);
        if(x == 0)
        break;

        int kvadrat = pom(x);
        printf("%d ", izbaci(x,kvadrat));


    }

    return 0;
}