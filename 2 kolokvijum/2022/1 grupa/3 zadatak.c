//pravac jug jugozapad moj zdrav zivot moja pravila
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#define MAXN 1001

void podstring(char *str1, char *str2){
    int n = strlen(str1);
    int jeste = 0;
    char tmp[MAXN];
    int t = 0;
     for(int i = 0; i < n; i++){
        for(int j = i; j<n;j++){
            if(abs(i-j) >= 2){
                for(int k = i; k <= j;k++){
                tmp[t] = str2[k];
                t++;
                if(t>2){
                    if(strstr(str1,tmp)){
                        if(strlen(tmp) >= 3){
                        printf("%s %s\n", str1, str2);
                        return;}
                    }
                }
            }
           // printf("%s %d \n", tmp, i);
            t=0;
            tmp[0] ='\0';
            
            
            }
            
        }
    }

    
}



int main()
{
    
    char str[100];
    char words[MAXN][MAXN]; 
    int wordCount = 0;

    fgets(str, sizeof(str), stdin); 

   
    char* token = strtok(str, " \n");
    while (token != NULL && wordCount < MAXN) {
        strcpy(words[wordCount], token); 
        wordCount++;
        token = strtok(NULL, " \n");
    }
    
    
    for(int i = 0; i < wordCount; i++){
        for(int j = i+1; j < wordCount; j++){
            podstring(words[i],words[j]);
        }
    }
    
  
    return 0;
}
