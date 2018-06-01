/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 

Given a singly linked list L: L 0��L 1������L n-1��L n,
reorder it to: L 0��L n ��L 1��L n-1��L 2��L n-2����

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}. 
*/ 
#include<iostream>
#include<malloc.h> 
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
//�ҵ��м�ڵ㣬�����㲻��Ҫ�䶯  
class Solution {
public:
	
	//��ת���� 
	ListNode* reverse(ListNode* head){
		
		if(head==NULL) return head;
		
		ListNode* p=head;
		ListNode*q=p->next;
		p->next=NULL;
		ListNode*temp=NULL;
		
		//��Ϊ���Ҫ����һ��ͷָ�룬���ﲻ��temp�ƶ���NULL����Ȼ
		//�Ͷ��˶��µ�headָ�� 
		while(temp->next!=NULL){
			temp=q->next;
			q->next=p;
			p=q;
			q=temp;	
		}		
		
		q->next=p;
		return q;
	} 
	
    void reorderList(ListNode *head) {
       cout<<"can"<<endl; 
	    ListNode* slow=head;
		ListNode* fast=head;
		
		while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
			
			slow=slow->next;
			
			fast=fast->next->next;
			
		}
		 
		if(fast->next!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
		
		//slow �ƶ���һ�� fast�ƶ������һ��Ԫ��
		
		ListNode* start=slow->next;
		slow->next=NULL;
		
		//��벿������ת 
		start=reverse(start);
		
		ListNode*temp=NULL;
		ListNode* left=head;
		
		//�ֿ�����ߵ�Ԫ�����Ƕ����ұߵ�Ԫ��
		//�ָ��㷨�����ģ�����ֻ��Ҫ�ж��ұߵı�
		//�Ƿ��յ� 
		while(start!=NULL){
			temp=left->next;	
			left->next=start;
			start=start->next;
			left=left->next;
		} 
		
		//return head; 
    }
    
    void printtest(){
    	cout<<"This is a test"<<endl;
	}
};
	//��ת���� 
	ListNode* reverse(ListNode* head){
	
//		cout<<head->val<<endl; 
		if(head==NULL || head->next==NULL) 
			return head;
	
		ListNode* p=head;
		ListNode*q=p->next;
		ListNode*temp=q;
		p->next=NULL;
		
		
		//��Ϊ���Ҫ����һ��ͷָ�룬���ﲻ��temp�ƶ���NULL����Ȼ
		//�Ͷ��˶��µ�headָ�� 
		while(temp->next!=NULL){
			temp=q->next;
			q->next=p;
			p=q;
			q=temp;	
		}		
		
		q->next=p;
		
			//cout<<q->val<<endl;
		return q;
	} 
	
    void reorderList(ListNode *head) {
       //  cout<<"can"<<endl; 
       if(head==NULL || head->next==NULL||head->next->next==NULL)
       		return;
	    ListNode* slow=head;
		ListNode* fast=head;
		
		while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
			
			slow=slow->next;
			
			fast=fast->next->next;
			
		}
		 
		if(fast->next!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
		
		//slow �ƶ���һ�� fast�ƶ������һ��Ԫ��
		
		ListNode* start=slow->next;
		slow->next=NULL;

		//��벿������ת 
		start=reverse(start);
		
		ListNode*temp=NULL;
		ListNode* left=head;
		ListNode*right=start; 
	
		//�ֿ�����ߵ�Ԫ�����Ƕ����ұߵ�Ԫ��
		//�ָ��㷨�����ģ�����ֻ��Ҫ�ж��ұߵı�
		//�Ƿ��յ� 
		while(start!=NULL){
			temp=left->next;	
			left->next=start;
			right=left->next;
			
			//ָ������ƶ� 
			start=start->next;
			
			
			right->next=temp;
			left=left->next->next;
		} 
		
		//return head; 
    }
    
    void printtest(){
    	cout<<"This is a test"<<endl;
	}
int main(){
	cout<<"-----------main_____----------------------"<<endl;
	ListNode*root=(ListNode*)malloc(sizeof(ListNode*));
	root->val=1;
	ListNode t2=ListNode(2);
	root->next=&t2;
	ListNode t3=ListNode(3);
	ListNode t4=ListNode(4);
	root->next->next=&t3;
	root->next->next->next=&t4;	
	ListNode t5=ListNode(5);
	root->next->next->next->next=&t5;
		ListNode t6=ListNode(6);
	ListNode t7=ListNode(7);
//	root->next->next->next->next->next=&t6;
//	root->next->next->next->next->next->next=&t7;
//	Solution s=Solution();
	//cout<<"can"<<endl; 
	//s.printtest();
	reorderList(root);
//	cout<<"can"<<endl; 
	while(root!=NULL){
		cout<<root->val<<endl;
		root=root->next;
	}
	
//	cout<<root->next->val;
}
