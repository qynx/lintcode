#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

 ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
        	return pHead2;
        if(!pHead2)
        	return pHead1;
        ListNode* start;
        if(pHead1->val<pHead2->val){
        	start=pHead1;
        	pHead1=pHead1->next;
		}else{
				start=pHead2;
        	pHead2=pHead2->next;
		}
		ListNode* temp=start;
		while(pHead1&&pHead2){
        	if(pHead1->val<pHead2->val){
        		temp->next=pHead1;
        		temp=temp->next;
        		pHead1=pHead1->next;
			}else{
				temp->next=pHead2;
				temp=temp->next;
				pHead2=pHead2->next;
			}
		}
		if(pHead1)
			temp->next=pHead1;
		else
			temp->next=pHead2; 
		
		return start;
    }

int main(){
	ListNode*p1=new ListNode(1);
	p1->next=new ListNode(3);
	p1->next->next=new ListNode(5);
	ListNode*p2=new ListNode(2);
	p2->next=new ListNode(3);
	p2->next->next=new ListNode(6);
	
	ListNode* start=Merge(p1,p2);
	
	while(start){
		cout<<start->val<<" ";
		start=start->next; 
	}
	
}
