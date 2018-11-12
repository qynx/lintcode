#include<iostream>
using namespace std;


int main(){
	
	int n;
	cin>>n;
	int a[n+1];
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int q;
	cin>>q;
	
		int l,r,k;
		int count=0;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r>>k;
		count=0;
		for(int j=l;j<=r;j++){
			if(a[j]==k)
			 count++;
		}
		cout<<count<<endl;
	}
} 
