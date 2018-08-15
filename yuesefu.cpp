/*


约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。然后由第一个人开始报数，数到m的人出局。
现在需要求的是最后一个出局的人的编号。

给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。

测试样例：
5 3
返回：4
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
				//计够m个人 
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
