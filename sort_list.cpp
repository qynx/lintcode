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
		if(left->val<right->val){
			//root->val=left->val;
			root=left;
			root->next=merge(left->next,right);
		}else{
			//root->val=right->val;
			root=right;
			root->next=merge(left,right->next);
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
	
	
}
