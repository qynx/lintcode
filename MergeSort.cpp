#include<iostream>
#include<cstdlib>

using namespace std;

int *b=(int *)malloc(sizeof(int)*50);

void Merge(int *a,int *b,int left,int mid,int right);
void Copy(int *a,int *b,int left,int right);

void MergeSort(int *a,int left,int right){
	
	if(left>=right) return;
	int mid=(left+right)/2;
	
	MergeSort(a,left,mid);
	MergeSort(a,mid+1,right);
	
	Merge(a,b,left,mid,right);
	Copy(a,b,left,right);
}

void Merge(int *a,int* b,int left,int mid,int right){
	
	int k=left,r=mid+1;
	
	while((left<=mid)&&(r<=right)){
		if(a[left]<a[r]) b[k++]=a[left++];
		else b[k++]=a[r++];
	}	
	
	if(left<=mid) 
	 for(int i=left;i<=mid;i++)
	  b[k++]=a[i];
	else
	  for(int i=r;i<=right;i++)
	   b[k++]=a[i];
}

void Copy(int *a,int *b,int left,int right){
	
	for(int i=left;i<=right;i++){
		a[i]=b[i];
	}	
}



int main(){
	int len=10;
	
	int a[10]={5,6,7,8,2,1,3,4,9};
	cout<<a[9]<<endl;
	MergeSort(a,0,8);
	
	for(int i=0;i<len;i++){
		cout<<a[i];
	}
	free(b);
} 
