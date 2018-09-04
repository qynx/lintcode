#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
  class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return toBST(num,0,num.size()-1);
    }
    
    TreeNode* toBST(vector<int>&num,int l,int r){
        if(l>r)
            return NULL;
        int mid=(l+r)/2;
        
        TreeNode* root=new TreeNode(num[mid]);
        
        root->left=toBST(num,l,mid-1);
        root->right=toBST(num,mid+1,r);
        
        return root;
    }
};
TreeNode *sortedListToBST(ListNode *head) {
		if(!head) return NULL;
		if(head->next==NULL) return new TreeNode(head->val);
	 	queue<TreeNode* >q;  //队列中存储待求左右子结点的元素 
	 	
	 	TreeNode*root=new TreeNode(head->val);
	 	q.push(root);
	 	
	 	TreeNode* temp=root;
		ListNode* cur=head;
		while(cur->next!=NULL){
			temp=q.front();
			q.pop();
			cur=cur->next;
			
			temp->left=new TreeNode(cur->val);
			q.push(temp->left);
			cur=cur->next;
			if(cur){
				 
				temp->right=new TreeNode(cur->val);
				q.push(temp->right);}
			else
				break;
		}
		
		return root;       
}
int main(){
	vector<int>c;
	vector<int>::iterator it=c.begin();
	c.insert(it,1);
	cout<<c[0]<<endl;
}
