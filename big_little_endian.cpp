#include<iostream>
using namespace std;

int main(){
/*	int a=0x12345678;
	
	char b=*(char *)&a;
	char c=a;
	cout<<int(b)<<endl;
	cout<<(b==0x78)<<endl;
	cout<<(c==0x78)<<endl;*/
	
	short int a = 0x1122;//ʮ�����ƣ�һ����ֵռ4λ
	char b =  *(char *)&a;  //ͨ����short(2�ֽ�)ǿ������ת����char���ֽڣ�bָ��a����ʼ�ֽڣ����ֽڣ�
	if( b == 0x11)//���ֽڴ�������ݵĸ��ֽ�����
	{
		cout<<"���";
	}
	else
	{
		cout<<"��С��ģʽ";
	}
} 
