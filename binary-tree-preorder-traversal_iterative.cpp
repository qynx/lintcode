#include<iostream>
#include<stack>
#include<vector>
using namespace std;
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        	vector<int> result;
          stack<TreeNode*s>s;
          
         //首先左子结点不为空，结点入栈，值入vector
		  
          /*while(root!=NULL){
          	result.push_back(root->val);
          	s.push(root);
          	root=root->left;
		  }
		  
		TreeNode* temp;
		//挨个弹出 取右子结点的值，栈空了，就没了
		while(s.size()!=0){
			temp=s.top();
			s.pop();
			if(temp->right!=NULL){
				result.push_back(temp->right->val);
				s.push(temp;)
			}
		} */
	/*	s.push(root);
		result.push_back(root->val);
		TreeNode* temp;
		while(s.size()!=0){
			temp=s.top();
			s.pop();
			if(temp->left!=NULL){
				result.push_back(temp->left->val);
				s.push(temp->left);
				temp->left=NULL;
			}
			
		}*/// 这种方法虽然是可行的，但是破坏了原有的结构
		
		while(true){
			
			while(root!=NULL){
				result.push_back(root->val);
				
				if(root->right!=NULL){
					s.push(root->right)
				}
				
				root=root->left;
			}
			
			if(s.size()==0)
				break;
				
			root=s.top();
			s.pop();
			
		}
		return result;
    }
};

int main(){
	
	
}
