#include<iostream>
using namespace std;

//十进制 20位数 乘法 
int main(){
	
	string s1,s2;
	cin>>s1>>s2;
	
	int l1=s1.length(),l2=s2.length(); 
    int s[41]={0};
	
	for(int i=0;i<l1+l2-1;i++){
		
		for(int j=0;j<l1;j++){
			for(int k=0;k<l2;k++){
				if(j+k==i)
				s[i]+=(s1[j]-'0')*(s2[k]-'0');
			}
		}
	}
	
	for(int i=l1+l2-2;i>0;i--){
		if(s[i]>=10){
			s[i-1]+=s[i]/10;
			s[i]=s[i]%10;
		}
	}
	if(s[0]>10){
		cout<<s[0]/10;
		s[0]=s[0]%10;
	}
	for(int i=0;i<l1+l2-1;i++)
	cout<<s[i];
	
	
	
	
}
