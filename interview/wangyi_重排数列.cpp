/*
С����һ������ΪN������������A = {A[1], A[2], A[3]..., A[N]}��
ţ��ʿ��С�׳���һ������:
������A������������,ʹ����A�������е�A[i] * A[i + 1](1 �� i �� N - 1)����4�ı�����
С��������Ҫ�ж�һ�������Ƿ��������֮������ţ��ʿ��Ҫ�� 
��������:
����ĵ�һ��Ϊ���еĸ���t(1 �� t �� 10),
������ÿ��������һ������A,��һ��Ϊ���г���n(1 �� n �� 10^5)
�ڶ���Ϊn��������A[i](1 �� A[i] �� 10^9)


�������:
����ÿ���������һ�б�ʾ�Ƿ��������ţ��ʿҪ��,����������Yes,�������No��

��������1:
2
3
1 10 100
4
1 2 3 4

�������1:
Yes
No
*/

#include<iostream>
#include<vector>
using namespace std;

//�Ƿ���Ա�4���� 
bool is4(int n){
	if(n%4==0)
	return true;
	return false; 
}

//�Ƿ���Ա�2����
bool is2(int n){
	if(n%2==0)
	return true;
	return false;
} 

//ÿһ������������һ���ܱ�4����������������� 
int main(){
	
	int n;
	cin>>n;
//	vector<int>a;
	int temp;
	int b;
	for(int i=0;i<n;i++){
		cin>>temp;  //�������е����� 
		int oushu=0;
		int jishu=0;
		int by4=0;
		for(int j=0;j<temp;j++){ //���������� 
		cin>>b;
		
		//ͳ����Ϣ 
		if(is2(b))
		{
			oushu++;
			if(is4(b))
			by4++;
		}else{
			jishu++;
		}
		
		//a.push_back(b);			
		}
		
		if(by4<jishu)	 
			cout<<"No"<<endl; 
		else
			cout<<"Yes"<<endl;
	}//��ѭ������  
} 
