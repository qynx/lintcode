#include<iostream>
#include<cstdlib>
#include<vector>
#define defaultsize 30

using namespace std;

template <typename E> class Stack{
	private:
		void operator =(const Stack&) {}
		Stack(const Stack&) {}
	
	public:
		Stack() {}
		virtual ~Stack(){}
		
		//reinitailize the stack
		//the user is responsible for 
		//reclaiming the storage used 
		//by the stack elements
		virtual void clear()=0;
		
		virtual void push(const E&it)=0;
		
		//virtual E pop()=0;
		virtual void pop()=0;
		
		virtual const E& topValue() const=0;
		
		virtual int length() const=0;						 				
};

template <typename E> class stack:public Stack<E>{
	private:
		int maxSize;
		int top;
		E * listArray;
	
	public:
		
		stack(int size=defaultsize){
			
			maxSize=size;
			top=0;
			listArray=new E[size];
		
		}
		
		~stack(){
			
			delete [] listArray;
		
		}
		
		void clear(){
			
			top=0;
		} 
		
		void push(const E&it){
			
		//	Assert(top!=maxSize,"Stack is full");
			listArray[top++]=it;
		}
		
		void pop(){
			
		//	Assert(top!=0,"Stack is empty");
			//return listArray[--top];
			top--;
		} 
		
		const E& topValue() const{
			
	//		Assert(top!=0,"Stack is empty");
			return listArray[top-1];
		}
		
		int length() const{ return top; }
}; 


//栈 结点 实现
//用这种结点怎么实现栈中元素的插入：
//栈中初始化一个top结点，下一个为空
// 
template <typename E> class Link{
	public:
		E element;
		Link* next;
		
		Link(const E& elemval,Link* nextele=NULL){
			
			element=elemval;
			next=nextele;
		}
		
		Link(Link* nextele=NULL){
			
			next=nextele;
		}
}; 

//C++ delete 操作符删除指针指向的内存
//并不释放指针本身 
template<typename E> class LStack: public Stack<E>{
	
	private:
		Link<E> *top;
		int size;
	
	public:
		
		LStack(int sz=defaultsize){
			
			top=NULL;
			size=0;
		}
		
		~LStack() {
			
			clear();
			
		}
		
		void clear(){
			
			while(top!=NULL){
				
				Link<E>* temp=top;
				top=top->next;
				delete temp;
				
			}
			size=0;
		}
		
		void push(const E& it){
			
			top=new Link<E>(it,top);
			size++;
		}
		
		void pop(){
			
			if(size>0){
				E it =top->element;
				
				Link<E>* ltemp=top;
			//	printf("This value should not change %p\n",ltemp);
				top=top->next;
			//	printf("This value should not change %p\n",ltemp);
				delete ltemp;
				
				size--;
				
				cout<<it<<endl;
			}
		}
		
		const E& topValue() const{
			
			if(size>0){
				return top->element;
			}
		}
		
		int length() const {
			return size; 
		}
		
};
class Solution{
	public:
		int evalRPN(vector<string> &tokens) {
        	stack<int>ss;
        	string op="+-*/";
        	int isop;
			for(int i=0;i<tokens.size();i++){
        	//	cout<<tokens[i]<<endl;
				isop=op.find(tokens[i]);
        		int result;
                
        		if(isop==-1)
        			ss.push(atoi(tokens[i].c_str()));
        		
        		else{
        			string temp_op=tokens[i];
        			
					int number_right=ss.topValue();
                    ss.pop();
                    int number_left=ss.topValue();
                    ss.pop();
                    
					switch(isop){
						
						case 0:
							result=number_left+number_right;
							break;
							
						case 1:
							result=number_left-number_right;
							break;
						
						case 2:	
							result=number_left*number_right;
							break;
						
						case 3:
							result=number_left/number_right;
							break;
						
						default:
							result=-1;
							break;
					
					}
					
					ss.push(result);
										        			
				}				
        		
			}
			
			int final_result=ss.topValue();
			
       		return final_result;
    }
};

int main(){
	
	/*	Solution s=Solution();
	
	vector<string>token;
	
	string test1[]={"2", "1", "+", "3", "*"};
	string test2[]={"4", "13", "5", "/", "+"};
	
//	cout<<sizeof(test1)<<endl;
	for(int i=0;i<5;i++){
			
		token.push_back(test1[i]);
	//	cout<<test1[i]<<endl;
	}
	
	int result;
	//	cout<<"ca"<<endl;
	result=s.evalRPN(token);
	//	cout<<"ca"<<endl;
	cout<<result<<endl;*/
	
	Link<int>a(10);

	printf("%p\n",a); 
	
//	int b=0;
//	printf("%p\n",&b);
//	int*p=&b;
//	printf("%p\n",&p);
//	int c=0;
//	printf("%p\n",&c);
	LStack<int> l(10);
	
	l.push(3);
	l.push(4);
	l.push(5);
	l.pop();
	l.pop();
	cout<<l.topValue()<<endl;
	return 0;
	
}
