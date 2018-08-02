#include<iostream>
using namespace std;

void insSort(int *a,int n,int incr);

void shellSort(int *a,int n){
	
	for(int i=n/2;i>2;i/=2)
	 for(int j=0;j<i;j++)
	  insSort(a+j,n-j,i);
	
	insSort(a,n,1);
}

void insSort(int *a,int n,int incr){
	
	int temp;
	for(int i=incr;i<n;i+=incr)
	 for(int j=i;j>=incr;j-=incr){
	 	if(a[j]>a[j-incr]) break;
	 	else{
	 		temp=a[j];
	 		a[j]=a[j-incr];
	 		a[j-incr]=temp;
		 }
	 }	
}

int main(){
	
	int len=10;
	
	//int a[15]={5,6,7,8,2,1,3,4,9,0,1,2,3,4,5};
	
	int a[10]={5,6,7,8,2,1,3,4,9,90};
	shellSort(a,10);
	
	for(int i=0;i<len;i++){
		cout<<a[i];
	}
}
