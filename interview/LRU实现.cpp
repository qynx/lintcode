#include<iostream>
#include<cstdlib> 
using namespace std;

#define pageSize 3
int *pages=(int *)malloc(pageSize*sizeof(int)); 

//查询并移动 index 0 位最高优先级 
//使用位置表示最近使用的时间 
int query(int *a,int page){
	for(int i=0;i<pageSize;i++){
			
		//命中 
		if(a[i]==page){
			//return i;
			
			//移到最前面 之后的位置元素不动 
			 for(int j=i;j>=1;j--){
			 	a[j]=a[j-1];
			 }
			 a[0]=page;
			 return 0;
		}
	}
	
	//没有命中,如果没有内容，直接存放0号位 
	if(a[0]==-1)
		{
		a[0]=page; 
		return -1;
	}
	//如果有内容 把最后一个元素踢出数组
	for(int i=pageSize-1;i>=1;i--){
		a[i]=a[i-1];
	} 
	a[0]=page;
	
	return -1;
}

//打印当前情况 
void print(int *a){
	for(int i=0;i<pageSize;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
}
int main(){
	cout<<"开始模拟"<<endl;
	
	int page;
	int curr=0;
	for(int i=0;i<pageSize;i++){
		pages[i]=-1;
	}
	
	int missing=0; 
	int count=0;
	while(true){
		cout<<"输入页  ";
		cin>>page;
		if(page==-1){
			cout<<"共查询 "<<count<<" 次  未命中"<<missing<<" 次"<<endl; 
			free(pages);
			return 0;
		}
		int result=query(pages,page);
		if(result==-1)
			missing++;
		count++;
		print(pages);
		
	}	
} 
