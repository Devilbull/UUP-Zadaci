#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void proveri(int **mat,int n,int  m, int pI, int pJ, int d){
    int glu = mat[pI][pJ];//T
    int gdu = mat[pI][m-1];//T
    int dlu = mat[n-1][pJ];
    int ddu = mat[n-1][m-1];//T
   // printf("\n glu %d gdu %d dlu %d ddu %d\n",glu,gdu,dlu,ddu);
    int jeste = 0;
    for(int i = pI; i < n; i++){
        for(int j = pJ; j < m; j++){
            int x = mat[i][j];
          //  printf("%d ", x);
            if(x != glu && x != gdu && x != dlu && x != ddu){
                jeste++;
            }
        }
       // putchar('\n');
    }
   //printf("%d %d\n", jeste, d*d-4);
    if(jeste == d*d-4)
    printf("(%d, %d) dimenzija %d x %d\n", pI, pJ, d,d);
    
}


int main()
{   
    int n, m;
    scanf("%d%d",&n,&m);
    int **mat=(int **)malloc(m*sizeof(int));
    for(int i=0;i<n;i++)
        mat[i]=(int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int manji = n > m ? m : n;
    
    for(int d = 3; d <= manji; d++){
        for(int i = 0; d+i-1 < n;i++){
            for(int j = 0; d + j - 1 < m;j++){
                proveri(mat, d+i, d+j, i,j,d);
                
            }
        }
        
    }
    
    
    return 0;
}