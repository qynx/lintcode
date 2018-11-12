#include "header.h"


ListNode *partition(ListNode *head, int x) {
        if(!head||!head->next)
            return head;
        ListNode* in=head;
        ListNode* vhead=(ListNode*) malloc(sizeof(ListNode));
        vhead->val=0;
        vhead->next=head;
        
        ListNode* left=vhead;
        ListNode* right=vhead;
        
        while(in!=NULL){ 
	   
            if(in->val<x)
                left=in;
            else
            {
                right=in;
                break;
            }
            in=in->next;
        }
        //cout<<in->val<<endl;
        while(in->next!=NULL){
        //	cout<<in->next->val<<endl;
            if(in->next->val<x){
                
				left->next=in->next;
             	//cout<<"Ð¡ÓÚ "<<in->next->val<<endl;
                in->next=in->next->next;
              	//	cout<<"´îÅä "<<in->next->val<<endl;
                
                left=left->next;
            }
            else{
            	in=in->next;
			}
        }
        
        left->next=right;
        left=vhead->next;
        free(vhead);
        return left;
        
    }

int main(){
	int a[6]={1,1};
	
	ListNode* root=consLNode(a,0);
	print_List(root); 
	root=partition(root,0);
	print_List(root);
}	
