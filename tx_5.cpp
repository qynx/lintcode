#include<iostream>
using namespace std;

bool iszhi(int n){
	if(n==1)
	return false;
	else if(n==2)
	return false;
	else{
		
		for(int i=2;i<n;i++){
			if(n%i==0)
			return true;
		}
		return false;
	}
}
int main(){
	
	int a,b;
	cin>>a>>b;
	
	int count=0;
	for(int i=a;i<=b;i++){
		if(!iszhi(i)){
			count+=1;
		}
	}
	
	cout<<count;
}
