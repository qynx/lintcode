//�ǵݹ�ʵ�� �鲢����

#include<iostream>
using namespace std;

//hebing [l,mid] [mid+1,r] 
void hebing(int *a,int *b,int l,int mid,int r){
	int k=l;
	int rb=mid+1;
	while((l<=mid)&&(rb<=r)){
		if(a[l]<=a[rb]){
			b[k++]=a[l++];
		}else{
			b[k++]=a[rb++];
		}
	}
	
	if(l<=mid){
		for(int i=l;i<=mid;i++){
			b[k++]=a[i];
		}
	}
	if(rb<=r){
		for(int i=rb;i<=r;i++)
			b[k++]=a[i];
	}
}

//ÿs��Ԫ��Ϊһ�� һ����Ϊ������ �������� 
void Merge(int *a,int *b,int s,int len){
	int i=0;
	while(i+s<len){
		hebing(a,b,i,i+s/2-1,i+s-1);
		i+=s;
	} 
	//ʣ�µ�Ԫ�� �Ƿ���Ի���Ϊ���飨����һ��Ԫ�ز������� 
	if(i+s/2<len){
		hebing(a,b,i,i+s/2-1,len-1);
	}else{ //ֻʣ��һ�� 
		for(int j=i;j<len;j++){
			b[j]=a[j];
		} 
	}
	
	
	
}
void mergeSort(int *a,int *b,int len){
	int s=1;
	
	while(s<len){
		s+=s;
		Merge(a,b,s,len);
		s+=s;
		Merge(b,a,s,len);
		
	}
	
}
int main(){
	int len=9;
	int a[9]={1,23,1,5,10,9,8,7,6};
	int *b=new int[10];
	mergeSort(a,b,len);
	
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	} 
} 
