#include<iostream>
using  namespace std;

bool notAlpha(char c){
	//printf("%d\n",c);
//	cout<<(64<c)<<" "<<(96<c)<<endl;
        if((64<c&&c<91)||(96<c&&c<123)||(c>47&&c<58))
            return false;
        return true;
    }
    bool isPalindrome(string s) {
        if(s.length()==0)
            return true;
        if(s.length()==1)
            return true;
        int p=-1;
        int q=s.length();
        
       
        while(p<q){
           while(notAlpha(s[++p]));
           while(notAlpha(s[--q]));
          	//cout<<p<<" "<<q<<endl;
 			if(p>=q)
			 	return true;       
           if(s[p]!=s[q] && s[p]-s[q]!=32 && s[q]-s[p]!=32)
               return false;
        }
        return true;
    }

int main(){
	//cout<<notAlpha('.')<<endl;
	cout<<isPalindrome("'''''")<<endl;
}
