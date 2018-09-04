#include<iostream>
#include<set>
#include<map>
using namespace std;
// x首 长度为a的歌曲  y首 长度为b的歌曲
//凑成长度为k的歌 求排列数（不计顺序） 
//最后复杂度过大 
set< set<int> >sets;
set<int>tset;

long count=0;

void dfs(int *A,int k,int l){
	
	if(k==0)
	{
		count++;
		sets.insert(tset);
		return;
	}else if(k<0){
		return;
	}
	for(int i=0;i<l;i++){
		int temp=A[i];
		if(temp!=0){ //未被选中 
			k-=temp;
			tset.insert(i);
			A[i]=0;
			dfs(A,k,l); 
			A[i]=temp;
			tset.erase(i);
			k+=temp;
		}
	}
}
int main(){
	tset.clear();
	sets.clear();
	//总长度 
	int k;
	cin>>k;
	//x首 长度为a的歌
	//y首 长度为b的歌 
	int a,b,x,y; 
	
	cin>>a>>x>>b>>y;
	
	int A[x+y];
	//int B[y];
	for(int i=0;i<x;i++)
		A[i]=a;
	for(int i=0;i<y;i++)
		A[i+x]=b;
	
	dfs(A,k,x+y);
	
	set< set<int> >::iterator it=sets.begin();
	//cout<<count;
	count=0;
	while(it!=sets.end()){
		//cout<<"GG";
		count++;
		it++;
	}
	cout<<(count%1000000007);
	 
} 
