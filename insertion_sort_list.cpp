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
		//����Ҫ��û���ȼ��ָ���Ƿ�Ϊ�� 
		ListNode* temp=head;  //����ƶ�ָ�� 
		ListNode* temp2=head; //�ڲ��ƶ�ָ�� 
		ListNode* help;       //������λ 
		
		ListNode* temps=head->next;
		head->next=NULL;
		//��ô�������һ��ָ���Ƶ�ͷ����ѭ�������⣬���ó��������Ǽ��� 
		//ÿ��ȡ��һ��Ԫ�أ��ȱ������ĺ�һ��Ԫ�أ��ٰ����ĺ�һ����ΪNULL 
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
							
							if(temp->val<=temp2->next->val )  //�ҵ���֯ 
							{
								help=temp2->next;
								temp2->next=temp;
								temp->next=help;
								break;	 
							}else{
								temp2=temp2->next;
							}							
							
						}else{  //����ǰ��������������������˵���ȵ�һ��С����ͷ��� 
							
								
								temp->next=head;
								head=temp; 
							//	cout<<"head: "<<head->val<<endl;
								break;
								
							
						}
				
				}
				
				temp2=head;	
				//if(temp2==temp){}  //��֮ǰ���е�Ԫ�ض���  ����Ҫ�ƶ�								
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
