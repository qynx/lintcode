/*
ÌâÄ¿ÃèÊö

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 ="aabcc",
s2 ="dbbca",

When s3 ="aadbbcbcac", return true.
When s3 ="aadbbbaccc", return false.


*/

//self 
class Solution {
public:
    string s1c,s2c,s3c;
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=(s1.length()+s2.length())) return false;
        /*
        for(i;i<s3.length();i++){
            if(s3[i]==s1[i1])
                i1++;
            else if(s3[i]==s2[i2])
                i2++;
            else
                return false;
        }
        
        return true;*/
        s1c=s1,s2c=s2,s3c=s3;
        int i1=0,i2=0;
        int i=0;
        return ishehe(i1,i2,i);
    }
    
    bool ishehe(int i1,int i2,int i){
        if(i>=s3c.length()) return true;
        if(s3c[i]==s1c[i1]&&s3c[i]==s2c[i2]){
            return ishehe(i1+1,i2,i+1)||ishehe(i1,i2+1,i+1);
        }else if(s3c[i]==s1c[i1])
               return ishehe(i1+1,i2,i+1);
        else if(s3c[i]==s2c[i2])
            return ishehe(i1,i2+1,i+1);
        else 
            return false;
    }
};
#include<iostream>
using namespace std;

int main(){
	
}
