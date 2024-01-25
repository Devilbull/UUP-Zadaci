//
// Created by Milos on 1/24/2024.
//
#include <stdio.h>
#include <string.h>
#define  MAXN 100

// P: asadadio
// S: gladansam
int main(){
    char p[MAXN], s[MAXN];
    fgets(p,MAXN,stdin);
    fgets(s,MAXN,stdin);

    p[strlen(p)] = '\0';
    s[strlen(s)] = '\0';

    int nS = strlen(s);
    int nP = strlen(p);
    printf("%d %d\n", strlen(s), nS);
    for(int i = 0; i < nS; i++){
        char ch = s[i];
        int numCh = 0;
        for(int j = 0; j < nP; j++){
            if(p[j] == ch)
                numCh++;
        }
        if(numCh){
            for(int k = 0; k < numCh; k++){
                strcat(s,&ch);
            }
            numCh = 0;
        }
    }

    printf("%s\n", s);


}

