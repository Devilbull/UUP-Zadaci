#include <stdio.h>
#include <string.h>
#define MAXN 100
 
void removeSubstr (char *string, char *sub) {
    char *match;
    int len = strlen(sub)+1;
    while ((match = strstr(string, sub))) {
        
        *match = '\0';
        strcat(string, match+len);
    }
}
int removeDuplicates(char str[][MAXN], int n, char tmp[][MAXN]){
    int index = 0;
    
    for(int i = 0; i < n; i++ ){
        int j;
        
        for(j = 0; j < i; j++){
            if(strcmp(str[i],str[j]) == 0)
            break;
        }
        
        if(i == j)
        strcpy(tmp[index++], str[i]);
    }
    return index;
    
}
 
int main(int argc, const char *argv[]) {
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
    
    char niz1[MAXN][MAXN];
    
    int n1 = removeDuplicates(words,wordCount,niz1);
    int niz2[MAXN];
    int maxPo = 0;
    int n2 = 0;
    for(int i = 0; i < n1; i++){
        int x = 0;
        for(int j = 0; j < wordCount; j++){
            if(strcmp(niz1[i],words[j]) == 0){
                x++;
                niz2[i] = x;
                if(x > maxPo)
                maxPo = x;
            }
        }
    }
    char strK[MAXN];
    for(int i = 0; i < wordCount; i++){
        strcat(strK,words[i]);
        strcat(strK," ");
    }
    for(int i = 0; i < n1; i++){
        if(niz2[i] < maxPo){
            removeSubstr(strK,niz1[i]);
            wordCount-=niz2[i];
        }
    }
    
    
    puts(strK);
    
    //removeSubstr(test, "woods");
    // for(int i = 0; i < wordCount; i++){
    //     printf("%s ",words[i]);
    // }
    return 0;
}