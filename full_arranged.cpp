/*
求一个全排列函数： 
如p([1,2,3])输出： 
[123]、[132]、[213]、[231]、[321]、[312]
*/
#include<iostream>
using namespace std;

void perm(int *a,int *b,int curlen,int len ){
	
	if(curlen==1){
		for(int i=0;i<len;i++){
			cout<<b[i]<<"  ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<curlen;i++){
		swap(a[0],a[i]);
		perm(a+1,b,curlen-1,len);
		swap(a[0],a[i]);
	}	
	
}

void swap(int &a,int&b){
	int temp=a;
	a=b;b=temp;
}
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int *b;
	b=a;
	perm(a,b,10,10);
} 
