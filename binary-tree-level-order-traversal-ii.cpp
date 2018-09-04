 #include<iostream>
 #include<queue>
 #include<vector>
 using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
        vector< vector<int> >result;
        if(!root)
            return result;
        
        vector< vector<int> >::iterator it=result.begin();
        vector<int>temp;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        while(!q.empty()){
            
            int len=q.size();
            cout<<len<<endl;
            for(int i=0;i<len;i++){
                t=q.front();
                cout<<"T  "<<t->val<<endl;
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            it=result.begin();
            result.insert(it,temp);
            temp.clear();
            cout<<"yicixunhuan"<<endl;
        }
        
        return result;
    }

int main(){
	
	TreeNode*root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	
	vector< vector<int> > result=levelOrderBottom(root);
	 
}
