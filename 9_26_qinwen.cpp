#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int *enhance(int *a,int *b,int n){
	//a , b传入的数组 n数组长度 
	int flag[n];
	//int deal[n]; 
	int *result=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
		{
		flag[i]=0;
		//deal[i]=0;
		result[i]=-1;
		}
		
	for(int i=0;i<n;i++){  //对于B中每一个元素 在a中寻找 刚好比其大的 
		
		int neightborGreat=-1;
		
		for(int j=0;j<n;j++){
			if(!flag[j]&&a[j]>b[i]){  //如果a中 当前元素没有用过 并且 其比b中当前元素值大 
				if(neightborGreat==-1){  //如果neightborGreat尚未赋过值 
				
					neightborGreat=a[j];
					flag[j]=1;
				} 
				else //如果neightborGreat已经赋过值 则判断其是否与b中当前值 更接近  
				/*
				
				此处 忘记修改上一个认定为neighbor的flag值 
				*/ 
					{
						if(a[j]<neightborGreat){
							neightborGreat=a[j];
							flag[j]=1;
						}
					}
			}
		}//a中寻找是否有符合条件的值
		
		if(neightborGreat!=-1)
			 result[i]=neightborGreat;
	}
	
	int i=0;int j=0;
	
	while(i<n){
		if(!flag[i]){
			while(result[j]!=-1){
				j++;
			}
			result[j]=a[i];
		}
		i++;
	}
	
	for(int i=0;i<n;i++){
		cout<<result[i]<<" ";
	}
	
	return result;
}
int main(){
	
	int a[4]={2,7,15,11};
	int b[4]={1,10,4,11};
	
	//vector<int>A=()
	enhance(a,b,4);
	
} 
