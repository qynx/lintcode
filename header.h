/*
LintNode 刷题专用头文件
*/ 
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<set> 
#include<queue>
#include<stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};



void print_Intvector(vector<int>&v);  //打印整数向量组
void print_List(ListNode* root);     //打印单链表 
ListNode* consLNode(int *a,int n); 	//输入数组 构建对应单链表 



//implementions 
void print_Intvector(vector<int>&v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void print_List(ListNode *root){
	ListNode* p=root;
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}

ListNode* consLNode(int *a,int n){
	if(n==0)
	return NULL;
	ListNode* root=(ListNode*)malloc(sizeof(ListNode));
	ListNode* tmp=root;
	
	for(int i=0;i<n-1;i++){
		tmp->val=a[i];
		tmp->next=(ListNode*)malloc(sizeof(ListNode));
		tmp=tmp->next; 
	}
	tmp->val=a[n-1];
	tmp->next=NULL;
	return root;
} 
