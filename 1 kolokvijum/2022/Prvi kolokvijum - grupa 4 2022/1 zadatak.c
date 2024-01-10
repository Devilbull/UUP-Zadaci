#include <stdio.h>

// Ulaz: 12 23
// Izlaz: 6 14 10 9 7 18 6 20 7 11 14 24

int pom(int arg, int n){
    int zbir = 0;
    for(int i = 1; i <= arg; i++){
        if(arg%i == 0){
            zbir += i;
            n--;
        }
        if(n == 0)
        break;
    }
    
    return zbir;
    
}

int main()
{
    int x, y;
    scanf("%d%d", &x,&y);
    
    for(int i = x; i <= y;i++){
        printf("%d ", pom(i,3));
    }
    putchar('\n');
    

    return 0;
}