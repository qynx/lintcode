#include<iostream>
#include<malloc.h>
using namespace std;
/*A linked list is given such that each node contains an additional 
random pointer which could point to any node in the list or null.

Return a deep copy of the list.*/

struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	//RandomListNode* old2new[][2];
	RandomListNode* copyaNode(RandomListNode *node){
		RandomListNode* newnode=&(RandomListNode(node->label)); 
		return newnode;
		
	}
	
    RandomListNode *copyRandomList(RandomListNode *head) {
    	
		RandomListNode*move=head;
		RandomListNode*newhead;
		newhead=copyNode(move);
		RandomListNode*newmove=newhead;
		
		int count=0;
		
		while(move!=NULL){
			
			newmove->next=copyaNode(move->next);
			newmove=newmove->next;
			move=move->next;		
			count++;
		}	
    	//当前 random指针都是空的 next label已经完善 
		
		
    	
    }
};

int main(){
	
	return 0;
}
