#include<iostream>
#include<vector>
using namespace std;

char a[10000][10000];
char b[10000][10000];

int m,n,k;

bool isValidate(int i,int j,char c){
	if(i>=0&&i<m&&j>=0&&j<n&&b[i][j]==0&&c==a[i][j])
		return true;
	return false;
	
}
bool dfs(string s,int index,int lasti,int lastj){
	
	if(index>=s.length())
		return true;
	
	if(index!=0){
		bool d1;
		if(isValidate(lasti,lastj+1,s[index])){
			b[lasti][lastj+1]=1;
			d1=dfs(s,index+1,lasti,lastj+1);
			b[lasti][lastj+1]=0;
			if(d1)
			return true;	
		}
		
		if(isValidate(lasti,lastj-1,s[index])){
			b[lasti][lastj-1]=1;
			d1=dfs(s,index+1,lasti,lastj-1);
			b[lasti][lastj-1]=0;
			if(d1)
			return true;
		}
		if(isValidate(lasti-1,lastj,s[index])){
			b[lasti-1][lastj]=1;
			d1=dfs(s,index+1,lasti-1,lastj);
			b[lasti-1][lastj]=0;
			if(d1)
			return true;
		}
		if(isValidate(lasti+1,lastj,s[index])){
			b[lasti+1][lastj]=1;
			d1=dfs(s,index+1,lasti+1,lastj);
			b[lasti+1][lastj]=0;
			if(d1)
			return true;
		}
	}//第一个字母之后的字母 
	
	else{
	
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++){
		
		if(a[i][j]==s[index]&&b[i][j]==0){
			b[i][j]=1;
			if(dfs(s,index+1,i,j))
				return true;
			b[i][j]=0;
		}
	}
	return false;	
	} //第一个字母
	 
	return false;
}

void init_b(){
		for(int i=0;i<m;i++)
	for(int j=0;j<n;j++){
		b[i][j]=0;
	}	
}
	
int main(){
	

	
	cin>>m>>n>>k;
	
	string s;
	vector<string>ss;
	
	for(int i=0;i<k;i++)
		{
			cin>>s;
			ss.push_back(s); //输入字符串 
		}
	
	//cout<<m<<" "<<n<<endl;
	  
	  char c;
	  for(int i=0;i<m;i++){
	//	cout<<n<<endl;
		for(int j=0;j<n;j++){
			cin>>c;
			a[i][j]=c;
		} //输入图空间 
	 }
	
	for(int i=0;i<k;i++){
		init_b();
		
		if(dfs(ss[i],0,0,0))
			cout<<ss[i]<<endl;
	} 
	
	
}
