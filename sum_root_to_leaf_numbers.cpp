/*Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25.*/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
void dfs(TreeNode*root,vector<int>&path,vector< vector<int> >&allpath){
    	path.push_back(root->val);
    	if(root->left!=NULL)
		{
			dfs(root->left,path,allpath);
			//path.pop_back();
		}
		if(root->right!=NULL){
			dfs(root->right,path,allpath);
		//	path.pop_back();
		}	
	//	cout<<root->val<<endl;
		if(root->left==NULL && root->right==NULL){
			allpath.push_back(path);		
		}
		path.pop_back();
	}

    int sumNumbers(TreeNode *root) {
    	if(root==NULL)
    		return 0;
    	vector<int>path;
    	vector< vector<int> >allpath;
        dfs(root,path,allpath);
        int sum=0;
        int temp=0;
        
        for(int i=0;i<allpath.size();i++){
        	temp=0;
        	for(int j=0;j<allpath[i].size();j++){
        	//	cout<<allpath[i][j]<<"	";
        		temp=temp*10+allpath[i][j];
			} 
			sum+=temp;
		}
		
		return sum;
    }
    
    
int main(){
	
	TreeNode* root=new TreeNode(1);
	root->left=new  TreeNode(2);
	root->right=new TreeNode(3);
	
	cout<<sumNumbers(root);
}


