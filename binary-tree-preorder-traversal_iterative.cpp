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
          
         //�������ӽ�㲻Ϊ�գ������ջ��ֵ��vector
		  
          /*while(root!=NULL){
          	result.push_back(root->val);
          	s.push(root);
          	root=root->left;
		  }
		  
		TreeNode* temp;
		//�������� ȡ���ӽ���ֵ��ջ���ˣ���û��
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
			
		}*/// ���ַ�����Ȼ�ǿ��еģ������ƻ���ԭ�еĽṹ
		
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
