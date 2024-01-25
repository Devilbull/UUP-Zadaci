//
// Created by Milos on 1/24/2024.
//
#include <stdio.h>
#include <stdlib.h>
#define  MAXN 1000

int nadjiMax(int n,int mat[n][n], int i, int j){
    int max = -1;
    //1 gore levo
    for(int k = i-1, t = j-1;k >=0 ;k--,t--){
        if(t < 0)
            break;
        if(mat[k][t] > max)
            max = mat[k][t];

    }
    //2 gore desno
    for(int k = i-1, t = j+1;k>=0;k--,t++){
        if(t >= n)
            break;
        if(mat[k][t] > max)
            max = mat[k][t];

    }
    //3 dole levo
    for(int k = i+1, t = j-1; t >=0 && k >=0;k++,t--){
        if(k >= n)
            break;
        if(mat[k][t] > max)
            max = mat[k][t];
    }
    //4 dole desno
    for(int k = i+1, t = j+1; t < n ;k++,t++){
        if(k >= n)
            break;
        if(mat[k][t] > max)
            max = mat[k][t];
    }
    return max;
}

int main(){
    int n;
    scanf("%d", &n);
    int mat[n][n];
    int tmp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&mat[i][j]);
            tmp[i][j] = mat[i][j];
        }
    }

    putchar('\n');

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           mat[i][j] = nadjiMax(n,tmp,i,j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           printf("%d ", mat[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
