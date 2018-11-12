#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> zhiyinzi(int a){
	vector<int>result;	
	for(int i=2;i<=a;i++){
		if(a%i==0){
			result.push_back(i);
		}
	}
	
	return result;
	
}

int main(){
	
	int n,m;	
	cin>>n;
	
	int a[n+1];
	
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
	a[1]=1;
//	set<int>yinshu;
	vector<int>temp;
	int count=n-1; //尚且需要n-1个数 待确定 
	for(int i=n+1;;i++) 
	{
		temp=zhiyinzi(i);
		for(int j=0;j<temp.size();j++){
			//yinshu.insert(temp[j]);
			if(temp[j]<=n){
				a[temp[j]]=1;
				//count--; 
			}
		}
		
		int k=1;
		for(;k<=n;k++){
			if(a[k]==0)
				break;
		}
		if(k>n){
			cout<<i;
			return 0;
		}
		
	}
	
	return 0;
} 
