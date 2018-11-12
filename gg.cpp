#include<iostream>
using namespace std;

int a[10];
int main(){
	
	for(int i=0;i<10;i++)
		a[i]=0;
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		
		a[(int)(s[i]-'0')]=1;
	}
	
	for(int i=9;i>=0;i--){
		if(a[i]!=0)
		cout<<i;
	}
} 
