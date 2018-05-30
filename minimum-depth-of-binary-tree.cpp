class Solution {
public:
    int run(TreeNode *root) {
        if(root==NULL)
            return 0;
        else if((root->left!=NULL)&&(root->right!=NULL)){
            int minLeft=run(root->left)+1;
            int minRight=run(root->right)+1;
            return minLeft>minRight?minRight:minLeft;
        }else if(root->left!=NULL){
            return run(root->left)+1;
        }else{
            return run(root->right)+1;
        }
    }
};
