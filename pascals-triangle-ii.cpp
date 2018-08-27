#include<iostream>
#include<vector>
using namespace std;

 vector<int> getRow(int rowIndex) {
       vector<int>result=vector<int>(rowIndex+1,0);
       //result[0]=1;
       for(int i=1;i<=rowIndex;i++){
       		result[0]=1;
           for(int j=i;j>=1;j--){
               result[j]=result[j]+result[j-1];
           }
       }
        
       return result;
    }
    
int main(){
	
	vector<int>a =getRow(3);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
}
