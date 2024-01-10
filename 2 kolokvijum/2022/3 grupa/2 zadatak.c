#include <stdio.h>
#define MAXN 100
/*
4 5
1 2 2 2 
6 3 1 1 
5 8 1 1 
6 3 3 1 
7 2 1 2

6 2 1 2
7 3 3 1
1 8 1 1
6 3 2 1
5 2 1 2
*/
int proveri(int mat[MAXN][MAXN], int j, int n){
    
    int tmp = n-1;
    for(int i = 0, k = tmp; i < n/2;i++,k--){
       
        if(mat[i][j] != mat[k][j]){
            return 0;
        }
    }
    return 1;
}
int maximum(int mat[MAXN][MAXN], int j, int n){
    
    
    int max = -1;
    for(int i = 0; i < n;i++){
        
        if(max  < mat[i][j]){
            max = mat[i][j];
        }
    }
    return max;
}
void rotiraj(int niz[MAXN][MAXN], int j, int n){
    
    int tmp = niz[n-1][j];
    for(int i = n-1; i > 0; i--){
        niz[i][j] = niz[i-1][j];
        
         
    }
    niz[0][j] = tmp;
    
    
}

int main()
{
   int n, m;
   scanf("%d%d",&m, &n);
   int mat[MAXN][MAXN];
   
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    
   
    for(int j = 0; j < m; j++){
      int flag = proveri(mat,j,n);
      
      if(!flag){
          int max = maximum(mat,j,n);
          max%=n;
          
          for(int k = 0; k < max; k++){
              
              rotiraj(mat,j,n);
          }
      }
    }
    putchar('\n');
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ",mat[i][j]);
        }
        putchar('\n');
    }
    
    return 0;
}
