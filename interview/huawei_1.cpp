#include<iostream>
using namespace std;

int a[129]={0};

int main(){
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		a[s[i]]+=1;
	}
	char r='%';
	for(int i=0;i<s.length();i++){
		if(a[s[i]]==1){
			r=s[i];
		}
	}
	
	if(r=='%')
		cout<<"NULL";
	else
		cout<<r;
	
}
