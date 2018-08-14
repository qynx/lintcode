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
using namspace std;
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

vector<vector<string>> partition(string s) {
		int len=s.length();
		char *p=new char[len+1];
		for(int i=0;i<len;i++)
			p[i]=s[i];
		p[len]='\0';
		
		//dp[i][j]表示 i到i+j(左闭右闭)是否是回文数 
		int dp[len][len];        
		
		
}
int main(){
	
}
