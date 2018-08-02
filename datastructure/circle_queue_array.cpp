#include<iostream>
#define defaultSize 10
template<typename E> class Queue{
	
	private:
		int maxSize;
		int front;
		int rear;
		E* listArray;
	
	public:
		
		//constructor
		Queue(int size=defaultSize){
			
			maxSize=size+1;
			rear=size;
			front=0;
			listArray=new E[maxSize];
			
		}
		
		//Destructor
		~Queue(){
	
			delete [] listArray;
		}
		
		//Reinitialize
		void clear(){
			
			front=0;rear=maxSize-1;

		}
		
		//put "it" in queue
		void enqueue(const E&it){
			
			if((rear+2)%maxSize == front){
				//队列已满 
				return -1;
			}
			
			rear=(rear+1)%maxSize;
			listArray[rear]=it;
			
		}
		
		//take element out
		E dequeue(){
			if((rear+1)%maxSize==front){
				//队列为空 
				return -1; //?
			
			E it=listArray[front];
			front=(front+1)%maxSize;
			return it; 
		}
	}
		const E& frontValue() const{
			
			if(length()==0){
				return -1;
			}
			
			
		}
		
		//return the length of the queue
		int length() const{
		
		return ((rear+maxSize)-front+1)%maxSize;
		}
};

int main(){
return 0; 
}
