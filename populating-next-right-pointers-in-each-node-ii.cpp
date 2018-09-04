#include<iostream>
#include<queue>
using namespace std;
/*
You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

void bfs(queue<TreeLinkNode*>&q){
	queue<TreeLinkNode*> temp;
	while(!q.empty()){
	//	queue<TreeLinkNode*>::iterator it=q.begin();
		TreeLinkNode*node;
		int len=q.size();
		while(len>1){
			node=q.front();
			q.pop();
			node->next=q.front();
			temp.push(node);
			len--;
		}
		
		node=q.front();
		temp.push(node);
		q.pop();
		
	
		len=temp.size();
		while(len){
			TreeLinkNode*left=temp.front()->left;
			TreeLinkNode*right=temp.front()->right;
			if(left)
			q.push(left);
			if(right)
			q.push(right);
			temp.pop();
			len--;
		}
		
	}
	
}
void connect(TreeLinkNode *root) {
	if(root==NULL)
		return ;
		
	queue<TreeLinkNode*>q;
	q.push(root);
	bfs(q);
	 
	return ;        
}
int main(){
//	queue<int>::iterator it;
}
