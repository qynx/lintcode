/*
魔法王国一共有n个城市,编号为0~n-1号,n个城市之间的道路连接起来恰好构成一棵树。
小易现在在0号城市,每次行动小易会从当前所在的城市走到与其相邻的一个城市,小易最多能行动L次。
如果小易到达过某个城市就视为小易游历过这个城市了,小易现在要制定好的旅游计划使他能游历最多的城市,请你帮他计算一下他最多能游历过多少个城市(注意0号城市已经游历了,游历过的城市不重复计算)。 
输入描述:
输入包括两行,第一行包括两个正整数n(2 ≤ n ≤ 50)和L(1 ≤ L ≤ 100),表示城市个数和小易能行动的次数。
第二行包括n-1个整数parent[i](0 ≤ parent[i] ≤ i), 对于每个合法的i(0 ≤ i ≤ n - 2),在(i+1)号城市和parent[i]间有一条道路连接。


输出描述:
输出一个整数,表示小易最多能游历的城市数量。

输入例子1:
5 2
0 1 2 3

输出例子1:
3
*/

//第一次运行 没有考虑 可以重复走（但不重复计数的）情况 
//首先尽可能选择走的深 如果回退的话肯定浪费了一步 有多余的步数时才回退 如果有回退 需要考虑 先走哪边再走哪边 
//回退的不知道怎么处理 
#include<iostream>
using namespace std;
 
int dfs(int *a,int *b,int pos,int curl,int l,int n){
	if(curl>l){
		return 0;
	}
	int max=0;
	int cl=0;
	//遍历 父节点为当前节点的节点 
	int flag; 
	for(int i=1;i<n;i++){
		if(a[i]==pos)
		{
			cl=dfs(a,i,curl+1,l,n);
			max=max>cl?max:cl;
			flag=1;
		}
	}
	if(flag==0){  //已无子结点可走 尝试回退 
 		if(curl<l){
 			reverseDfs(a,b,pos,curl,l,n);
		 }
	}
	return 1+max;
} 

int reverseDfs(int *a,int *b,int pos,int curl,int l,int n){
	if(curl>l)
		return 0;
	
}
int main(){
	int n; cin>>n;  //城市个数
	int l; cin>>l; //步数
	
	int parent[n];  //父节点集
	int isvisited[n]={0}; 
	for(int i=1;i<n;i++){
		cin>>parent[i];   //输入父节点 
	} 
	
	int count=1;  //已经游历一个城市
	
	cout<<dfs(parent,isvisited,0,0,l,n); //当前节点为0 已走步数为0  
} 
///////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void traversal(int n,int L,vector<int> &parent){
    int maxlen=0;
    vector<int> dp(n);
    for(int i=0;i<n-1;i++){
        dp[i+1]=dp[parent[i]]+1;
        maxlen=max(maxlen,dp[i+1]);   //使用贪心算法计算最长链的长度
    } 
    int validpath=min(maxlen,L);
    cout<<min(n,1+validpath+(L-validpath)/2);    
}
int main(){
    int n,L;
    cin>>n>>L;
    vector<int> parent;
    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        parent.push_back(temp);
    }
    traversal(n,L,parent);
    return 0;
}
//////////////////////////////////////////////////////////////////////////// 
