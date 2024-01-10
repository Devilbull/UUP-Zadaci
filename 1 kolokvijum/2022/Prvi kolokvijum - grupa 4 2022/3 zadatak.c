
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int l = n-1;
    int d = n-1;
    
    for(int i = 0; i < n-1; i++){
        for(int j =0; j < n*2-1; j++){
            if(i == 0 && j == n-1)
            putchar('^');
            else if(j == l && i != 0){
            putchar('/');
            }else if(j == d && i != 0){
            putchar('\\');
            }else if(j < d && j > l && i != 0){
            putchar('*');}
            else{
            putchar('.');}
            
        }   l--;
            d++;
        putchar('\n');
    }
    int granica = n*2-1;
    for(int i = 0; i < n-1; i++){
        for(int j =0; j < n*2-1; j++){
            if(i == 0 && (j <= n/2 || j >= granica - (n/2)-1))
            putchar('-');
            else if(j<n/2 || j > granica - (n/2)-1){
            putchar('.');
            }else if(j == n/2 || j == granica - (n/2)-1){
            putchar('|');
            }
            else
            putchar('*');
        }
        putchar('\n');
    }
    for(int j =0; j < n*2-1; j++){
       if( (j >= n/2 && j <= granica - (n/2)-1))
            putchar('-');
        else if(j<n/2 || j > granica - (n/2)-1)
            putchar('.'); 
    }
    return 0;
}