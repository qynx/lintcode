/*


Լɪ��������һ���ǳ�������Ȥ�⣬����n��������һȦ����˳ʱ����1��ʼ�����Ǳ�š�Ȼ���ɵ�һ���˿�ʼ����������m���˳��֡�
������Ҫ��������һ�����ֵ��˵ı�š�

��������int n��m��������Ϸ���������뷵�����һ�����ֵ��˵ı�š���֤n��mС�ڵ���1000��

����������
5 3
���أ�4
 */
#include<iostream>
using namespace std;

int getResult(int n,int m){
	
	int a[n+1];
	for(int i=0;i<n+1;i++)
		a[i]=0;
	int k=0;
	int i=1;
	int size=n;
	while(1){
		while(k!=m){
			if(a[i]==0){
				k++;
				//�ƹ�m���� 
				if(k==m){
					a[i]=1;
					break;
				}
			}
			i++;
			if(i==n+1)
				i=1;
		}
		k=0;
		
		size--;
		if(size==1)
			break;		
	}
	
	for(i=1;i<=n;i++)
		if(a[i]==0)
			return i; 
	
}
int main(){
	cout<<getResult(5,3);
} 
