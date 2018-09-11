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
 int add(int a,int b){
 	
 //	int num=0;
 	int sum=a;
 	while(b){
 		sum=a^b;
 		//cout<<a<<endl;
 		b=a&b ;
 	//	cout<<b<<endl;
 		if(!b){
 			break;
		 }
		 b=b<<1;
 		a=sum;
 		//cout<<a<<endl;
 		//sum
	 }
	 return sum;
 } 
int main(){
//	cout<<(1&4)<<endl;
	int a,b;
	while(cin>>a>>b){
		cout<<add(a,b)<<endl;
	}
	//cout<<Add(10,15)<<endl; 
}

