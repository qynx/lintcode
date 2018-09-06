#include<iostream>
using namespace std;

int Add(int num1, int num2)
    {
        int x=0x01;
        int a;
        int b;
        int sum=0;
        int c=0;
        while(num1||num2){
            a=num1&x;
            b=num2&x;
            
            if(a==1&&b==1)
                c=1;
            sum=(sum<<1)|(a^b);
        }
        
        return sum;
    }
    
int main(){
	
}

