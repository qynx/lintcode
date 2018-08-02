#include<iostream>
using namespace std;
/*
现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n-1）组成，
下面是n-1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号

*/ 
struct Node{
	int left;
	int right;
	Node(int x=-1,int y=-1){
		left=x;
		right=y;
	} 
};

//nodes为结点数组 i 为当前节点 
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
	cin>>a; //结点个数 
	
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
	//完成输入
	
	cout<<computeHeight(nodes,0); 
		
} 
