#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	char a[n][m];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	
	//�ӵ����ڶ�������  �Ⱦ������µ��� ������������ 
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<m;j++){
			int k;
			if(a[i][j]=='o'){ //��ľ�� �ſ��Ե���
			
			if(a[i+1][j]=='.'){ //��һ���Ƿ�Ϊ��
			
			//��������ܵ����λ�� 
			for(k=i+1;k<n;k++){
				if(a[k][j]!='.'){
					break;
				}
			}
			//�����пո���  ����Ӧ�ò������ж���
			if(k>i+1){
				a[k-1][j]='o';
				a[i][j]='.';
			}
		       }//�����һ����Ե��� 
			}//���Ϊľ�� 
		}
	
	//�����ܵ���ȥ�� �����һ������ ���� �����ľ���� �Ͷ��ܵ���ȥ
	for(int j=0;j<m;j++){
		int i; 
		for( i=n-1;i>=0;i--){
			if(a[i][j]=='x'){
				break;
			} 
		}
		for(int k=i+1;k<n;k++){
			a[k][j]='.';
		}
	} 
	
    //���
	for(int i=0;i<n;i++){
	
		for(int j=0;j<m;j++){
			cout<<a[i][j];
		} 
		cout<<endl;	
	}
} 
