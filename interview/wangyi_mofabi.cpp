#include<iostream>
#include<vector>
using namespace std;
/*
С��׼��ȥħ�������ɹ�ħ������,����ħ��������Ҫʹ��ħ����,����С������һöħ���Ҷ�û��,����С������̨ħ����������ͨ��Ͷ��x(x����Ϊ0)��ħ���Ҳ��������ħ���ҡ�
ħ������1:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+1��ħ����
ħ������2:���Ͷ��x��ħ����,ħ�������Ὣ���Ϊ2x+2��ħ����
С�ײɹ�ħ�������ܹ���Ҫn��ħ����,����С��ֻ��ͨ����̨ħ����������ǡ��n��ħ����,С����Ҫ��������һ��Ͷ�뷽��ʹ�����ǡ��ӵ��n��ħ���ҡ� 
��������:
�������һ��,����һ��������n(1 �� n �� 10^9),��ʾС����Ҫ��ħ����������


�������:
���һ���ַ���,ÿ���ַ���ʾ�ô�С��ѡȡͶ���ħ������������ֻ�����ַ�'1'��'2'��

��������1:
10

�������1:
122
*/ 
//ֻ�ܵ����� 
#include<iostream>
#include<vector>

int main(){
	
	long n;
	std::cin>>n;
	std::vector<int>result;
	long curr=0;
	while(n!=0){
		//�����ż�� 
		if(n%2==0)
		{
			result.push_back(2); 
			n=(n/2-1);
			
		}else{
			result.push_back(1);
			n/=2;
		}
	}
	
	for(int i=result.size()-1;i>=0;i--){
		std::cout<<result[i];
	}
	
} 