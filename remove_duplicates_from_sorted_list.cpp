#include "header.h"
using namespace std;

 ListNode *deleteDuplicates(ListNode *head) {
        if(!head||!head->next)
            return head;
        ListNode* vhead=new ListNode(0);
        vhead->next=head;
        ListNode* slow=vhead;
        ListNode* fast=head;
        
        while(fast&&fast->next){
        	cout<<slow->val<<" "<<fast->val<<endl;
        	
            if(fast->val!=fast->next->val){
                slow=slow->next;
                fast=fast->next;
            }else{
                while(fast->next&&(fast->val==fast->next->val)){
                    fast=fast->next;
                }
                slow->next=fast;
                cout<<"== "<<slow->val<<" "<<fast->val<<endl;
                fast=fast->next;
            }
        }
        return vhead->next;
    }
    
int main(){
	int a[]={1,1,2,2};
		ListNode*	root=consLNode(a,4);
	root=deleteDuplicates(root);
	print_List(root);
}
