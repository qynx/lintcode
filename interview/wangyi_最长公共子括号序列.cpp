/*
定义LCS(S,T)为字符串S和字符串T最长公共子序列的长度,即一个最长的序列W既是S的子序列也是T的子序列的长度。
小易给出一个合法的括号匹配序列s,小易希望你能找出具有以下特征的括号序列t:
1、t跟s不同,但是长度相同
2、t也是一个合法的括号匹配序列
3、LCS(s, t)是满足上述两个条件的t中最大的
因为这样的t可能存在多个,小易需要你计算出满足条件的t有多少个。

如样例所示: s = "(())()",跟字符串s长度相同的合法括号匹配序列有:
"()(())", "((()))", "()()()", "(()())",其中LCS( "(())()", "()(())" )为4,其他三个都为5,所以输出3. 
输入描述:
输入包括字符串s(4 ≤ |s| ≤ 50,|s|表示字符串长度),保证s是一个合法的括号匹配序列。


输出描述:
输出一个正整数,满足条件的t的个数。

输入例子1:
(())()

输出例子1:
3
*/

#include<iostream>
using namespace std;

int lcs(string s1,string s2){
	if(s1==s2)
		return 0;
	int dp[s1.length()]+1[s2.length()+1];
	
	for(int i=0;i<s1.length();i++)
		dp[i][0]=0;
	for(int i=0;i<s2.length();i++)
		dp[0][i]=0;
	
	for(int i=1;i<s1.length();i++)
		for(int j=1;j<s2.length();j++){
			if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	
	return dp[s1.length()][s2.length()];
} 


int main(){
	string s;
	cin>>s;
	
	int len=s.length();	
	int left=len/2;  //半括号的数目
	
	 
}
