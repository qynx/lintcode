#include<iostream>
#include<vector>
using namespace std;
vector<int>result;
void swap(vector<int>&a,int i,int begin){
	int temp=a[i];
	a[i]=a[begin];
	a[begin]=temp;
}
void quanpai(vector<int>&a,int begin,int end){
	if(begin==end){
		result.push_back(a[begin]);
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		result.pop_back();
		return;
	}
	for(int i=begin;i<=end;i++){
		int flag=0;
		
		//�����ǰ�� �Ƿ�����ͬ��
		//�� 3 2 1 1
		//���ĸ�1����ǰ�����ʱ �������������1��һ����		 
		/*for(int j=i-1;j>=begin;j--){
			if(a[j]==a[i]){
				flag=1;
			}
		}*/
		if((i==begin||a[i]!=a[begin])){
		swap(a,i,begin);
		result.push_back(a[begin]);
		quanpai(a,begin+1,end);
		result.pop_back();
		swap(a,i,begin);
		}
		
	}	
}
int main(){
	
	vector<int>a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	quanpai(a,0,a.size()-1);
} 
