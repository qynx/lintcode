#include<iostream>
using namespace std;

/*
去掉重复的数 
*/ 
int a[10];
int flag[10];

int main(){
	
	
	string s;
	cin>>s;
	
	for(int i=0;i<10;i++)
		{
		
		a[i]=0; flag[i]=0;
	}
	
	for(int i=0;i<s.length();i++){
		
		a[(int)(s[i]-'0')]+=1;
	}
	
	
	string result;
	
	for(int i=0;i<s.length();i++){
		
		if(a[(int)(s[i]-'0')]==1)
		{
			result+=s[i];
		}	
		else{
			int j=9;
			
			while(1){
				if(a[j]>1&&!flag[j])
				 break;
				 j--;
			}
			
			if(j==-1){
				continue;
			}
			else if(j==(int)(s[i]-'0'))
			{
				result+=s[i];
				flag[j]=1;
			}
			else{
				continue;
			}
			
			
		}
	}
	
	cout<<result;
}
