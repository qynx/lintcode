#include<iostream>
#include<vector>
using namespace std;
/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).

Here is an example:
S ="rabbbit", T ="rabbit"

Return3.


*/ 
/*int numDistinct(string S, string T) {
		if(S.length()==0)
			return 0;
		if(S.length()==T.length())
			return 1;
		
		int a[S.length()];
		int len=S.length();
		for(int i=0;i<len;i++){
			
			for(int j=0;j<T.length();j++){
				if(S[i]==T[j]&&(j+1<length())){
					int count=0;
					for(int k=i+1;k<len;k++)
						if(S[k]==T[j+1]){
							count++;
						}
					a[i]=count;
				}
			}
			
			
		}
		
			        
}*/
int numDistinct(string S, string T) {
    int len=T.size();
    vector<int> array(len+1);
    array[0]=1;
    for(int i=1;i<S.size()+1;i++){
    
        for(int j=min(i,len);j>0;j--){
            if(S[i-1]==T[j-1])
                array[j]=array[j]+array[j-1];
        }
    }
    return array[len];
    }

int main(){
	
	cout<<numDistinct("abcabc","abc");
}
