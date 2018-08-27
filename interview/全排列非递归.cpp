#include<iostream>
#include<vector>
using namespace std;
vector<int>result;

//functions
void print(vector<int>&a);
void swap(vector<int>&a,int i,int j);
void reverse(vector<int>&a,int i,int j);

void swap(vector<int>&a,int i,int j){
	a[i]^=a[j];
	a[j]^=a[i];
	a[i]^=a[j];
}

void inSort(vector<int>::iterator begins,vector<int>::iterator ends,int span,int size){
	for(int i=span;i<size;i+=span){
		for(int j=i;j>=span;j-=span){
			if(*(begins+j)<*(begins+j-1)){
				int temp=*(begins+j);
				*(begins+j)=*(begins+j-1);
				*(begins+j-1)=temp; 
			}
		}
	}
}
void shellSort(vector<int>&a){
	int len=a.size();
	vector<int>::iterator en=a.end();
	for(int i=len/2;i>=2;i/=2){
		for(int j=0;j<i;j++){
			vector<int>::iterator it=a.begin()+j;
			inSort(it,en,i,len);
		}
	} 
	inSort(a.begin(),en,1,len);
}

void reverse(vector<int>&a,int i,int j){
	
	for(i,j;i<j;i++,j--){
		swap(a,i,j);
	}
}
void quanpai(vector<int>&a){
	
	if(a.size()<2) {
		print(a);
		return;
	}
	//从小到大排序 
	shellSort(a);
	bool end=false;
	while(true){
		print(a);
		
		int i,j;
		
		for(i=a.size()-2;i>=0;i--){
			if(a[i]<a[i+1]) break;
			else if(i==0) return;
		}
	//	cout<<"第一个for"<<endl;
		for(j=a.size()-1;j>i;j--){
			if(a[j]>a[i])  break;
 		}
 		
 		swap(a,i,j);
		reverse(a,i+1,a.size()-1); 		
 	//	cout<<"一次while循环"<<endl;
	}

} 

void print(vector<int>&a){
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<"  ";
	 cout<<endl;
}
int main(){
	
	vector<int>a;
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	//quanpai(a,0,a.size()-1);
	//shellSort(a);
	//print(a);
	quanpai(a);
} 
