#include <stdio.h>
#include <math.h>
#include <limits.h>

///Ulaz: (15 4 42) 21 4 [54 103 36]
///Izlaz: 154

int main()
{
    char ch;
    
    int flag = 3;
    char pre;
    int sum = 0;
    int min = INT_MAX;
    int br = 0;
    int vel = 0;
    int zbir = 0;
    while((ch = getchar())!= '\n'){
        if(ch == '('){
           
            if(vel != 0){
                sum = sum + zbir/vel;
                zbir = 0;
                vel = 0;
            }
            
            flag = 0;
        }else if(ch == '['){
            
            if(vel != 0){
                sum = sum + pow(min,vel);
                min = INT_MAX;
                vel = 0;
            }
            
            flag = 1;
        }else if(pre == ']' || pre == ')' || flag == 3){
            flag = 2;
        }
        
        if(flag == 0){
            if(ch >='0' && ch <='9'){
                br = br*10 + ch-'0';
            }else if(ch == ' ' || ch ==')'){
                if(br < min){
                    min = br;
                }
                vel++;
               
                br = 0;
                
            }
            
        }else if(flag == 1){
            if(ch >='0' && ch <='9'){
                br = br*10 + ch-'0';
            }else if(ch == ' ' || ch == ']'){
                zbir = zbir + br;
                vel++;
                
                br = 0;
            }
            
        }else if(flag == 2){
            if(ch >='0' && ch <='9'){
                br = br*10 + ch-'0';
            }else if(ch == ' '){
                sum += br;
                
                br = 0;
                
            }
        }
        
        if(pre == ']' || pre == ')')
        flag = 3;
        
        
        
        pre = ch;
    }
    if(zbir != 0){
        int dodaj;
        if(zbir%vel != 0){
           dodaj =  zbir/vel +1;
            sum = sum + dodaj;
        }else{
             sum = sum + zbir/vel;
        }
       
    }else if(min != INT_MAX){
        sum = sum + pow(min,vel);
        
    }
    
    printf("%d\n", sum);
    return 0;
}