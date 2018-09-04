/*给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：

区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:

 

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
