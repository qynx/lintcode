#include<iostream>
#include<set> 
using namespace std;
/*
����m������Ϊl���ַ���

����µ��ַ��� �µ��ַ�����һ���ַ������������ַ����е�һ���ĵ�һ���ַ�
һ������
������ԭ�ַ����غ� 
*/
string s[2005];
string result;
set<string>strs;
set<char>chars[15];
string results;
int flag=0;
void dfs(int cur,int m){
	if(cur>=m){
		if(strs.find(result)!=strs.end()){
			return;
		}else{
			results=result;
			flag=1;
			return;
		}
	}
	
	set<string>::iterator it=strs[cur].begin();
	
	while(it!=strs[cur].end()){
		
		result[cur]=*it;
		dfs(cur+1,m);
		if(flag)
			return;
		++it;
	}
}
int main(){
	
	int n,l;
	cin>>n>>l;
	
	for(int i=0;i<n;i++){
		cin>>s[i];
		
		strs.insert(s[i]);
		for(int j=0;j<s[i].length();j++){
			chars[j].insert(s[i][j]);
		}
		
		
	}
	
	result=""
	for(int i=0;i<m;i++)
		result+='a';
	
	dfs(0);
	
	if(flag){
		cout<<result<<endl;
		
		
	}else{
		cout<<"-"<<endl;
	}
	
	return 0;
}
