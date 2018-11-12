#include<iostream>
#include<cstdlib>
using namespace std;

struct sequence{
	int *color;	
}; 

void init_b(int *b,int m){
	for(int i=0;i<m;i++)
	b[i]=0;
}
int main(){
	
	
	
	int n,m,c;
	cin>>n>>m>>c;
	
	struct sequence* s=(struct sequence*)malloc(n*sizeof(struct sequence));
	//int a[n];  // 存储n个串子 
	//for(int i=0;i<n;i++){
	//	s->color=(int *)malloc(sizeof(int)*m);
	//}
	int b[m]; //存储颜色 数 
	
	int count;
	int color;
	for(int i=0;i<n;i++){
		cin>>count;
		s->color=(int *)malloc(sizeof(int)*(count+1));
		s[i]->color[0]=count;
		for(int j=0;j<count;j++){
			cin>>color;
			s[i]->color[j+1]=1;
		}
	}  //输入每个珠串的颜色 
	
	init_b(b,m);
	
	int result=0;
	for(int i=0;i<m;i++){
		
		count=s[i]->color[0];
		for(int j=0;j<count;j++){
			b[s[i]->color[j+1]-1]++;
		}
	}
	for(int i=1;i!=0;i=(i+1)%n){
		
	} 
}
