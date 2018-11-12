#include<iostream>
using namespace std;
#define result "UNKNOWN"
long a1,b1,v1,a2,b2,v2;
	
int main(){
	
	int t;
	cin>>t;
	

	while(t--){
		
		cin>>a1>>b1>>v1>>a2>>b2>>v2;
		//int x=0;
		//int y=0;
		
		int count=0;
		int tempx,tempy;
		
		int maxx,maxy;
		maxx=1,maxy=1;
		for(int x=1;a1*x<v1&&a2*x<v2;x++){
		
			for(int y=1;(a1*x+b1*y)<=v1&&(a2*x+b2*y)<=v2;y++){
				//cout<<(a1*x+b1*y)<<" "<<x<<" "<<y<<endl;
				/*if(((a2-a1)*x+(b2-b1)*y)==v2-v1){
					cout<<x<<" "<<y<<endl;
					count++;
					tempx=x;
					tempy=y;
				}*/
				if()
			}
		}
		
		if(count==1){
			cout<<tempx<<" "<<tempy<<endl;
		}else{
			cout<<result<<endl;
		}
	}
}
