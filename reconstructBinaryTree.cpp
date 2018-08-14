/*

https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6
输入某二叉树的前序遍历和中序遍历的结果，
请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        vector<int>::iterator preiter=pre.begin();
        vector<int>::iterator viniter=vin.begin();
        int presize=pre.size();
        int vinsize=vin.size();
        
        return reconstruct(preiter,presize,viniter,vinsize);
    }
    
    TreeNode* reconstruct(vector<int>::iterator preiter,int presize,vector<int>::iterator viniter,int vinsize){
        //preize vinsize equal
        if(presize==0)
            return NULL;
        if(presize==1)
            return new TreeNode(*preiter);
        TreeNode* node=new TreeNode(*preiter);
        
        for(int i=0;i<vinsize;i++){
            if(*preiter==*(viniter+i)){
                node->left=reconstruct(preiter+1,i,viniter,i);
                node->right=reconstruct(preiter+i+1,presize-i-1,(viniter+i+1),presize-i-1);
                break;
            }
        }
        return node;
    }
};
