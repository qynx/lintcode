/*����һ����������, ��Ҫ��ѡ��һ������, ʹ�ø����������������о������¼����ֵ����һ����

�����е���С�� * �����������ĺ�����������������������ֵ���ɣ�����Ҫ�����������䡣���������  [6 2 1]�����������ʽ, �ɵõ����п���ѡ����������ļ���ֵ:

 

[6] = 6 * 6 = 36;

[2] = 2 * 2 = 4;

[1] = 1 * 1 = 1;

[6,2] = 2 * 8 = 16;

[2,1] = 1 * 3 = 3;

[6, 2, 1] = 1 * 9 = 9;*/
#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
//	int dp[n][n];
	int step;
	int result=0;
	int min;
	for(int step=1;step<=n;step++){
		for(int i=0;i+step-1<n;i++){
			int sum=0;
			min=a[i];
			for(int j=0;j<step;j++)
			{
				sum+=a[i+j];
				min=a[i+j]<min?a[i+j]:min;
			}
			//dp[i][i+step-1]=min*sum;
			sum=min*sum;
			result=result>sum?result:sum;
		}
	}
	
	cout<<result;
}
