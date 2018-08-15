/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4]. Return its length:4.

Your algorithm should run in O(n) complexity.
*/ 
#include<iostream>
#include<vector>
using namespace std;
//排序 
// 两个元素相差 1  或者 -1   相等只算一个元素 
 int longestConsecutive(vector<int> &num) {
         int temp;
        int len=num.size(); 
        if(len==1)
               return 1;
        //排序 
        for(int i=0;i<len;i++)
        	for(int j=i+1;j<len;j++){
        		if(num[j]<num[i]){
        			temp=num[j];
        			num[j]=num[i];
        			num[i]=temp;
				}
			}
	 //寻找最大长度
	 int maxL=0;
   temp=1;
	 for(int i=1;i<len;i++){
	 	if((num[i]==(num[i-1]+1))){
	 		temp+=1;
		}else if(num[i]!=num[i-1]){
			temp=1;
		}
	 	maxL=maxL>temp?maxL:temp;
	 }
	 
	 return maxL; 
    }


int main(){
	
}
