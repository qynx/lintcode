#include<iostream>
using namespace std;

int main(){
	
	long n;
	cin>>n;
	

	int count=0;
	
	long t;
	while(n){
            ++ count;
            n = (n - 1) & n;
   

	}
	
	cout<<count;
} 
