
 #include<iostream>
 #include<queue>
 #include<vector>
 using namespace std;
 
/* inorder 是 中序遍历
   postorder 后续遍历 
*/ 

/* 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int offset,int l,int r);
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0)
        return NULL;
        TreeNode* r=build(inorder,postorder,inorder.size()-1,0,postorder.size()-1);
        //cout<<r->val;
        return r;
    }
    
    TreeNode* build(vector<int>&inorder,vector<int>&postorder,int offset,int l,int r){
    	if(l>r)
    		return NULL;
    	//cout<<inorder[offset]<<endl;
        if(offset<0||offset>=inorder.size())
            return NULL;
    	TreeNode* root=new TreeNode(inorder[offset]);
    	if(l==r)
    		return root;
    	int index;
    	int left; 
    	for(int i=0;i<postorder.size();i++){
    		if(postorder[i]==inorder[offset]){
    			index=i;
			}
		}
		if(index>l){ //如果存在右树 
		
		
		root->left=build(inorder,postorder,offset-r+index-1,l,index-1);
		root->right=build(inorder,postorder,offset-1,index+1,r);}
		else{
			root->right=build(inorder,postorder,offset+1,index+1,r);
		} 
    	return root;
	} 

void preorder(TreeNode* root){
	if(root){
		cout<<root->val<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        vector<int>::size_type lenIn = inorder.size();
        vector<int>::size_type lenPost = postorder.size();
        return buildTree_Aux(inorder,0,lenIn-1,postorder,0,lenPost-1);
    }
     
    TreeNode *buildTree_Aux(vector<int> &inorder,int inB,int inE,
                            vector<int> &postorder,int poB,int poE) {
        if(inB > inE || poB > poE)
            return NULL;
        //在后序遍历中确定根节点
        TreeNode* root = new TreeNode(postorder[poE]);
        //在中序遍历中确定左右子树
        vector<int>::iterator iter = find(inorder.begin()+inB,inorder.begin()+inE,postorder[poE]);
        int index = iter - inorder.begin();
        root->left = buildTree_Aux(inorder,inB,index-1,postorder,poB,poB+index-1-inB);
        root->right = buildTree_Aux(inorder,index+1,inE,postorder,poB+index-inB,poE-1);
        return root;
    }
};
int main(){
	int a[2]={2,1};
	int b[2]={2,1};
	vector<int>inorder(a,a+2);
	vector<int>postorder(b,b+2);
	
	TreeNode*root=buildTree(inorder,postorder);
	//cout<<root->val;
	preorder(root);
}
