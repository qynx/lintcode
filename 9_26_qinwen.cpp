#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int *enhance(int *a,int *b,int n){
	//a , b��������� n���鳤�� 
	int flag[n];
	//int deal[n]; 
	int *result=(int *)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++)
		{
		flag[i]=0;
		//deal[i]=0;
		result[i]=-1;
		}
		
	for(int i=0;i<n;i++){  //����B��ÿһ��Ԫ�� ��a��Ѱ�� �պñ����� 
		
		int neightborGreat=-1;
		
		for(int j=0;j<n;j++){
			if(!flag[j]&&a[j]>b[i]){  //���a�� ��ǰԪ��û���ù� ���� ���b�е�ǰԪ��ֵ�� 
				if(neightborGreat==-1){  //���neightborGreat��δ����ֵ 
				
					neightborGreat=a[j];
					flag[j]=1;
				} 
				else //���neightborGreat�Ѿ�����ֵ ���ж����Ƿ���b�е�ǰֵ ���ӽ�  
				/*
				
				�˴� �����޸���һ���϶�Ϊneighbor��flagֵ 
				*/ 
					{
						if(a[j]<neightborGreat){
							neightborGreat=a[j];
							flag[j]=1;
						}
					}
			}
		}//a��Ѱ���Ƿ��з���������ֵ
		
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
