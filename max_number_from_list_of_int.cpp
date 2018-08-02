#include<iostream>
#include<stdlib.h>
using namespace std;
/*
题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。*/

//计算一个整数的位数 
int bits(int n){
	int count=1;
	while(n!=0){
		n/=10;
		count*=10;
	}
	
	return count;
} 
//对比两个数的优先级 
int compare(int n,int m){
	
	int ns=bits(n);
	int ms=bits(m);
	
	int nm=n*ms+m;
	int mn=m*ns+n;
	
//	cout<<nm<<"	"<<mn<<endl;
	return nm>mn?1:0;	//nm>mn 返回1 
}

void swap(int &a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
void sort(int *b,int len){
	
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++)
		{
			if(compare(b[j],b[i])==1){
				swap(b[j],b[i]);
			}
		}
	}
}
int main(){
	
	int a;
	int *b;
	
//	cout<<compare(1,123);
	while(true){
		
		cin>>a;
		b=(int* )malloc(sizeof(int)*a);
		for(int i=0;i<a;i++){
		
			cin>>b[i];
		//	cout<<b[i]<<endl;
	}
		//c= (int* )malloc(sizeof(int)*a);
		sort(b,a);
		for(int i=0;i<a;i++){
			cout<<b[i];
		}
		//cout<<endl;
		
		cout<<endl;
		free(b);	
		
	}
} 
