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
        
        
        stack<BinTree*> s;
    BinTree *cur;                      //当前结点 
    BinTree *pre=NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
              s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
    }
};

int main(){
	
}
