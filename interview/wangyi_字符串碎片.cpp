/*
һ����Сд��ĸ��ɵ��ַ������Կ���һЩͬһ��ĸ�������Ƭ��ɵġ�����,"aaabbaaac"����������Ƭ��ɵ�:'aaa','bb','c'��ţţ���ڸ���һ���ַ���,���������������ַ�����������Ƭ��ƽ�������Ƕ��١�

��������:
�������һ���ַ���s,�ַ���s�ĳ���length(1 �� length �� 50),sֻ��Сд��ĸ('a'-'z')


�������:
���һ������,��ʾ������Ƭ��ƽ������,�������뱣����λС����

��������ʾ: s = "aaabbaaac"
������Ƭ��ƽ������ = (3 + 2 + 3 + 1) / 4 = 2.25

��������1:
aaabbaaac

�������1:
2.25
*/

#include<iostream>
#include<vector> 
#include<iomanip>
using namespace std;

int main(){
	string s;
	cin>>s;
	
	int i=0;  
	int len=s.length();
	int temp; //��ǰ��Ƭ���� 
	vector<int>result;
	//count=1;
	temp=1;
	while(i<(len-1)){
		if(s[i]==s[i+1])
		{
			temp+=1;
		}else{
			result.push_back(temp);
			temp=1; 
		}
		i++;
	}
	
	//�Ƶ�������һ��Ԫ��ʱ����������ᱻwhileѭ����ֹ 
	if(s[len-1]==s[len-2])
		result.push_back(temp);
	else
		result.push_back(1);
	
	int sum=0;
	for(int i=0;i<result.size();i++){
		sum+=result[i]; 
	} 
	cout<<fixed<<setprecision(2)<<(float)sum/result.size();
} 
