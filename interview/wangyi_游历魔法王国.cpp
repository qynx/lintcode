/*
ħ������һ����n������,���Ϊ0~n-1��,n������֮��ĵ�·��������ǡ�ù���һ������
С��������0�ų���,ÿ���ж�С�׻�ӵ�ǰ���ڵĳ����ߵ��������ڵ�һ������,С��������ж�L�Ρ�
���С�׵����ĳ�����о���ΪС�����������������,С������Ҫ�ƶ��õ����μƻ�ʹ�����������ĳ���,�����������һ������������������ٸ�����(ע��0�ų����Ѿ�������,�������ĳ��в��ظ�����)�� 
��������:
�����������,��һ�а�������������n(2 �� n �� 50)��L(1 �� L �� 100),��ʾ���и�����С�����ж��Ĵ�����
�ڶ��а���n-1������parent[i](0 �� parent[i] �� i), ����ÿ���Ϸ���i(0 �� i �� n - 2),��(i+1)�ų��к�parent[i]����һ����·���ӡ�


�������:
���һ������,��ʾС������������ĳ���������

��������1:
5 2
0 1 2 3

�������1:
3
*/

//��һ������ û�п��� �����ظ��ߣ������ظ������ģ���� 
//���Ⱦ�����ѡ���ߵ��� ������˵Ļ��϶��˷���һ�� �ж���Ĳ���ʱ�Ż��� ����л��� ��Ҫ���� �����ı������ı� 
//���˵Ĳ�֪����ô���� 
#include<iostream>
using namespace std;
 
int dfs(int *a,int *b,int pos,int curl,int l,int n){
	if(curl>l){
		return 0;
	}
	int max=0;
	int cl=0;
	//���� ���ڵ�Ϊ��ǰ�ڵ�Ľڵ� 
	int flag; 
	for(int i=1;i<n;i++){
		if(a[i]==pos)
		{
			cl=dfs(a,i,curl+1,l,n);
			max=max>cl?max:cl;
			flag=1;
		}
	}
	if(flag==0){  //�����ӽ����� ���Ի��� 
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
	int n; cin>>n;  //���и���
	int l; cin>>l; //����
	
	int parent[n];  //���ڵ㼯
	int isvisited[n]={0}; 
	for(int i=1;i<n;i++){
		cin>>parent[i];   //���븸�ڵ� 
	} 
	
	int count=1;  //�Ѿ�����һ������
	
	cout<<dfs(parent,isvisited,0,0,l,n); //��ǰ�ڵ�Ϊ0 ���߲���Ϊ0  
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
        maxlen=max(maxlen,dp[i+1]);   //ʹ��̰���㷨��������ĳ���
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
