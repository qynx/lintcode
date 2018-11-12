//https://www.nowcoder.com/question/next?pid=10611931&qid=161632&tid=18643189//
//³ÔÇÉ¿ËÁ¦ 
#include<iostream>
using namespace std;
double mi(double n,int m){
    double temp=n;
    while(--m){
        n*=temp;
    }
    return n;
}
double dengbihe(int n,int m){
    return 2.0*n*(1.0-mi(0.5,m));
}

bool cheng(int i,int n){
	int r=1;
	while(--n){
		r*=2;
		if(r>i)
			return false;
	}
	return true;
}
int main(){
    
    int n,m;
    cin>>n>>m;
    cout<<cheng(40,58)<<endl;
    for(int i=m;i>=2;i--){
    	if(cheng(n)<m){
		
        if(dengbihe(i,n)<=m){
            cout<<i;
            break;
        }
        
    	}
    }
    
}
