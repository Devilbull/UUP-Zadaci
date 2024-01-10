#include <stdio.h>
#include <math.h>

//Ulaz : Az(12895)2*&c22[1414](241)[78]
//Izlaz : Az(30745)2*&c22[0](651)[4]

int f1(int broj){
    int kvadrat = pow(broj,2);
    int max = -1;
    
    while(broj){
        int x = broj%10;
        if(max < x)
        max = x;
        broj/=10;
    }
    
    return kvadrat%max;
}

int f2(int broj){
    
    int poslednja = broj%10;
    broj/=10;
    
    int pre;
    int y = poslednja + broj%10;
    int zbir = zbir*10 + y%10;
     
    
    while(broj){
        int x = broj%10;
        broj/=10;
         y = x + broj%10;
        zbir = zbir*10 + y%10; 
       
    }
    zbir/=10;
    int konacni = 0;
    while(zbir){
        konacni = konacni*10 + zbir%10;
        zbir/=10;
    }
    
    return konacni*10+poslednja;
}

int main()
{
   char ch;
   int flag = 0;
   int broj = 0;
   // flag = 0 nista
   // flag = 1 ()
   // flag = 2 []
   char prethodni;
   while((ch = getchar()) != '\n'){
       if(prethodni == '(')
        flag = 1;
       if(prethodni == '[')
        flag = 2;
       if(prethodni == ']' || prethodni == ')'){
          
       flag = 0;
         if(prethodni == ']'){
            printf("%d",f1(broj));
            broj = 0;
             
         }else if(prethodni == ')'){
             printf("%d",f2(broj));
            broj = 0;
         }
         putchar(prethodni);
       }
       if(flag == 0){
       putchar(ch);
       prethodni = ch;
       }
       else if(flag == 1){
           if(ch >='0' && ch <='9')
           broj= broj*10 + (ch-'0');
           prethodni = ch;
       }else if(flag == 2){
           if(ch >='0' && ch <='9')
           broj= broj*10 +( ch-'0');
           prethodni = ch;
       }
   }
   
        if(prethodni == ']'){
            printf("%d",f1(broj));
            broj = 0;
        }else if(prethodni == ')'){
             printf("%d",f2(broj));
            broj = 0;
        }
         putchar(prethodni);
   
    return 0;
}

/* 2 nacin
// Ulaz : Az(12895)2*&c22[1414](241)[78]
// Izlaz : Az(30745)2*&c22[0](651)[4]

//  flag = 0 nista ne radis
//  flag = 1 ( sabiras susedne
//  flag = 2 [ kvadrira se broj i moduje se sa najvecom cifrom
#include <stdio.h>
#include <math.h>

int main()
{
    char ch;
    int flag = 0;
    int broj = 0;
    int preBr = -1;
    int max = -1;
    while((ch = getchar()) != '\n'){
        if(ch == '('){
            putchar(ch);
            flag = 1;

        }else if(ch == '['){
            putchar(ch);
            flag = 2;
        }

        if(ch == ')'){
            printf("%d",preBr);
            preBr = -1;
            flag = 0;
        }
        else if (ch == ']'){
            printf("%d", ((int)pow(broj,2))%max);
            broj = 0;
            max = -1;
            flag = 0;
        }

        if(flag == 1){
            if(ch >='0' && ch <= '9'){
                if(preBr != -1){

                    printf("%d",(preBr+(ch-'0'))%10);
                    preBr = ch-'0';
                }else{
                    preBr = ch-'0';
                }
            }

        }else if(flag == 2){
            if(ch >='0' && ch <= '9'){
                broj = broj*10 + ch-'0';
                if(max < ch-'0')
                max = ch - '0';
            }

        }else{
            putchar(ch);
        }

    }

    return 0;
}