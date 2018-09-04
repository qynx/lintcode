#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
/*
5
1 2
5 3
4 6
7 5
9 0

output:
4 6
7 5
9 0
*/ 

struct Points{
	int x;
	int y;
	Points(int xx,int yy):x(xx),y(yy){
	}
};
bool cmp(Points*a,Points*b){
	return a->x<b->x;
}

class Solution{
	public:
	int maxx;
	int maxy;
	vector<Points*>result;
	
	Solution(){
		maxx=0;
		maxy=0;
	}
	
	void insert(int x,int y){
		if(x>maxx)
			maxx=x;
		if(y>maxy)
			maxy=y;
		result.push_back(new Points(x,y));
	}
	
	void clear(){
		result.clear();
	}
	
	int contain(Points*a,int x,int y){
		if(a->x>x&& a->y>y)
			return 1;
		else if(a->x<x&&a->y<y)
			return -1;
		else
			return 0;
	}
	
	bool compare(int x,int y){
		int flag=0;
		vector<Points*>::iterator it=result.begin();
		while(it!=result.end()){
			int t=contain(*it,x,y);
			if(t==1)
				return false;
			else if(t==-1)
			{	
				result.erase(it);
				flag=1;
			}
			else if(t==0){
				flag=1;
				it++;
			}
		}
		
		if(flag)
			return true;
		return false;
	}
	
	void SortByx(){
		sort(result.begin(),result.end(),cmp);
	}
	
	void print(){
		
		for(int i=0;i<result.size();i++){
		//	cout<<result[i]->x<<" "<<result[i]->y<<endl;
		printf("%d %d\n",result[i]->x,result[i]->y);
		}
	}
};
int main(){
	int n;
	cin>>n;
	
	int x,y;
	int a,b=0;
	Solution s=Solution();
	while(n--){
		//cin>>x>>y;
		scanf("%d%d",&x,&y);
		if(x>s.maxx&&y>s.maxy){
			s.clear();
			s.insert(x,y);
		}
		else if(s.compare(x,y)){
			s.insert(x,y);
		}
	}
	s.SortByx();
	s.print();
	return 0;
} 
