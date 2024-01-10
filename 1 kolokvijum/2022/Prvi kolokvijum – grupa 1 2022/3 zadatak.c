#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n) ;
    
    for(int i = 0; i < n*2-1; i++){
        char ch = 'A' +n-1;
        int donja = i;
        int gornja = n*2-2-i;
        for(int j =0; j<n*2-1;j++){
            if(j == n-1 || i == n-1){
                if(j<n*2-2)
            printf("%c ",ch+32);
                else
            printf("%c",ch+32);
            }
            else{
                if(j<n*2-2)
            printf("%c ",ch);
                else
            printf("%c",ch);
            }
            if(i < n){
                if(j < donja)
                    ch--;
                else if(j >= gornja)
                    ch++;
                else
                    continue;
            }else{
                if(j < gornja)
                    ch--;
                else if(j >= donja)
                    ch++;
                else
                    continue;
            }
        }
        putchar('\n');
        
    }
    
    return 0;
}
