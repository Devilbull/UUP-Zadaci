#include <stdio.h>
#include <limits.h>

// Ulaz: {32 53 12} (31 6 2) 123 {355} (3 7)
// Izlaz: 166

// {} razlika max i min flag 0
// () najmanji parni flag 1
// bez zagrada samo se dodaje na zbir flag 2

int main()
{
    char ch;

    int zbir = 0;
    int broj = 0;
    char prev;
    char prevZ;
    int flag = 2;
    int min = INT_MAX;
    int minParni = INT_MAX;
    int max = INT_MIN;
    int flagCounter2 = 0;
    while((ch = getchar())!= '\n'){
        printf("flag %d ", flag);
        if(flag == 0){

            if(prev == ' '){
                if(broj > max)
                    max = broj;
                if(broj < min)
                    min = broj;
                broj = 0;
            }if(ch >= '0' && ch <='9'){
                broj = broj*10 + ch-'0';
            }


        }else if(flag == 1){

            if(prev == ' '){
                if(broj%2 == 0){
                    if(broj < minParni)
                        minParni = broj;
                }
                broj = 0;
            }if(ch >= '0' && ch <='9'){
                broj = broj*10 + ch-'0';
            }


        }else if(flag == 2){

            if(ch >= '0' && ch <='9'){
                broj = broj*10 + ch-'0';
            }
            if(prev == ' ' && flagCounter2 > 2){
                printf(" 2. z %d %d broj\n", zbir, broj);
                zbir += broj;
                broj = 0;
            }
            flagCounter2++;
        }



        prev = ch;
        //{32 53 12} (31 6 2) 123 {355} (3 7)
        if(ch == '{'){
            flag = 0;
            flagCounter2 = 0;
            if(minParni != INT_MAX){
                if(broj < minParni)
                    minParni = broj;
                printf("{ mP %d \n", minParni);
                zbir += minParni;
                minParni = INT_MAX;
            }

        }else if(ch == '('){
            flag = 1;
            flagCounter2 = 0;
            if(min != INT_MAX && max != INT_MIN){
                if(broj > max)
                    max = broj;
                if(broj < min)
                    min = broj;
                broj = 0;
                printf("( z %d  min %d max %d \n", zbir,min, max);
                zbir = zbir + (max-min);
                min = INT_MAX;
                max = INT_MIN;
            }
            if(broj != 0){
                printf("( z %d br %d\n", zbir,broj);
                zbir += broj;
                broj = 0;
            }

        }else if(prev =='}' || prev == ')' || ch == '}' || ch == ')'){

            if(min != INT_MAX && max != INT_MIN){
                if(broj > max)
                    max = broj;
                if(broj < min)
                    min = broj;
                broj = 0;
                printf("%c z %d  min %d max %d \n", prevZ,zbir,min, max);
                zbir = zbir + (max-min);
                min = INT_MAX;
                max = INT_MIN;
            }
            if(minParni != INT_MAX){
                if(broj < minParni)
                    minParni = broj;
                printf("%c z %d mP %d \n", prev,zbir,minParni);
                zbir += minParni;
                minParni = INT_MAX;
                broj = 0;
            }
            if(flag == 0){
                if(broj > max)
                    max = broj;
                if(broj < min)
                    min = broj;
                zbir += (max-min);
                broj = 0;
                min = INT_MAX;
                max = INT_MIN;
            }
            if(flag == 1){
                if(broj%2 == 0)
                if(broj < minParni) {
                    minParni = broj;
                    zbir += minParni;
                }
                broj = 0;
                minParni = INT_MAX;
            }
            flag = 2;
        }
    }
    if(min != INT_MAX && max != INT_MIN){
        zbir = zbir + (max-min);
        min = INT_MAX;
        max = INT_MIN;
    }
    if(minParni != INT_MAX){
        zbir += minParni;
        minParni = INT_MAX;
    }
    if(broj != 0){
        zbir += broj;
    }
    printf("%d\n", zbir);

    return 0;
}
