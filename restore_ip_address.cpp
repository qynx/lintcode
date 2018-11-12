#include "header.h" 
using namespace std;

vector<string> restoreIpAddresses(string s) {
	vector<string> ans;
	string current;
	backtracking(ans,current,s,0,0);
	return ans;   
}

void backtracking(vector<string>&ans,string&current,string& s,int i,int p){
	
	if(i==4){
		ans.push_back(current);
		return ;
	}
	
	for(int j=1;j<=3;j++){
		if(j==3 && s.substr(p,j)>"255") continue;
		if(j>1 && s[p]=='0') continue;
		if(s.length()-p-j<4-i-1 || s.length()-p-j>(4-i-1)*3)
			continue;
		if(i>0) current+='.';
		current+=s.substr(p,j);
		backtracking(ans,current,s,i+1,p+j);
		current.erase(p+i,j);
		if(i>0)
			current.erase(p+i-1,1);
	}
}
int main(){
	
	
} 
