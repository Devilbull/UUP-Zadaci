#include <stdio.h>
#include <math.h>
#include <limits.h>



int main()
{
    int n;
    scanf("%d",&n);
    
    int granica = n*2-1;
    
    for(int i = 0; i< n -1;i++){
        for(int j = 0; j < granica;j++){
            if(j < n/2 || j >= granica-(n/2)){
                putchar('.');
            }else if(i == 0){
                putchar('-');
            }else if(j == n/2 || j == granica-(n/2)-1){
                putchar('|');
            }else{
                putchar('*');
            }
            
        }
        putchar('\n');
    }
    int levo = 0;
    int desno = granica-1;
    for(int i = 0; i< n;i++){
        for(int j = 0; j < granica;j++){
            if(j== levo && j != desno){
                putchar('\\');
            }else if(j == desno && j != levo){
                 putchar('/');
            }else if(j > levo && j < desno){
                putchar('*');
            }else if(levo == desno && j == n-1 ){
                
                putchar('V');
            }
            else{
                putchar('.');
            }
        }
        putchar('\n');
        levo++;
        desno--;
    }
    return 0;
}