#include<iostream>
using namespace std;

int a[1000][1000];

void matrix(int n){
	
	int m=1;
	
	for(int i=0;i<(n+1)/2;i++){
		
		
		int x=i;
		int y=i;
		
		for(;y<(n-i);y++){
			a[x][y]=m++; 
		//	cout<<x<<y<<" "<<m-1<<endl;
			if(m>n*n)
			 break;
		}
		y--;
		x+=1;
		for(;x<(n-i);x++){
			a[x][y]=m++;
			if(m>n*n)
			 break;
		}
		x--;
		y--;
		for(;y>=i;y--){
			a[x][y]=m++;
			if(m>n*n)
			 break;
		}
		y++;
		x--;
		for(;x>i;x--){
			a[x][y]=m++;
			if(m>n*n)
			 break;
		}
	}
}


int main(){
	int n=9;
	matrix(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
