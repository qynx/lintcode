/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s ="aab",
Return1since the palindrome partitioning["aa","b"]could be produced using 1 cut.

*/
#include<iostream>
using namespace std;

/*bool palindrome(string s){
	char *p=new char[s.length()+1];
	int i;
	for( i=0;i<s.length();i++){
		p[i]=s[i];
	}
	p[i]='\0';
	char*q=p+i-1;
	while(q>=p){
		if(*q==*p){
			q--;
			p++;
		}else{
			return false;
		}
	}
	
	return true;
}*/
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
int mincut(string s){
	
	char *p=new char[s.length()+1];
	int i;
	for( i=0;i<s.length();i++){
		p[i]=s[i];
	}
	p[i]='\0';
	
	int len=s.length();
	//dp[i][j] 记录 从 index i 开始 长度为j的子串需要几次划分 
	int dp[s.length()][s.length()+1];
	
	for(int i=0;i<len;i++)
		dp[i][1]=0;
	
	//从第二列开始 
	for(int j=2;j<len+1;j++)
		for(int i=0;(i+j)<=len;i++){
			
			//如果加入新的元素仍是回文数 则仍只需0次划分 
			if(palindrome(p+i,j)){
				dp[i][j]=0;
			}else{
				int min=dp[i][j-1]+dp[i+j-1][1]+1;
			//	cout<<i<<"  i	"<<j<<" j  "<<min<<endl;
				for(int k=j-2;k>=1;k--){
					int temp=dp[i][k]+dp[i+k][j-k]+1;
				//	if(j==3)
				//	cout<<"temp "<<temp<<endl;
					min=min<temp?min:temp;
					
				} 
				dp[i][j]=min;
			}
		}
	 for(int i=0;i<len;i++){
	 	for(int j=1;(i+j)<=len;j++){
	 		cout<<dp[i][j]<<" ";
		 }
		 cout<<endl;
	 }
	 cout<<endl;
	 return dp[0][len];
}
int main(){
		cout<<mincut("abcccb");
//	char*q="abcccb";
//	cout<<palindrome(q,6);
//	cout<<palindrome("a");
} 
