#include<iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	
	char a[n][m];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	
	//从倒数第二排向上  先尽量向下掉落 但不掉出棋盘 
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<m;j++){
			int k;
			if(a[i][j]=='o'){ //是木块 才可以掉落
			
			if(a[i+1][j]=='.'){ //下一层是否为空
			
			//计算最大能掉落的位置 
			for(k=i+1;k<n;k++){
				if(a[k][j]!='.'){
					break;
				}
			}
			//下面有空格子  这里应该不用再判断了
			if(k>i+1){
				a[k-1][j]='o';
				a[i][j]='.';
			}
		       }//如果下一层可以掉落 
			}//如果为木块 
		}
	
	//所有能掉出去的 从最后一层向上 遍历 如果是木块或空 就都能掉出去
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
	
    //输出
	for(int i=0;i<n;i++){
	
		for(int j=0;j<m;j++){
			cout<<a[i][j];
		} 
		cout<<endl;	
	}
} 
