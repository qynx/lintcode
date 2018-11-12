#include "header.h"
//using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	int count=0;
	
	while(1){
		if((n=n&(n-1))!=0){
			count++;
			n=n-1;
		}	
		else{
			break;
		}
	}
	
	cout<<count<<endl;
} 
