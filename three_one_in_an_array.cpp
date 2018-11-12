#include<iostream>
using namespace std;

int a[10];

int main(){
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	
	int b[32]={0};
	
	for(int i=0;i<n;i++){
		
		for(int j=0;j<32;j++){
			b[j]+=(a[i]&(1<<j))>>j;
		} 
	} 
	int result=0;
	for(int i=0;i<32;i++){
	//	cout<<b[i]<<" ";
		if(b[i]%3!=0){
			result|=(1<<i);
		}
	}
	
	cout<<result;
	
}
