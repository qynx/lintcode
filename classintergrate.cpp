#include<iostream>
using namespace std;

class A{
	private:
		int x,y;
	protected:
		int z;
	public:
		A(int a,int b,int c){
			x=a;
			y=b;
			z=c;
		}
		
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		int getZ(){
			return z;
		}
};

class B:public A{
	
	private:
		int k;
	public:
		B(int a,int b,int c,int d):A(a,b,c){
			k=d;
		}
		
		int now(){
			cout<<getX()<<" "<<getY()<<" "<<z<<" "<<k<<endl; 
		}
};
int main(){
	
	B b=B(1,2,3,4);
	b.now();
} 
