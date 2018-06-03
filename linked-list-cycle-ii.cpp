/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
  Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.

Follow up:
Can you solve it without using extra space? 
*/

#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
  
ListNode *detectCycle(ListNode *head) {
      
      if(head==NULL || head->next==NULL)
      	return NULL;
      	
      ListNode*slow=head;
	  ListNode*fast=head; 
	  
	  while(fast!=NULL && fast->next!=NULL){
	  		
	  		slow=slow->next;
	  		fast=fast->next->next;
	  		
	  		if(slow==fast){   //ÓÐ»· 
	  			
			  	ListNode* x=head;
				ListNode *y=slow;
				
				while(x!=y){
					x=x->next;
					y=y->next;
				} 
				
				return x;
			  }
	  	
	  } 
	  
	  return NULL; 
}
    
int main(){
	
} 
