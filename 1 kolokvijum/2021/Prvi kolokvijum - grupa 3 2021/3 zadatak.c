
#include <stdio.h>
#include <math.h>


int main()
{
    int n;
    scanf("%d", &n);
    int plus;
    int x = 0;
    for(int i = 0; i < n; i++){
        char chV = 'A';
        char chM = 'a';
        if(n%2 == 0){
            if(i < n/2){
        plus = plus + x;
        x++;
         
        }else if(i > n/2) {
          
        plus =plus - x;
        x--;
            }else{
            x--;
            
         }
            
        }else{
           if(i < n/2){
        plus = plus + x;
        x++;
         
        }else if(i > n/2) {
        plus =plus - x;
        x--;
        }else{
             plus = plus + x;
        }
        }
        for(int j = 0; j < n; j++){
            if(( j < i || j >= n -i) && (i < n/2)){
                putchar(chM+i);
            }else if((i >= n/2) && (j > i || j < n - i-1) ){
                 putchar(chM+i);
            }
            else {
                
                putchar(chV+plus);
            }
        }
        
        putchar('\n');
    }

    return 0;
}
