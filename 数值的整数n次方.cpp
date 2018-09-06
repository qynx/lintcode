#include<iostream>
using namespace std;

 double Power(double base, int exponent) {
       double result=1.0;
        while(exponent--){
           result*=base;
       }
       return result;
}

int main(){
	
	cout<<Power(2.0,2)<<endl; 
}
