#include<iostream>
using namespace std;
/*
Given an array of integers,
 every element appears three times except for one.
  Find that single one.
*/

int singleNumber(int A[], int n) {
        
        int bits[32]={0};
        int temp;
        
        for(int i=0;i<n;i++){
            temp=A[i];
            
            for(int j=0;j<32;j++){
            	bits[j]+=(((0x01<<j)&temp)>>j);
			}
        }
        
        int result=0;
        for(int i=0;i<32;i++){
            if(bits[i]%3!=0){
                result+=1<<i;
            }
        }
        
        return result;
    }

void qu(int temp){
for(int j=0;j<32;j++){
            	cout<< (((0x01<<j)&temp)>>j);
			}
}
int main(){
	//qu(-4);
	//return 0;
	int a[20]={-2,-2,1,1,-3,1,-3,-3,-4,-2};
	cout<<singleNumber(a,10);
}
