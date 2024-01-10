#include <stdio.h>
#include <math.h>


int main()
{
    int n;
    scanf("%d", &n);
    int granica = 0;
    
    for(int i = 0; i <= n*2; i++){
       
       int   broj = 1;
        for(int j = 0; j <= granica; j++){
            if(j == 0 || j == granica)
            putchar('*');
            else{
                if(j < granica/2){
                    printf("%d",broj);
                    broj++;
                }else{
                    printf("%d",broj);
                    broj--;
                }
            }
        }
         if(i < n){
            granica+=2;    
        }else if(i >= n){
            granica-=2;
        }
        
        putchar('\n');
    }

    return 0;
}