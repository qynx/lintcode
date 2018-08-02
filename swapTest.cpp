#include<iostream>
using namespace std;

void swap(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}

int main(){
	
	int b[2]={0,1};
	swap(b[0],b[1]);
	
	cout<<b[0]<<" "<<b[1]<<endl;
	
	cout<<("abc"<"bcd");
}
