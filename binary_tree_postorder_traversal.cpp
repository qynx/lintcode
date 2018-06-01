/*
 Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree{1,#,2,3}, 
*/
#include<iostream>
#include<vector>
#include<stack>
 
using namespace std;

  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int>result;
		if(root==NULL)
			return result;
		
		vector<int>left=postorderTraversal(root->left);     
		vector<int>right=postorderTraversal(root->right);   
		
		if(left.size()>0)
		result.insert(result.end(),left.begin(),left.end());
		if (right.size()>0)
		result.insert(result.end(),right.begin(),right.end());
		
		result.push_back(root->val);
		
		return result;
		
    }
};

int main(){
		
} 
