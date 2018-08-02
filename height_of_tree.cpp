#include<iostream>
using namespace std;
/*
������һ�úϷ��Ķ����������Ľڵ㶼�������ֱ�ʾ�����ڸ�������������еĸ��ӹ�ϵ����������ĸ߶�
����ĵ�һ�б�ʾ�ڵ�ĸ���n��1 �� n �� 1000���ڵ�ı��Ϊ0��n-1����ɣ�
������n-1�У�ÿ����������������һ������ʾ���ڵ�ı�ţ��ڶ�������ʾ�ӽڵ�ı��

*/ 
struct Node{
	int left;
	int right;
	Node(int x=-1,int y=-1){
		left=x;
		right=y;
	} 
};

//nodesΪ������� i Ϊ��ǰ�ڵ� 
int computeHeight(struct Node*nodes,int i){
	
	if((nodes[i].left==-1) && (nodes[i].right==-1)){
		return 1;
	}else if(nodes[i].left==-1){
		return 1+computeHeight(nodes,nodes[i].right); 
	}else if(nodes[i].right==-1){
		return 1+computeHeight(nodes,nodes[i].left); 
	}else{
		int leftHeight=1+computeHeight(nodes,nodes[i].left);
		int rightHeight=1+computeHeight(nodes,nodes[i].right);
		
		return leftHeight>rightHeight?leftHeight:rightHeight;
	}	
	
} 

int main(){
	
	int a;
	cin>>a; //������ 
	
	if(a==0){
		cout<<0;
		return 0;
	}
	
	struct Node nodes[a];

	int n;
	
	int p;
	for(int i=0;i<a-1;i++){
		
		cin>>n;
		if(nodes[n].left==-1){
			cin>>nodes[n].left;
		}else if(nodes[n].right==-1){
			cin>>nodes[n].right;
		}else{
			cin>>p;
		}	
	}
	//�������
	
	cout<<computeHeight(nodes,0); 
		
} 
