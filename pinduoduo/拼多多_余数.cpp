#include<iostream>
#include<map>
using namespace std;
/*
1/3 ѭ����Ϊ3 ѭ���峤��Ϊ1 ��ʼλ��Ϊ0��С������λ�ã� ���� 0,1 
5/4  �������� С�����λ��Ϊ2  ��� ���� 2,0 
 
*/
pair<int,int>result;
map<int,int>position;
pair<int,int>solve(int a,int b){
	
	a=a%b;
	
	int flag=0;
	int now=0;
	position.clear();
	while(true){
	
		a=a%b;
		
		if(position.find(a)!=position.end()){
			//�����ҵ� �������� ������� 0.112��������ʽ�� 
			flag=1;
			return make_pair(position[a],now-position[a]); 
		}else{
			//�Ҳ���
			position[a]=now; 
		}
		
		if(a==0){
			flag=1;
			return make_pair(now,0);
		}
		
		a*=10;
		
		now++;
	}
}
int main(){
	
	int a,b;
	cin>>a>>b;
	
	result=solve(a,b);	
	cout<<result.first<<" "<<result.second<<endl;
} 
