#include<iostream>
using namespace std;

int singleNumber(int A[], int n) {
	
	int result=0;
	for(int i=0;i<n;i++){
		result=result^A[i];
	}        
	return result;
}
int main(){
	
	int a[15]={2,2,-1,-1,3};
	cout<<singleNumber(a,5);
}
