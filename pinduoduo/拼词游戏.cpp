#include<iostream>
#include<vector>
using namespace std;

//存储每一列的情况  为1表示对应的字母在 
int a[11][26];

void dfs(int a[11][26],string s[],int l,int n,vector<char> &result,int cur,int flag){
		
		if(cur>l){
			return;
		}
		for(int j=0;j<26;j++){
			if(result.size()==4){
				return;
			}
			if(a[cur][j]==1){
				
				result.push_back((char)(j+65));
				if(cur==l-1){
					string temp;
					//构造字符串 
					for(int i=0;i<result.size();i++){
						temp+=result[i];
					}
					for(int i=0;i<n;i++){
						if(temp==s[i]){
							result.clear();
						} 
					}
					
					return;
				}else{
					dfs(a,s,l,n,result,cur+1,flag);
				}
				
				
			}
		}
	
}
int main(){
	
	for(int i=0;i<11;i++)
		for(int j=0;j<26;j++){
			a[i][j]=0;
		} 
	int n,l;
	cin>>n>>l;
	
	string s[n];
	vector<char>result;
	//cout<<(char)65<<endl;
//	char c=90;
//	cout<<('Z'==90)<<endl;
	//cout<<'Z'-65<<endl;
	//输入 
	for(int i=0;i<n;i++){
		cin>>s[i];
		
		//每一列可以取的值 
		for(int j=0;j<s[i].length();j++){
			a[j][s[i][j]-65]=1;
		}
	
	}
	
	dfs(a,s,l,n,result,0,0);
	
	if(result.size()==0)
	cout<<"-";
	else
	for(int i=0;i<result.size();i++){
		cout<<result[i];
	}
	
	
	
	
	
} 
