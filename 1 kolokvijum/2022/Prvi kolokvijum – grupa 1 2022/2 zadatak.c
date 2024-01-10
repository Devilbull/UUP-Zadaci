#include <stdio.h>
#include <math.h>

//Ulaz :  ca123ab15C3dE782EfG1228g
//Izlaz : ca246ab3C0dE805EfG12g
int main()
{
    char ch, prev ;
    int broj = 0, mesto = 0;
    int flagBr = 0;
    int flagCh = 0;
    while((ch = getchar()) != '\n'){
        if((ch >= 'a' && ch <= 'z') ||(ch >='A' && ch <='Z')){
            if(flagCh==0 && flagBr == 1){
                if(prev == ch){
                int povecaj = 0;
                for(int i = 1; i <= mesto; i++){
                    povecaj= povecaj*10+i;
                }
                int zbir = 0;
                int sumaDva = 0;
                for(int i = 0; i <mesto; i++){
                    zbir = povecaj%10 + broj%10;
                    sumaDva = sumaDva + (zbir%10)*pow(10,i);
                    povecaj/=10;
                    broj/=10;
                }
                printf("%d",sumaDva);
            }else{
                int deljenik = pow(mesto,2);
                broj = broj%deljenik;
                printf("%d",broj);
                }
                
            }
            flagCh = 1;
            flagBr = 0;
            prev = ch;
            broj = 0;
            mesto = 0;
        }else if(ch >='0' && ch <= '9'){
            flagBr = 1;
            flagCh = 0;
        }
    
        if(flagCh)
         putchar(ch);
        if(flagBr){
            broj =broj*10+ ch-'0';
            mesto++;
        }
        
       
    }
    putchar('\n');

    return 0;
}