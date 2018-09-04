#include<iostream>
#include<vector>
#include<set> 
#include<cstdlib>
using namespace std;
bool checkSame(string s1,string s2,int l){
	string t1="";
	string t2=""; // 
	int r1=0;
	int  r2=0;
	int i,j=0;
	int c=1;
	while(true){
	if(c>=5){
		return true;
	}
	t1="";
	t2="";
	while(i<s1.length()){
		if(s1[i]!='.'){
			t1+=s1[i];
		}else{
			//int temp=stoi(t);
			i++;
			break; 
		}
		i++;
	}
	
	while(j<s2.length()){
			if(s2[j]!='.'){
			t2+=s2[j];
		}else{
			j++;
			//int temp=stoi(t);
			break; 
		}
		j++;
	}
//	cout<<t1<<endl;
//	cout<<t2<<endl;
	r1=stoi(t1);
	r2=stoi(t2);
	
	if(c*8>l){
		int ll=l%8;
		//cout<<r1<<endl;
		//cout<<r2<<endl;
		return (r1>>(8-ll)==r2>>(8-ll));
	}else{
	
		if(r1!=r2)
			return false;
	}
	c++;
	}//总循环 
}
int compare(string s1,string s2){
	int pos1=s1.find('/',0);
	int pos2=s2.find('/',0);
	
	//192.19.1.1
	string t1=s1.substr(0,pos1);
	string t2=s2.substr(0,pos2);
	
	// 16 32 
	int i1=stoi(s1.substr(pos1+1,s1.length()-pos1-1));
	int i2=stoi(s2.substr(pos2+1,s2.length()-pos2-1));

	if(i1<=i2){
		if(checkSame(t1,t2,i1)){  //前i位一样 
			return 1;
		}else{
			return 0;
		}
	}else{
		if(checkSame(t2,t1,i2)){
			return -1;
		}else{
			return 0;
		}
	}
}
bool validate(string s,vector<string>&r){
	int flag=0;

	for(int i=0;i<r.size();i++){
		int t=compare(s,r[i]); 
		
	
	//	cout<<t<<endl;
		if(t==1){ //如果s包含r[i]  移除r[i] 
 			r[i]=s;  //两个小的不包容 后来来一个大的 覆盖两个 
 			//return false;
		}else if(t==-1){ //r[i]包含s 
			return false;
		}
	}
	
	return true;
}
int main(){
	
	int n;
	cin>>n;
	
	vector<string> r;

	string s; 
	for(int i=0;i<n;i++){
		cin>>s;
		
		if(validate(s,r)){
		
		r.push_back(s);}
	}
	set<string>rs;
	//cout<<r.size()<<endl;
	for(int i=0;i<r.size();i++){
		rs.insert(r[i]);
	}
	cout<<rs.size()<<endl;
	set<string>::iterator it =rs.begin();
	while(it!=rs.end()){
		cout<<*it<<endl;
		it++;
	}
}
