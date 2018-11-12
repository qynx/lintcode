#include "header.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next)
            return head;
        ListNode *vhead=new ListNode(0);
        vhead->next=head;
        ListNode* slow=vhead;
        ListNode* fast=head;
        
        while(fast!=NULL&&fast->next!=NULL){
            if(fast->val!=fast->next->val){
                fast=fast->next;
                slow=slow->next;
            }else{
               
                while(fast->next&&(fast->val==fast->next->val)){
                    fast=fast->next;
                }
                fast=fast->next;
                slow->next=fast;
                
            }
        }
        return vhead->next;
    }
};

int main(){
	
	return 0;
} 
