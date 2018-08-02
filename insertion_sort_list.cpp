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
	ListNode(int x):val(x),next(NULL){
	}
};

class Solution {

public:
    ListNode *insertionSortList(ListNode *head) {
		//很重要，没有先检查指针是否为空 
		ListNode* temp=head;  //外层移动指针 
		ListNode* temp2=head; //内层移动指针 
		ListNode* help;       //辅助换位 
		
		ListNode* temps=head->next;
		head->next=NULL;
		//怎么处理最后一个指针移到头部后，循环的问题，单拿出来，或是计数 
		//每次取出一个元素，先保存它的后一个元素，再把它的后一个置为NULL 
		while(temps!=NULL){
			temp=temps;
			 
			temps=temps->next;
			temp->next=NULL;
				
		//	cout<<temp->val<<endl;
	
			
				while(temp2!=NULL){
					
						
							
					if(temp->val>temp2->val)
						{	
							
							//cout<<temp2->val<<endl;
							if(temp2->next==NULL){
								temp2->next=temp;
								break;
							}
							
							if(temp->val<=temp2->next->val )  //找到组织 
							{
								help=temp2->next;
								temp2->next=temp;
								temp->next=help;
								break;	 
							}else{
								temp2=temp2->next;
							}							
							
						}else{  //根据前面的条件，遇到这种情况说明比第一个小，即头结点 
							
								
								temp->next=head;
								head=temp; 
							//	cout<<"head: "<<head->val<<endl;
								break;
								
							
						}
				
				}
				
				temp2=head;	
				//if(temp2==temp){}  //比之前所有的元素都大  不需要移动								
		}
		
		return head; 
		        
    }

};
 int main(){
 	ListNode *root=new ListNode(1);
 	ListNode* r=root;
 	r->next=new ListNode(2);
 	r=r->next;
 	
 	r->next=new ListNode(3);
 	r=r->next;
 	
 	r->next=new ListNode(4);
 	r=r->next;
 	r->next=new ListNode(5);
	r=r->next; 
 	r->next=NULL;
 	Solution s=Solution();
 	ListNode* ro=s.insertionSortList(root);
 	
 	
 	while(ro!=NULL){
 	
 		cout<<ro->val<<"	";
 		ro=ro->next;
	 }
	 
 }
