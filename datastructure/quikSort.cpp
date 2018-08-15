#include<iostream>
using namespace  std;
int Partition(int *a,int left,int right);
void qsort(int *a,int left,int right){
	if(left<right){
	//	int mid=(left+right)/2;
		int p=Partition(a,left,right);
		qsort(a,left,p-1);
		qsort(a,p+1,right);
	}
}

int Partition(int *a,int left,int right){
	
	int r=right++;
	int l=left;
	int temp=a[left];
	while(left<right){
		
		while(a[++left]<=temp);
		while(a[--right]>temp);
		if(left<right){
			int t=a[left];
			a[left]=a[right];
			a[right]=t;
		} 
	}
	
	a[l]=a[right];
	a[right]=temp;
	return right;
}
int main(){
	int a[20]={1,1,1,1,1,1,1,1,1,1};
	qsort(a,0,9);
	for(int i=0;i<20;i++)
		cout<<a[i]<<"  ";
	
}
