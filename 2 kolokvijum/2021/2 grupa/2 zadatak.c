
#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
/*
2 6 1 4
3 5 6 8
4 1 8 0
9 6 3 7

9 2 6 7
4 1 8 6
0 5 6 8
2 0 8 4
*/
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int n;
    int mat[MAXN][MAXN];
    scanf("%d",&n);
    int maTmp[MAXN][MAXN];
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
            maTmp[i][j] = mat[i][j];
        }
    }
    
      for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            if(i != j && i + j != n - 1){
                int levo,desno,dole,gore;
                levo = maTmp[i][j-1];
                desno = maTmp[i][j+1];
                dole = maTmp[i+1][j];
                gore = maTmp[i-1][j];
                int max = 0;
                if(levo%2 == 0){
                    max = (max < levo)? levo : max;
                }
                if(desno%2 == 0){
                    max = (max < desno)? desno : max;
                }
                if(dole%2 == 0){
                    max = (max < dole)? dole : max;
                }
                if(gore%2 == 0){
                    max = (max < gore)? gore : max;
                }
            
                mat[i][j] = max;
            }
        }
       
    }
    
    int g = 0;
    int d = n-1;
    if(n%2 == 0){
        for(int i = 0; i < n; i++){
        if(i < n/2){
           swap(&mat[g][i],&mat[d][i]);
           g++;
           d--;
        }else{
           g--;
           d++; 
           swap(&mat[g][i],&mat[d][i]);
            }
        }
    }else{
        for(int i = 0; i < n; i++){
        if(i < n/2){
           swap(&mat[g][i],&mat[d][i]);
           g++;
           d--;
        }else{
           swap(&mat[g][i],&mat[d][i]);
           g--;
           d++; 
            }
        }
    }
    
    
    putchar('\n');
     for(int i = 0; i < n;i++){
        for(int j = 0; j < n; j++){
            printf("%d ",mat[i][j]);
        }
        putchar('\n');
    }
    
    return 0;
}