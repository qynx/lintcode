#include<iostream>
#include<malloc.h>
using namespace  std;

template <typename E> class BinNode{
	public :
		virtual ~BinNode(){}
		
		virtual E& element()=0;
		
		virtual void setElement(const E&)=0;
		
		virtual BinNode* left() const=0;
		
		virtual BinNode* right() const=0;
		
		virtual void setRight(BinNode* )=0;
		
		virtual bool isLeaf()=0;
};

template<typename Key,typename E>
class BSTNode:public BinNode<E>{

	public:
		Key k;
		E it;
		BSTNode *lc;
		BSTNode *rc;
		
	public:
		BSTNode(){
			lc=rc=NULL;
		}		
		
		BSTNode(Key K,E e,BSTNode* l=NULL,BSTNode* r=NULL){
			k=K;
			it=e;
			lc=l;
			rc=r;
		}
		BSTNode(E e,BSTNode* l=NULL,BSTNode* r=NULL){
			
			it=e;
			lc=l;
			rc=r;
		}
		
		E& element(){
			return it;
		}
		
		void setElement(const E& e){
			it=e;
		}
		
		Key& key(){
			return k;
		}
		
		void setKey(const Key&K){
			k=K;
		}
		
		inline BSTNode*left() const{
		return lc;}
		
		inline BSTNode*right() const{
		return rc;}
		
		void setLeft(BinNode<E> *b){
			lc=(BSTNode*)b;
		}
		
		void setRight(BinNode<E> *b){
			rc=(BSTNode*)b;
		}
		
		bool isLeaf(){
			return (lc==NULL)&&(rc=NULL);
		}
		
};

int maps[12]={0};

//输入二叉树的前序序列和 中序序列 生成二叉树 
BSTNode<int,int>* insert(int pre[],int  n,int offset){
	
	if(n==0) return NULL;
	
	int rootval=pre[0];
	//cout<<rootval<<endl;
	int i=maps[rootval]-offset;
	
	BSTNode<int,int>* root;
	root=(BSTNode<int,int>*)malloc(sizeof(BSTNode<int,int>));
	root->it=rootval;
	cout<<i<<endl;
	root->lc=insert(pre+1,i,offset);
	
	root->rc=insert(pre+i+1,n-i-1,offset+i+1);
	
	return root;
				
}

void pre_order(BSTNode<int,int>*root){
	
	if(root==NULL) return;
	cout<<root->it;
	
	pre_order(root->lc);
	pre_order(root->rc);
}



int main(){
//	BSTNode<int,int>root=BSTNode<int,int>(1,1);
	
	int pre[6]={3,4,5,7,6,9};
	int in[6]={5,4,7,3,6,9};
	//int maps[6]={};
	for(int i=0;i<6;i++){
		maps[in[i]]=i;
	
	}
	
	BSTNode<int,int>* root=insert(pre,6,0);
	pre_order(root);
	return 0;
} 
