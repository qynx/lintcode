#include<iostream>
#include<vector>
using namespace std;

int a[52][11];
int flag[52];  //是否分配过
int members[11]; //成员数

vector<int>result;

void solve(int m,int n,int k,int cur){
	
	for(int j=0;j<m;j++){ //每个应聘的人 
	if(flag[j]==0){
	
	for(int i=0;i<n;i++){ //每个岗位 
		if(members[i]<k){
			members[i]+=1;
			flag[j]=1;
			cur+=a[j][i];
			int complete=1;
			
			for(int ii=0;ii<n;ii++){
				if(members[ii]!=k){
					complete=0;
					break;
				}
			}
			
			if(complete){
				result.push_back(cur);
				//continue;
			}
			else
			solve(m,n,k,cur);
			
			cur-=a[j][i];
			members[i]-=1;
			flag[j]=0;
		}//岗位是否招满人 
	}// 分配岗位循环 
		 } //如果没有分配过 
		}//遍历成员 
} 
void init(int m,int n){
	
	result.clear();
	for(int i=0;i<m;i++)
	flag[i]=0;
	for(int i=0;i<n;i++)
	members[i]=0;
}
int main(){
	
	int count;
	cin>>count;
	int m,n,k;
	
	while(count--){
		
		cin>>m>>n>>k;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		
	//	for(int i=0;i<m;i++)
	//	for(int j=0;j<n;j++)
	//	cout<<a[i][j]<<" ";
		init(m,n);
		solve(m,n,k,0);	
		int max=0;
		for(int i=0;i<result.size();i++){
		//	cout<<result[i]<<" ";
			if(result[i]>max)
			max=result[i];
		}
		cout<<max<<endl;
	}
} 
