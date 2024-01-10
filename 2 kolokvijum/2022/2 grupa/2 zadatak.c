#include <stdio.h>
#include <stdlib.h>
/*
Ulaz:
3 6 7 5 3 
5 6 2 9 1  
2 7 0 9 3  
6 0 6 2 6 
1 8 7 9 2        
      
Izlaz: 
2 0 0 1 1
5 6 2 2 2
9 6 6 3 3
9 7 7 5 3
9 8 7 6 6
       */
int main()
{
    int n;
    scanf("%d",&n);
    
    int **p = malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        p[i] = malloc(sizeof(int) *n);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            int x;
            scanf("%d",&x);
            p[i][j] = x;
        }
    }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n;j++){
    //         printf("%d ", p[i][j]);
            
    //     }
    //     putchar('\n');
    // }
    putchar('\n');
    
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n;i++){
           
        int min = p[i][j];
        int indeks;
        for(int k = i; k < n; k++){
            if(min > p[k][j]){
                min = p[k][j];
                indeks = k;
            }
        }
        if(min != p[i][j]){
            int tmp = p[i][j];
            p[i][j] = p[indeks][j];
            p[indeks][j] = tmp;
        }
    
            
        }
    }
   
    for(int i = n-1; i < n; i++){
        for(int j = 0; j < n;j++){
           
        int max = p[i][j];
        int indeks;
        for(int k = j; k < n; k++){
            if(max < p[i][k]){
                max = p[i][k];
                indeks = k;
            }
        }
        if(max != p[i][j]){
            for(int t = 0; t < n; t++){
                int tmp = p[t][j];
                p[t][j] = p[t][indeks];
                p[t][indeks] = tmp;
            }
            
        }
    
            
        }
    }
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n;j++){
            printf("%d ", p[i][j]);
            
        }
        putchar('\n');
    }
    return 0;
}