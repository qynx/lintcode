#include<iostream>
#include<map>
using namespace std;
/*
1/3 循环体为3 循环体长度为1 开始位置为0（小数点后的位置） 返回 0,1 
5/4  可以整除 小数点后位数为2  因此 返回 2,0 
 
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
			//可以找到 略有疑问 不会出现 0.112这样的形式吗 
			flag=1;
			return make_pair(position[a],now-position[a]); 
		}else{
			//找不到
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
