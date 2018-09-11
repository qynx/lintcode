#include<iostream>
#include<cstdlib>
using namespace std;
 
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

 RandomListNode* Clone(RandomListNode* pHead)
    {   
        if(!pHead)
            return pHead;
        RandomListNode* p=pHead;
        RandomListNode* q;
        cout<<"hh"<<endl;
        while(p){
           q=new RandomListNode(p->label);
           cout<<p->label<<endl;
           q->next=p->next;
           p->next=q;
           p=q->next;
        }
        cout<<"¸´ÖÆ"<<" ";
        p=pHead;
        q=p->next;
        while(q){
            //q=p->next;
            if(p->random)
            q->random=new RandomListNode(p->random->label);
            p=q->next;
            if(p){
            q->next=p->next;
            q=p->next;}
            else
                break;
        }
        q=pHead->next;
        return q;
    }

void construct(RandomListNode* root,int *a,int len){
	root->label=a[0];
	root->next=root->random=NULL;
	RandomListNode*temp=root;
	for(int i=1;i<len;i++){
		temp->next=new RandomListNode(a[i]);
		temp=temp->next;
	}
} 
void print(RandomListNode* root){
	int a;
	while(root){
		cout<<root->label<<" ";
		//cin>>a;
		root=root->next;
	}
}
int main(){
	int a[5]={1,2,3,4,5};
	RandomListNode* root=(RandomListNode* )malloc(sizeof(RandomListNode*)); 
//	cout<<"6 "<<root->label;
	
	construct(root,a,5);
	print(root);
	RandomListNode* clone=Clone(root);
	print(clone);
	
}
