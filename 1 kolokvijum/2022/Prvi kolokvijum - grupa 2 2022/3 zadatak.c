#include <stdio.h>
#include <math.h>



int main()
{
    int n;
    scanf("%d",&n);
    int br = 1;
    for(int i = 0; i < n*2; i++){
        
        for(int j = 0; j < n+br;j++){
            if(i == 0  && j > i && j < br+n-1){
                putchar('-');
            }else if(i == n*2-1 && j > 0 && j < n*2-1){
                putchar('-');
            }
            else if((j == 0 && (i == 0 || i == n*2-1)) || (j == br+n-1 && (i == 0 || i == n*2-1 || i == n+br-1)) ||
                        (i == n-1 && j == n+br-1)){
                putchar('+');
            }else{
                if(j == 0 || j == n*2-1){
                    putchar('|');
                }else if(i == j){
                    putchar('\\');
                }else if(j == n+br-1 && i < n){
                    putchar('\\');
                }else if(j + i == n*2-1 && i >= n/2){
                    putchar('/');
                }
                else{
                    putchar('.');
                }
            }
        }
        if(br+n < n*2)
        br++;
        putchar('\n');
    }
   
    return 0;
}
/* 2 nacin
 * #include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x = 1;
    int k = n +1;
    int t = (n%2) ? 1 : 0;
    for(int i = 0; i < n*2;i++){
        for(int j = 0; j < n+x;j++ ){
             if((i == 0 || i == n*2-1) && !(j>0 &&  j < n+x-1)){
                putchar('+');
            }else if((j>0 &&  j< n+x) && (i == 0 || i == n*2-1)){
                putchar('-');
            }
            else if(j==0 || j == n+x-1){
                if(x == n && j == n+x-1 && i < x)
                putchar('+');
                else if(n+x-1 == n*2-1 || j ==0)
                putchar('|');
                else
                putchar('\\');

            }else if(i == j){
                putchar('\\');
            }else if(j == k && i >= n/2+t){
               putchar('/') ;
               k--;
            }else
            putchar('.');
        }
        if(x < n){
            x++;
        }

        putchar('\n');
    }

    return 0;
}
