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
    BinTree *cur;                      //��ǰ��� 
    BinTree *pre=NULL;                 //ǰһ�η��ʵĽ�� 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
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
