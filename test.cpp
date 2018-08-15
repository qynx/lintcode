#include<iostream>
#include<cstdlib>
#include<malloc.h>
#include<vector>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node(int x):val(x),next(NULL){}
	
};
int main(){
	/*string s="dsad";
	cout<<s.find("l")<<endl;
	int n=s.find("l");
	cout<<n<<endl;
	
	long int x=0;
	unsigned int y=0xffffffff;
	cout<<y<<endl; 
	x=x^y;
	
	cout<<x<<endl; */
	//cout<<(float)5/2<<endl;
	//bool b=((float)5/0)==((float)4/0);
	//cout<<b<<endl;
	//cout<<atoi('0')<<endl;
//	Node *start;
//start=(Node*)malloc(sizeof(struct Node));
//	start->next=NULL;
	//cout<<start->val<<endl;
	//Node *temp=(Node*)malloc(sizeof(Node));
	//vector<int>c;
	//cout<<c.size();
//	temp=start->next;

  /* 2018-07-21 21:59 home  for copy_list_with_random_pointer from linstcode niuke*/
  	//int a[][2];
  	//a[0][1]=1;
  	int *a;
  	a=NULL;
  	int b=1;
  	a=&b;
  /*************************************************************/ 
  
  /* 2018-08-13 13:13 
  vector<int>s;
  s.push_back(1);
  s.push_back(2);
  
  vector<int>::iterator iter=s.begin();
  
  while(iter!=s.end()){
  	cout<<*iter;
  	iter++;
  }
  /* */
  
  /* 2018 8 15 11:08
  cout<<(-2)%5<<endl;
  cout<<'A'-'0'<<endl;
  printf("%d\n",'A');
  printf("%d\n",'Z');
  printf("%d\n",'a');
  printf("%d\n",'z');
   */
   
   /* 2018 8 15 13:40
   */cout<<(4<3<1)<<endl; 
   printf("%d\n",'0');
   printf("%d\n",'9');
}
