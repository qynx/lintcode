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
  	//int *a;
  //	a=NULL;
  	//int b=1;
  	//a=&b;
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
   cout<<(4<3<1)<<endl; 
   printf("%d\n",'0');
   printf("%d\n",'9');*/

	//2018 8 28
/*	vector<int>a=vector<int>(4,1);
	a.insert(a.end(),10);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<a.size()/2;*/ 
	/*
	string s="abcd";
	int a=s.find("b",2);
	cout<<a<<endl;*/
	//char *tt=(char*)malloc(4*sizeof(char));
	//cout<<aiot(1);
	/*string a="1234";
	cout<<stoi(a);
	cout<<to_string(1);
	auto b=a;*/
	
	/*
	char* string1="tencent2018";
	cout<<sizeof(string1)<<endl;
	cout<<sizeof(*string1)<<endl;
	cout<<sizeof("tencent2018")<<endl;
	char string2[100]="tencent2018";
	cout<<sizeof(string2)<<endl;*/ 
	
/*
    int m []={1,2,3,4,5,6,7,8,9,0};
    int(*p)[4]=(int(*)[4])m;
    cout<<p[1][2];
    return 0;*/
    char str[] = "";
    cout<<sizeof(str);

}
