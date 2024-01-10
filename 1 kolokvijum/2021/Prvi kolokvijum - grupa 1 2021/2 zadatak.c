#include <stdio.h>
#include <math.h>

//Ulaz: md({3}g)a(sd5a)sad{(10sda)12}g11
//Izlaz: 583

//{} kvadrira se velika
//() duplira se mala
//samo se dodaje
int main()
{
    int n=0;
    int zbir=0;
    int mala=0,velika=0;
    char ch;
    
    while((ch = getchar()) != '\n'){
        
        if(ch>='0'&&ch<='9')
        {
            n=n*10+ch-48;
        }
        if(ch=='(')
        {
            mala=1;
            zbir+=n;
            n=0;
        }
        if(ch==')')
        {
            mala=0;
            n*=2;
            if(velika==1)
                n*=n;
            zbir+=n;
            n=0;
            
        }
        if(ch=='{')
            {
             velika=1;
             zbir+=n;
             n=0;
            }
        if(ch=='}')
        {
            velika=0;
            n*=n;
            if(mala==1)
                n*=2;
            zbir+=n;
            n=0;
            
        }
        if(velika == 0 && mala == 0 && !(ch>='0'&&ch<='9')){
            zbir+=n;
            n = 0;
        }

    }
    zbir+=n;
    printf("%d \n", zbir);

    return 0;
}