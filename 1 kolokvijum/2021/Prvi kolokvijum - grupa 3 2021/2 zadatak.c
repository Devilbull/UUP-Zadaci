
// Ulaz: md(q2345q(a31b)g141d)a41(sd45a)sad((145sda)1222)g
// Izlaz: 634

// 0 - obrnuti broj
//
// 1 - samo parne cifre oformi broj

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

int main()
{
    char ch;
    int flag = 0;
    int broj = 0;
    int suma = 0;
    while((ch = getchar()) != '\n'){
        if(ch == '('){
            if(flag%2){
                int n = velicina(broj);
                int stepen = 0;
                
                if(n%2 == 0){
                while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                }}else{
                    broj/=10;
                    while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                 }
                }
                stepen = 0;
            }else{
                int obrnuti = 0;
                while(broj){
                    obrnuti = obrnuti*10 + broj%10;
                    broj/=10;
                }
                suma += obrnuti;
            }
            flag++;
        }else if(ch == ')'){
            if(flag%2){
                int n = velicina(broj);
                int stepen = 0;
                
                if(n%2 == 0){
                while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                }}else{
                    broj/=10;
                    while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                 }
                }
                stepen = 0;
            }else{
                int obrnuti = 0;
                while(broj){
                    obrnuti = obrnuti*10 + broj%10;
                    broj/=10;
                }
                suma += obrnuti;
            }
            flag--;
        }
        if(flag%2){
            if(ch >= '0' && ch <='9'){
                broj = broj*10 + ch - '0';
            }
            if(broj != 0 && !(ch >= '0' && ch <='9')){
                int n = velicina(broj);
                int stepen = 0;
                
                if(n%2 == 0){
                while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                }}else{
                    broj/=10;
                    while(broj){
                    int cifra = broj%10;
                    broj/=100;
                    suma = suma + cifra*(pow(10,stepen));
                    stepen++;
                 }
                }
                stepen = 0;
            }
            
            
        }else{
            if(ch >= '0' && ch <='9'){
                broj = broj*10 + (ch - '0');
            }
            if(broj != 0 && !(ch >= '0' && ch <='9')){
                int obrnuti = 0;
                while(broj){
                    obrnuti = obrnuti*10 + broj%10;
                    broj/=10;
                }
                suma += obrnuti;
            }
        }
    }
    
    printf("%d\n", suma);

    return 0;
}