#include<iostream>
#include<stdlib.h>
using namespace std;
/*
��Ŀ����
����n�������������������ӳ�һ�ţ����һ�����Ķ�λ������
��:n=3ʱ��3������13,312,343,���ɵ��������Ϊ34331213��
��:n=4ʱ,4������7,13,4,246���ӳɵ��������Ϊ7424613��*/

//����һ��������λ�� 
int bits(int n){
	int count=1;
	while(n!=0){
		n/=10;
		count*=10;
	}
	
	return count;
} 
//�Ա������������ȼ� 
int compare(int n,int m){
	
	int ns=bits(n);
	int ms=bits(m);
	
	int nm=n*ms+m;
	int mn=m*ns+n;
	
//	cout<<nm<<"	"<<mn<<endl;
	return nm>mn?1:0;	//nm>mn ����1 
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
