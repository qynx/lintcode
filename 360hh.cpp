#include<iostream>
#include<set>
using namespace std;

int min(long*a,int l,int r){
	int minn=a[l];
	int maxn=a[l];
	for(int i=l;i<=r;i++){
		if(a[i]<minn)
		minn=a[i];
		if(a[i]>maxn)
		maxn=a[i];
	}
	return make_pair<int,int>(minn,maxn);
}



//ÍþÁ¦Öµ 
int main(){
	
	int n;
	cin>>n;
	
	long a[n];
	int b[n];
	
	long dpmin[n][n];
	
	
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int j=0;j<n;j++)
	cin>>b[j];
	
	for(int i=0;i<n;i++)
		dpmin[i][i]=a[i];
	
		
	for(int i=0;i<n;i++)
	for(int step=1;step+i<n;step++){
		
		for(int j=0;j<step;j++){
			
		}
	
	}
	for(int i=0;i<n;i++){
		cout<<min(a,i-b[i]+1,i)*max(a,i-b[i]+1,i)<<endl;
	}
	 
	
} 
