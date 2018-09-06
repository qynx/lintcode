#include<iostream>
#include<vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  TreeNode* build(vector<int>&preorder,vector<int>&inorder,int startp,int endp,int starti,int endi);
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if(preorder.size()==0)
		return NULL;    	
		return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);    
    }
TreeNode* build(vector<int>&preorder,vector<int>&inorder,int startp,int endp,int starti,int endi){
	
	if(startp>endp)
		return NULL;
	TreeNode* root=new TreeNode(preorder[startp]);
	
	if(startp==endp)
		return 	root;
	int index=-1;
	for(int i=starti;i<=endi;i++){
		if(inorder[i]==preorder[startp])
			index=i;  //头结点在中序数组的索引 
	}
	cout<<index<<endl;
	cout<<startp+1<<" "<<startp+index-starti<<" "<<starti<<" "<<index-1<<endl;
	root->left=build(preorder,inorder,startp+1,startp+index-starti,starti,index-1);
	root->right=build(preorder,inorder,startp+index-starti+1,endp,index+1,endi); 
			 
	return root;
}

 int main(){
 	int p[2]={1,2};
 	int i[2]={2,1};
 	vector<int>preorder=vector<int>(p,p+2);
 	
 	vector<int>inorder=vector<int>(i,i+2);
 	
 	TreeNode* root=buildTree(preorder,inorder);
 	
 	cout<<root->val; 
 	cout<<root->left->val;
 }   
    
    
    

