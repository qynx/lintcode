/*
广度优先遍历二叉树*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> bfs(TreeNode* root){
	queue<TreeNode* >temp;
	vector<int>result;
	
	temp.push(root);
	TreeNode*tempnode;
	while(!temp.empty()){
		
		tempnode=temp.front();
		temp.pop();
		if(tempnode->left!=NULL)
			temp.push(tempnode->left);
		if(tempnode->right!=NULL)
			temp.push(tempnode->right);
		result.push_back(tempnode->val);
	}	 
	
	return result;
}
int main(){
	
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->right=new TreeNode(4);
	root->right->right=new TreeNode(5);
	vector<int>result=bfs(root);
	
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<"	";
	 } 
} 
