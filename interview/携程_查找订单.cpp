#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Post{
	int id;
	int intime;
	int outtime;
	Post(int x,int y,int z):id(x),intime(y),outtime(z){
	}
};

bool cmp(Post*a,Post*b){
	return a->intime<b->intime;
}

bool cmp2(Post*a ,Post*b){
	return a->id<b->id;
}
void find(vector<Post* >&a,int  &index,int element){
	
	index=-3;
	int start=0;
	if(a[0]->intime<element){
		index=0;
		return;
	}
	while(start<a.size()&&a[start]->intime>element){
		start+=2;
	}
	
	index=start-1;
}
int main(){
	
	int n;
	cin>>n;
	int time;
	cin>>time;
		vector<Post* >a;
	
	int x,y,z;
	for(int i=0;i<n;i++){
		cin>>x>>y>>z;
		a.push_back(new Post(x,y,z));
	}
	
	sort(a.begin(),a.end(),cmp);

	int index=-1;
	find(a,index,time);
	
	vector<Post*>result;
	if(index==-3){
		cout<<"null";
		return 0;
	} 
	//cout<<index<<endl;
	
		if(index<0)
			index=0;
	for(int i=index;i<a.size();i++){
		if((a[i]->intime<=time)&&(a[i]->outtime>=time)){
		//	cout<<a[i]->intime<<" "<<a[i]->outtime<<" "<<time<<endl;
			result.push_back(a[i]);
		}
	}
	
	sort(result.begin(),result.end(),cmp2);
	
	Post* p;
	for(int i=0;i<result.size();i++){
		p=result[i];
		cout<<p->id<<" "<<p->intime<<" "<<p->outtime<<endl;
	} 
	
}
