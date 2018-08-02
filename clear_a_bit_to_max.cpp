#include<iostream>
using namespace std;
/*
给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
*/

/* 325 1 35 */

int which_to_clear(int *a){
	
	while(true){
	
	while(*a==-1){
		a++;

	}
	int *b=a+1;
	
	while(*b==-1){
		b++;
	}
	if(*b==-2){
		*a=-1;
		return 1; 
	} 
	if(*b>*a){
		*a=-1;
		return 1;
	}else{
		a=b;
	}
	
   }
}

void add(int* a,int n){
	
	int b[6];
	
	int i=0;
	while(n!=0){
		b[i]=n%10;
		n/=10;
		i++;
	}
	
	for(int j=0;j<i;j++){
		a[j]=b[i-j-1];
	//	cout<<a[j]<<endl;
	}
	
	a[i]=-2;	
}

int main(){
	
	long n,count;
	cin>>n>>count;
	
	int a[50000]={-2};
	
	add(a,n);
	
	for(int i=0;i<count;i++){
		which_to_clear(a);
	}
	//cout<<a[0]<<endl;
	for(int i=0;i<6;i++){
		if(a[i]>0){
			cout<<a[i];
		}
	}
} 
