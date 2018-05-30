//Sort a linked list in O(n log n) time using constant space complexity. 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
	ListNode * merge(ListNode*left,ListNode*right){
		if(right==NULL)
			return left;
		if(left==NULL)
			return right;
		
	//	ListNode * root=malloc(sizeof(Node));
		ListNode * root=NULL;
		ListNode * tail=NULL;
		if(left->val<right->val)
			{
			root=left;
			left=left->next;
			}
		else{
			
			root=right;
			right=right->next;
		}
		
		tail=root;		
			
		while(left!=NULL && right!=NULL){
			
			if(left->val<right->val){
				tail->next=left;  //链接 
				tail=tail->next;  //移动尾指针 
				left=left->next; //链表移动 
			}else{
				tail->next=right;
				tail=tail->next;
				right=right->next;
			}
			
			
		}
		
		if(left!=NULL){
			tail->next=left;
		}else{
			tail->next=right;
		}
		
		return root;
	
	}
    ListNode *sortList(ListNode *head) {
    	
		if(head==NULL ||head->next==NULL)  return head;
    	ListNode*slow=head;
		ListNode*fast=head;
		
		while(fast!=NULL && fast->next!=NULL && fast->next->next != NULL){
			fast=fast->next->next;
			slow=slow->next;
		}  
		
		ListNode* head2=slow->next;
		
		slow->next=NULL;
		
		return merge(sortList(head),sortList(head2));
    }
};

int main(){
	
	ListNode*left=new ListNode(0); 
	left->next=new ListNode(1);
	ListNode*right=new ListNode(2); 
	right->next=new ListNode(3);
	
	cout<<left->next->val<<endl;
	ListNode* root=left;
	ListNode* tail=root;
	tail->next=right;
	cout<<left->next->val;
}
