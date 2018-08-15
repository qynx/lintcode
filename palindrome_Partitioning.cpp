/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s ="aab",
Return 
  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/ 
#include<iostream>
#include<vector>
using namespace std;
bool palindrome(char *p,int len){
	char*q=p+len-1;
	
	while(q>p){
		if(*p==*q){
			q--;
			p++;
		}else{
			return false;
		}
	}
	
	return true;
}
void dfs(char *p,string s,int i,int j,vector< vector<string> >&result,vector<string>temp);
vector< vector<string> > partition(string s) {
		int len=s.length();
		char *p=new char[len+1];
		for(int i=0;i<len;i++)
			p[i]=s[i];
		p[len]='\0';
		
		//dp[i][j]表示 i到j(左闭右闭)是否是回文数 
		int dp[len][len];        
		for(int i=0;i<len;i++){
			dp[i][i]=1;
		}
		for(int j=1;j<len;j++){
			for(int i=0;i<j;i++){
				dp[i][j]=palindrome(p+i,j-i+1);
			}
		}
		
		vector<string>temp;
		vector< vector<string> > result;
		
		dfs(p,s,0,len-1,result,temp);
		
		for(int i=0;i<result.size();i++){
			for(int j=0;j<result[i].size();j++){
				cout<<result[i][j]<<"	";
			}
			cout<<endl;
		}
		return result;
	//	dfs(dp);
		 
}

char* spice(char *p,int i,int j){
	char*q=p+i;
	q[j+1]='\0';
	return q;
}

void dfs(char* p,string s,int i,int j,vector< vector<string> >&result,vector<string>temp){
		
	//	vector<string> temp;
	//for(int k=j;k>=0;k--)
		for(int l=i;l<=j;l++){
			
			//如果l 至 j 是回文数 
			if(palindrome(p+i,l-i+1)){
				temp.push_back(s.substr(i,l-i+1));
				
				if(l==j){
				result.push_back(temp);
				}else{
					dfs(p,s,l+1,j,result,temp); 
				}	
				temp.pop_back();
			}
			
			//如果此段不是回文数 循环继续； 
		}
	
}
int main(){
	vector<string>p;
	//string s="sssss";
	//cout<<s.substr(1,4);
	//p.push_back(q+1);
	//cout<<p[0]<<endl; 
	partition("aab");
}
